#pragma once


#include <graphics.h>

#include "animation.h"
#include "vector2.h"
#include "camera.h"
#include "player_id.h"
#include "platform.h"
#include "bullet.h"
#include "particle.h"


extern std::vector<Platform> platform_list;
extern std::vector<Bullet*> bullet_list;

extern bool is_debug;

extern IMAGE img_1P_cursor;								// 1P ָʾ���ͼƬ
extern IMAGE img_2P_cursor;								// 2P ָʾ���ͼƬ

extern Atlas atlas_run_effect;							// ������Ч����ͼ��
extern Atlas atlas_jump_effect;							// ��Ծ��Ч����ͼ��
extern Atlas atlas_land_effect;							// �����Ч����ͼ��

class Player {
public:
	Player(bool facing_left = false) : is_facing_left(facing_left) {
		current_animation = is_facing_left ? &anim_idle_left : &anim_idle_right;

		timer_attack_cd.SetWaitTime(attack_cd);
		timer_attack_cd.SetOneShot(true);
		timer_attack_cd.SetCallback([&]()
			{
				can_attack = true;
			});

		timer_invulnerable.SetWaitTime(750);
		timer_invulnerable.SetOneShot(true);
		timer_invulnerable.SetCallback([&]()
			{
				is_invulnerable = false;
			});

		timer_invulnerable_blink.SetWaitTime(75);
		timer_invulnerable_blink.SetCallback([&]()
			{
				is_showing_sketch_frame = !is_showing_sketch_frame;
			});

		timer_run_effect_generation.SetWaitTime(75);
		timer_run_effect_generation.SetCallback([&]()
			{
				Vector2 particle_position;
				IMAGE* frame = atlas_run_effect.GetImage(0);
				particle_position.x = position.x + (size.x - frame->getwidth()) / 2;
				particle_position.y = position.y + size.y - frame->getheight();
				particle_list.emplace_back(particle_position, &atlas_run_effect, 45);
			});

		timer_die_effect_generation.SetWaitTime(35);
		timer_die_effect_generation.SetCallback([&]()
			{
				Vector2 particle_position;
				IMAGE* frame = atlas_run_effect.GetImage(0);
				particle_position.x = position.x + (size.x - frame->getwidth()) / 2;
				particle_position.y = position.y + size.y - frame->getheight();
				particle_list.emplace_back(particle_position, &atlas_run_effect, 150);
			});

		anim_jump_effect.SetAtlas(&atlas_jump_effect);
		anim_jump_effect.SetInterval(25);
		anim_jump_effect.SetLoop(false);
		anim_jump_effect.SetCallback([&]()
			{
				is_jump_effect_visiable = false;
			});

		anim_land_effect.SetAtlas(&atlas_land_effect);
		anim_land_effect.SetInterval(50);
		anim_land_effect.SetLoop(false);
		anim_land_effect.SetCallback([&]()
			{
				is_land_effect_visiable = false;
			});

		timer_cursor_visibility.SetWaitTime(2500);
		timer_cursor_visibility.SetOneShot(true);
		timer_cursor_visibility.SetCallback([&]()
			{
				is_cursor_visible = false;
			});
	}

	~Player() = default;

	virtual void OnUpdate(int delta) {
		int direction = is_right_key_down - is_left_key_down;

		if (direction != 0) {
			if (!is_attacking_ex)
				is_facing_left = direction < 0;
			current_animation = is_facing_left ? &anim_run_left : &anim_run_right;
			float distance = run_velocity * direction * delta;
			OnRun(distance);
		}
		else {
			current_animation = is_facing_left ? &anim_idle_left : &anim_idle_right;
			timer_run_effect_generation.Pause();
		}

		if (is_attacking_ex)
			current_animation = is_facing_left ? &anim_attack_ex_left : &anim_attack_ex_right;
		if (hp < 0)
			current_animation = last_hurt_direction.x < 0 ? &anim_die_left : &anim_die_right;

		current_animation->OnUpdate(delta);
		anim_jump_effect.OnUpdate(delta);
		anim_land_effect.OnUpdate(delta);

		timer_attack_cd.OnUpdate(delta);
		timer_invulnerable.OnUpdate(delta);
		timer_invulnerable_blink.OnUpdate(delta);
		timer_run_effect_generation.OnUpdate(delta);
		timer_cursor_visibility.OnUpdate(delta);

		if (hp <= 0)
			timer_die_effect_generation.OnUpdate(delta);

		particle_list.erase(std::remove_if(
			particle_list.begin(), particle_list.end(),
			[](const Particle& particle)
			{
				return !particle.CheckValid();
			}),
			particle_list.end());
		for (Particle& particle : particle_list)
			particle.OnUpdate(delta);

		if (is_showing_sketch_frame)
			SketchImage(current_animation->GetIndexImage(), &img_sketch);

		MoveAndCollide(delta);
	}

	virtual void OnDraw(const Camera& camera) {
		if (is_jump_effect_visiable)
			anim_jump_effect.OnDraw(camera, (int)position_jump_effect.x, (int)position_jump_effect.y);
		if (is_land_effect_visiable)
			anim_land_effect.OnDraw(camera, (int)position_land_effect.x, (int)position_land_effect.y);

		for (Particle& particle : particle_list)
			particle.OnDraw(camera);

		if (hp > 0 && is_invulnerable && is_showing_sketch_frame)
			putimage_alpha((int)position.x, (int)position.y, &img_sketch);
		else
			current_animation->OnDraw(camera, (int)position.x, (int)position.y);

		if (is_cursor_visible) {
			switch (id) {
			case PlayerID::P1:
				putimage_alpha(camera, (int)(position.x + (size.x - img_1P_cursor.getwidth()) / 2),
					(int)(position.y - img_1P_cursor.getheight()), &img_1P_cursor);
				break;
			case PlayerID::P2:
				putimage_alpha(camera, (int)(position.x + (size.x - img_2P_cursor.getwidth()) / 2),
					(int)(position.y - img_2P_cursor.getheight()), &img_2P_cursor);
				break;
			}
		}

		if (is_debug) {
			setlinecolor(RGB(0, 125, 255));
			rectangle((int)position.x, (int)position.y, (int)(position.x + size.x), (int)(position.y + size.y));
		}
	}

	virtual void OnInput(const ExMessage& msg) {
		switch (msg.message) {
		case WM_KEYDOWN:
			switch (id) {
			case PlayerID::P1:
				switch (msg.vkcode) {
					// 'A'
				case 0x41:
					is_left_key_down = true;
					break;
					// 'D'
				case 0x44:
					is_right_key_down = true;
					break;
					// 'W'
				case 0x57:
					OnJump();
					break;
					// 'F'
				case 0x46:
					if (can_attack) {
						can_attack = false;
						OnAttack();
						timer_attack_cd.Restart();
					}
					break;
					// 'G'
				case 0x47:
					if (mp >= 100) {
						mp = 0;
						OnAttackEx();
					}
					break;
				}
				break;
			case PlayerID::P2:
				switch (msg.vkcode) {
					// '<-'
				case VK_LEFT:
					is_left_key_down = true;
					break;
					// '->'
				case VK_RIGHT:
					is_right_key_down = true;
					break;
					// '^'
				case VK_UP:
					OnJump();
					break;
					// '.'
				case VK_OEM_PERIOD:
					if (can_attack) {
						can_attack = false;
						OnAttack();
						timer_attack_cd.Restart();
					}
					break;
					// '/'
				case VK_OEM_2:
					if (mp >= 100) {
						mp = 0;
						OnAttackEx();
					}
					break;
				}
				break;
			}
			break;
		case WM_KEYUP:
			switch (id) {
			case PlayerID::P1:
				switch (msg.vkcode) {
					// 'A'
				case 0x41:
					is_left_key_down = false;
					break;
					// 'D'
				case 0x44:
					is_right_key_down = false;
					break;
				}
				break;
			case PlayerID::P2:
				switch (msg.vkcode) {
					// '<-'
				case VK_LEFT:
					is_left_key_down = false;
					break;
					// '->'
				case VK_RIGHT:
					is_right_key_down = false;
					break;
				}
				break;
			}
			break;
		default:
			break;
		}
	}

	virtual void OnRun(float distance) {
		if (is_attacking_ex)
			return;

		position.x += distance;
		timer_run_effect_generation.Resume();
	}

	virtual void OnJump() {
		if (velocity.y != 0 || is_attacking_ex)
			return;

		velocity.y += jump_velocity;

		is_jump_effect_visiable = true;
		anim_jump_effect.Reset();

		IMAGE* effect_frame = anim_jump_effect.GetIndexImage();
		position_jump_effect.x = position.x + (size.x - effect_frame->getwidth()) / 2;
		position_jump_effect.y = position.y + size.y - effect_frame->getheight();
	}

	virtual void OnLand() {
		is_land_effect_visiable = true;
		anim_land_effect.Reset();

		IMAGE* effect_frame = anim_land_effect.GetIndexImage();
		position_land_effect.x = position.x + (size.x - effect_frame->getwidth()) / 2;
		position_land_effect.y = position.y + size.y - effect_frame->getheight();
	}

	void SetID(PlayerID id) {
		this->id = id;
	}

	void SetPosition(float x, float y) {
		position.x = x;
		position.y = y;
	}

	const Vector2& GetPosition() const {
		return position;
	}

	const Vector2& GetSize() const {
		return size;
	}

	virtual void OnAttack() {}
	virtual void OnAttackEx() {}

	virtual bool GetIsAttackingEx() {
		return is_attacking_ex;
	}

	void MakeInvulnerable() {
		is_invulnerable = true;
		timer_invulnerable.Restart();
	}

	void SetHp(int val) {
		hp = val;
	}

	int GetHp() const {
		return hp;
	}

	int GetMp() const {
		return mp;
	}

protected:
	void MoveAndCollide(int delta) {
		float last_velocity_y = velocity.y;

		velocity.y += gravity * delta;
		position += velocity * (float)delta;

		if (hp <= 0)
			return;

		if (velocity.y > 0) {
			for (const Platform& platform : platform_list) {
				const Platform::CollisionShape shape = platform.shape;
				bool is_collide_x = (max(position.x + size.x, shape.right) - min(position.x, shape.left))
					<= size.x + (shape.right - shape.left);  // �жϽ�ɫ��ƽ̨�����������ֵ���Ƿ�С�ڶ��߿��֮��
				bool is_collide_y = (shape.y >= position.y && shape.y <= position.y + size.y);

				if (is_collide_x && is_collide_y) {
					float delta_pos_y = velocity.y * delta;
					float last_tick_foot_pos_y = position.y + size.y - delta_pos_y;
					if (last_tick_foot_pos_y <= shape.y) {
						position.y = shape.y - size.y;
						velocity.y = 0;

						if (last_velocity_y != 0)
							OnLand();

						break;
					}
				}
			}
		}

		if (!is_invulnerable) {
			for (Bullet* bullet : bullet_list) {
				if (!bullet->GetValid() || bullet->GetCollideTarget() != id)
					continue;

				if (bullet->CheckCollision(position, size)) {
					MakeInvulnerable();
					bullet->OnCollide();
					bullet->SetValid(false);
					hp -= bullet->GetDamage();
					last_hurt_direction = bullet->GetPosition() - position;
					if (hp <= 0) {
						velocity.x = last_hurt_direction.x < 0 ? -0.35f : 0.35f;
						velocity.y = -1.0f;
					}
				}
			}
		}
	}

protected:
	const float gravity = 1.6e-3f;			// �������
	const float	run_velocity = 0.55f;		// �ܶ��ٶ�
	const float jump_velocity = -0.85f;		// �����ٶ�

protected:
	int mp = 0;								// ��ɫ����
	int hp = 100;							// ��ɫ����ֵ

	Vector2 size;							// ��ɫ�ߴ�
	Vector2 position;						// ��ɫλ��
	Vector2 velocity;						// ��ɫ�ٶ�

	Animation anim_idle_left;				// �������Ĭ�϶���
	Animation anim_idle_right;				// �����ҵ�Ĭ�϶���
	Animation anim_run_left;				// ������ı��ܶ���
	Animation anim_run_right;				// �����ҵı��ܶ���
	Animation anim_attack_ex_left;			// ����������⹥������
	Animation anim_attack_ex_right;			// �����ҵ����⹥������
	Animation anim_jump_effect;				// ��Ծ������Ч
	Animation anim_land_effect;				// ��ض�����Ч
	Animation anim_die_left;				// ���������������
	Animation anim_die_right;				// �����ҵ���������

	bool is_jump_effect_visiable = false;	// ��Ծ�����Ƿ�ɼ�
	bool is_land_effect_visiable = false;	// ��ض����Ƿ�ɼ�

	Vector2 position_jump_effect;			// ��Ծ��������λ��
	Vector2 position_land_effect;			// ��ض�������λ��

	Animation* current_animation = nullptr;	// ��ǰ���ڲ��ŵĶ���

	PlayerID id = PlayerID::P1;				// ������к�

	bool is_left_key_down = false;			// ����İ����Ƿ񱻰���
	bool is_right_key_down = false;			// ���ҵİ����Ƿ񱻰���

	bool is_facing_left = false;			// �Ƿ��������

	int attack_cd = 500;					// ��ͨ������ȴʱ��
	bool can_attack = true;					// �Ƿ�����ͷ���ͨ����
	Timer timer_attack_cd;					// ��ͨ������ȴ��ʱ��

	bool is_attacking_ex = false;			// �Ƿ����ͷ����⹥��

	IMAGE img_sketch;						// ��Ӱ���ͼƬ
	bool is_invulnerable = false;			// ��ɫ�Ƿ����޵�֡
	bool is_showing_sketch_frame = false;	// ��ǰ֡�Ƿ�Ӧ����ʾ��Ӱ
	Timer timer_invulnerable;				// �޵�״̬��ʱ��
	Timer timer_invulnerable_blink;			// �޵�״̬��˸��ʱ��

	std::vector<Particle> particle_list;	// ���Ӷ����б�

	Timer timer_run_effect_generation;		// �ܶ�������Ч���䶨ʱ�� 
	Timer timer_die_effect_generation;		// ����������Ч���䶨ʱ��

	bool is_cursor_visible = true;			// ��ҹ��ָʾ���Ƿ���ʾ
	Timer timer_cursor_visibility;			// ��ҹ��ָʾ���ɼ��Զ�ʱ��

	Vector2 last_hurt_direction;			// ���һ���ܻ�����
};