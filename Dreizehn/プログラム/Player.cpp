#include "DxLib.h"
#include "player.h"
#include"startsetting.h"

//Playerのコンストラクタ
Player::Player()
{

//プレイヤー画像の読み込み
 playerImg = LoadGraph("Picture/Player.png");

}

//Playerの更新
void Player::Update()
{
	//スタート時の更新
    startsetting.Update();

	//ゲーム開始時のチェック   
    startsetting.isPlaying;

	//ゲーム開始時チェックの更新
    if (startsetting.isPlaying == TRUE)
    {
        if (CheckHitKey(KEY_INPUT_SPACE)) //キーの割り当て
        {
            vy -= 0.2f; // 上に加速（ロケット推進）
        }
        vy += 0.1f; // 重力

        y += vy; // 位置更新

        // 画面外に出ないように制限
        if (y < 0) // 上
        {
            y = 0;
            vy = 2;
        }

        if (y > 480 - 64) // 下
        {
            y = 480 - 64;
            if (vy > 0) vy = 0;
        }
        
    }
    else
    {
         y= startsetting.y;
            if (CheckHitKey(KEY_INPUT_SPACE)) //キーの割り当て
            {
                y -= 1.0f; // 上に加速（ロケット推進）
            }
        }
}

//Playerの描画
void Player::Draw()
{  
    int size = 64;      //プレイヤー画像の大きさ

    DrawExtendGraph( 100,(int)y,100 + size, (int)y + size, playerImg,TRUE );      //プレイヤー画像の描画
}                                                                             