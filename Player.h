#pragma once
#include <Vector2.h>

class Player
{
private:
	static const int kBulletMaxCount = 20;

private:
	Vector2 m_pos;
	float m_speed = 0;
	float m_radius = 0;

	int m_bulletMaxCoolTime = 0;
	int m_bulletCoolTime = 0;
	class Bullet* m_bullets = nullptr;

public:
	Player();
	~Player();

	const Bullet* bullets() const { return m_bullets; }
	const int bulletCount() const { return kBulletMaxCount; }

	void Update(char* keys, char* preKeys);
	void Draw();
};

