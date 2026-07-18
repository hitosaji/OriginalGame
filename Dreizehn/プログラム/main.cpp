#include "DxLib.h"
#include "player.h"
#include"background.h"
#include <vector>
#include <string.h>
#include"BoxColider.h"
#include"Obstacles.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(TRUE);// ウィンドウモード
	SetGraphMode(640, 440, 32);  // 画面サイズの設定
    DxLib_Init();    // DxLib初期化 
	SetDrawScreen(DX_SCREEN_BACK);   // 裏画面を描画対象にする
	if (DxLib_Init() == -1) return -1;  // DxLib初期化に失敗した場合は-1を返す
 

    Player player;   // Playerクラス

	Background background;   // Backgroundクラス
	background.Init();   // Backgroundの初期化

    std::vector<Obstacles> allObstacles;

    allObstacles.push_back(Obstacles(640, 0));
    allObstacles.push_back(Obstacles(1000, 100));
    allObstacles.push_back(Obstacles(1500, -50));
    allObstacles.push_back(Obstacles(2300, 70));
    allObstacles.push_back(Obstacles(2600, 50));
    allObstacles.push_back(Obstacles(2700, 25));

    ////
    //for (int i = 0; i < 7; i++)
    //{
    //    if (player.boxcolider.CheckOverlap(BoxColider::allObstacles[i].boxcolider))
    //    {
    //        char String[100];
    //        strcpy_s(String, "曇り");
    //        DrawFormatString(0, 0, GetColor(255, 255, 255), "今日の天気は %s です", String);
    //    }
    //}

	// ゲームループ
    while (ProcessMessage() == 0)
    {
        // 描画 
        ClearDrawScreen();

		//Backgroundの更新と描画の関数
        background.Update();
        background.Draw();

		//Playerの更新と描画の関数
        player.Update();
        player.Draw();


		//障害物の更新と描画のループ
        //for (int i = 0; i < allObstacles.size(); i++)
        /*{
            allObstacles[i].Update();
            allObstacles[i].Draw();
        }*/

        //ゲーム画面の枠
        DrawBox(0, 0, 640, 440, GetColor(255, 255, 255), FALSE);

        ScreenFlip();
    }

    DxLib_End();
    return 0;
}