#include "Enemy.h"
#include <Novice.h>

bool Enemy::s_isActive = false;

Enemy::Enemy()
{
	m_speed = 5.0f;
	m_radius = 10.0f;
}

void Enemy::Update()
{
	if (s_isActive == true) {
		m_pos.x += m_speed;

		if (m_pos.x - m_radius < 0.0f ||
			m_pos.x + m_radius > 1280.0f) {
			m_speed *= -1.0f;
		}
	}
}

void Enemy::Draw()
{
	if (s_isActive == true) {
		Novice::DrawEllipse((int)m_pos.x, (int)m_pos.y, (int)m_radius, (int)m_radius, 0.0f, RED, kFillModeSolid);
	}
}