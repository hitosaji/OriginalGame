#include "DxLib.h"
#include "obstacles.h"
#include "startsetting.h"
#include "BoxColider.h"

// Obstaclesのベクター
//std::vector<Obstacles> allObstacles;

//Obstaclesのコンストラクタ
Obstacles::Obstacles(int initialX, int initialY)
{
	// 画像の読み込み
	playerImg = LoadGraph("Picture/obstacles2.png");

	// 初期位置設定
	x = initialX;
	y = initialY;

	// 速度設定
	vx = -2;
	vy = 0;
}

//Obstaclesの初期化
void Obstacles::Init()
{
}

//Obstaclesの更新
void Obstacles::Update()
{
	//スタート時の更新
	startsetting.Update();

	//ゲーム開始時のチェック
	startsetting.isPlaying;

	//ゲーム開始時チェックの更新
		if (startsetting.isPlaying == TRUE)
		{
			y += vy;
			x += vx;
		}
}

//Obstaclesの描画
void Obstacles::Draw()
{
	//Obstaclesのサイズ
	float size =0.9f;      

	//Obstaclesの描画
	DrawRotaGraph3(x, y, 0, 0, size, size, 0, playerImg, TRUE,TRUE);
}