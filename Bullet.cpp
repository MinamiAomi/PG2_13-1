#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet()
{
	m_isActive = false;
	m_pos = {};
	m_speed = 5.0f;
	m_radius = 7.0f;
}

void Bullet::Shot(const Vector2& pos)
{
	m_pos = pos;
	m_isActive = true;
}

void Bullet::Update()
{
	m_pos.y += -m_speed;

	if (m_pos.y - m_radius < 0.0f ||
		m_pos.y + m_radius > 1280.0f) {
		m_isActive = false;
	}
}

void Bullet::Draw()
{
	Novice::DrawEllipse((int)m_pos.x, (int)m_pos.y, (int)m_radius, (int)m_radius, 0.0f, WHITE, kFillModeSolid);
}
