#pragma once
#include <Vector2.h>

class Bullet
{
private:
	bool m_isActive = false;
	Vector2 m_pos = {};
	float m_speed = 0;
	float m_radius = 0;

public:
	Bullet();

	void pos(const Vector2& pos) { m_pos = pos; }
	const Vector2& pos() const { return m_pos; }
	float radius() const { return m_radius; }
	bool isActive() const { return m_isActive; }

	void Shot(const Vector2& pos);
	void Update();
	void Draw();
};

