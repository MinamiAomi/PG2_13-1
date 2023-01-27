#include "Player.h"
#include <Novice.h>
#include "Bullet.h"

Player::Player()
{
	m_pos = { 640.0f,360.0f };
	m_speed = 5.0f;
	m_radius = 20.0f;

	m_bulletMaxCoolTime = 10;
	m_bulletCoolTime = 0;
	
	m_bullets = new Bullet[kBulletMaxCount];
}

Player::~Player()
{
	delete[] m_bullets;
}

void Player::Update(char* keys, char* preKeys)
{
	if (m_bulletCoolTime > 0) {
		m_bulletCoolTime--;
	}

	if (keys[DIK_W] != 0) {
		m_pos.y += -m_speed;
	}
	if (keys[DIK_S] != 0) {
		m_pos.y += m_speed;
	}
	if (keys[DIK_A] != 0) {
		m_pos.x += -m_speed;
	}
	if (keys[DIK_D] != 0) {
		m_pos.x += m_speed;
	}

	if (m_bulletCoolTime == 0) {
		if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
			for (int i = 0; i < kBulletMaxCount; i++) {
				if (m_bullets[i].isActive() == false) {
					m_bullets[i].Shot(m_pos);
					m_bulletCoolTime = m_bulletMaxCoolTime;
					break;
				}
			}
		}
	}

	for (int i = 0; i < kBulletMaxCount; i++) {
		if (m_bullets[i].isActive() == true) {
			m_bullets[i].Update();
		}
	}

}

void Player::Draw()
{
	for (int i = 0; i < kBulletMaxCount; i++) {
		if (m_bullets[i].isActive() == true) {
			m_bullets[i].Draw();
		}
	}

	Novice::DrawEllipse((int)m_pos.x, (int)m_pos.y, (int)m_radius, (int)m_radius, 0.0f, GREEN, kFillModeSolid);
}
