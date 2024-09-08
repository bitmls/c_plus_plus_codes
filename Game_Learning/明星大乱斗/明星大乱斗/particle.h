#pragma once

#include "atlas.h"
#include "vector2.h"
#include "util.h"


class Particle {
public:
	Particle() = default;
	Particle(const Vector2& position, Atlas* atlas, int lifespan)
		: position(position), atlas(atlas), lifespan(lifespan) {}
	~Particle() = default;

	void SetAtlas(Atlas* new_atlas) {
		atlas = new_atlas;
	}

	void SetPosition(const Vector2 new_position) {
		position = new_position;
	}

	void SetLifespan(int ms) {
		lifespan = ms;
	}

	const bool CheckValid() const {
		return valid;
	}

	void OnUpdate(int delta) {
		timer += delta;
		if (timer >= lifespan) {
			timer = 0;
			idx_frame++;
			if (idx_frame >= atlas->GetSize() - 1) {
				idx_frame = atlas->GetSize() - 1;
				valid = false;
			}
		}
	}

	void OnDraw(const Camera& camera) const {
		putimage_alpha((int)position.x, (int)position.y, atlas->GetImage(idx_frame));
	}

private:
	int timer = 0;			// ���Ӷ������Ŷ�ʱ��
	int lifespan = 0;		// ��֡���Ӷ�������ʱ��
	int idx_frame = 0;		// ��ǰ���ڲ��ŵĶ���֡
	Vector2 position;		// ���ӵ���������λ��
	bool valid = true;		// ���Ӷ����Ƿ���Ч
	Atlas* atlas = nullptr;	// ���Ӷ�����ʹ�õ�ͼ��
};
