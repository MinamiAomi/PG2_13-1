#pragma once
#include <Vector2.h>


class Enemy
{
private:
	static bool s_isActive;

private:
	Vector2 m_pos = {};
	float m_speed = 0;
	float m_radius = 0;

public:
	static void isActive(bool isActive) { s_isActive = isActive; }

public:
	Enemy();

	void pos(const Vector2& pos) { m_pos = pos; }
	const Vector2& pos() const { return m_pos; }
	float radius() const { return m_radius; }

	void Update();
	void Draw();
};

