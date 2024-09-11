#pragma once


#include <functional>
#include <graphics.h>

#include "vector2.h"
#include "player_id.h"
#include "camera.h"
#include "atlas.h"

extern bool is_debug;

class Bullet {
public:
	Bullet() = default;
	~Bullet() = default;

	void SetPosition(float x, float y) {
		position.x = x;
		position.y = y;
	}

	const Vector2& GetPosition() const {
		return position;
	}

	void SetDamage(int val) {
		damage = val;
	}

	int GetDamage() {
		return damage;
	}

	const Vector2& GetSize() const {
		return size;
	}

	void SetVelocity(float x, float y) {
		velocity.x = x;
		velocity.y = y;
	}

	void SetCollideTarget(PlayerID target) {
		target_id = target;
	}

	PlayerID GetCollideTarget() const {
		return target_id;
	}

	void SetCallBack(std::function<void()> callback) {
		this->callback = callback;
	}

	void SetValid(bool flag) {
		valid = flag;
	}

	bool GetValid() const {
		return valid;
	}

	bool CheckCanRemove() const {
		return can_remove;
	}

	virtual	void OnCollide() {
		if (callback)
			callback();
	}

	virtual bool CheckCollision(const Vector2& position, const Vector2& size) {
		return this->position.x + this->size.x / 2 >= position.x &&
			this->position.x + this->size.x / 2 <= position.x + size.x &&
			this->position.y + this->size.y / 2 >= position.y &&
			this->position.y + this->size.y / 2 <= position.y + size.y;
	}

	virtual void OnUpdate(int delta) {

	}

	virtual void OnDraw(const Camera& camera) const {
		if (is_debug) {
			setlinecolor(RGB(255, 255, 255));
			setfillcolor(RGB(255, 255, 255));
			rectangle((int)position.x, (int)position.y, (int)(position.x + size.x), (int)(position.y + size.y));
			solidcircle((int)(position.x + size.x / 2), (int)(position.y + size.y / 2), 5);
		}
	}

protected:
	bool CheckIfExceedsScreen() {
		return (position.x + size.x <= 0 || position.x >= getwidth() ||
			position.y + size.y <= 0 || position.y >= getheight());
	}

protected:
	Vector2 size;						// �ӵ��ߴ�
	Vector2 position;					// �ӵ�λ��
	Vector2 velocity;					// �ӵ��ٶ�
	int damage = 10;					// �ӵ��˺�
	bool valid = true;					// �ӵ��Ƿ���Ч
	bool can_remove = false;			// �ӵ��Ƿ���Ա��Ƴ�
	std::function<void()> callback;		// �ӵ��ص�����
	PlayerID target_id = PlayerID::P1;	// �ӵ���ײĿ���ɫid
};