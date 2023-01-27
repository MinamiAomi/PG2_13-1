#include <Novice.h>
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"
const char kWindowTitle[] = "学籍番号";

bool HitCircleToCircle(const Vector2& p1, float r1, const Vector2& p2, float r2);

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player;
	Enemy* enemy1 = new Enemy;
	enemy1->pos({ 640,400 });
	Enemy* enemy2 = new Enemy;
	enemy2->pos({ 640,200 });
		
	Enemy::isActive(true);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		if (keys[DIK_R] != 0 && preKeys[DIK_R] == 0) {
			Enemy::isActive(true);
		}

		player->Update(keys, preKeys);
		enemy1->Update();
		enemy2->Update();

		

		for (int i = 0; i < player->bulletCount(); i++) {
			const Bullet& bullet = player->bullets()[i];
			if (HitCircleToCircle(enemy1->pos(), enemy1->radius(), bullet.pos(), bullet.radius()) ||
				HitCircleToCircle(enemy2->pos(), enemy2->radius(), bullet.pos(), bullet.radius())) {
				Enemy::isActive(false);
				break;
			}
		}



		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		player->Draw();
		enemy1->Draw();
		enemy2->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player;
	delete enemy1;
	delete enemy2;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

bool HitCircleToCircle(const Vector2& p1, float r1, const Vector2& p2, float r2)
{
	float dx = p1.x - p2.x;
	float dy = p1.y - p2.y;
	float dist = dx * dx + dy * dy;
	float r = r1 + r2;
	return dist <= r * r;
}
