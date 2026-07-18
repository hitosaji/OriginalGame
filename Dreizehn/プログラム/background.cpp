#include "DxLib.h"
#include "background.h"
#include"startsetting.h"

void Background::Init()
{
    //画像の読み込み
    handle1 = LoadGraph("Picture/perfect_loop1.bmp");
   
    back1 = 0;
    back2 = 2172; // 画面幅ぶん右に配置
}

void Background::Update()
{   
    startsetting.Update();
    startsetting.isPlaying;
    if (startsetting.isPlaying == FALSE)
    {
        back1 = 0;
        back2 = 2172;
    }
    else
    {
        //背景の速度
        back1 -= 1.25f;
        back2 -= 1.25f;

        // 画面外に出たらループ
        if (back1 <= -2172) back1 = back2 + 2172;
        if (back2 <= -2172) back2 = back1 + 2172;
    }
}

void Background::Draw()
{  
    //背景画像２枚のループ
    DrawGraph((int)back1, 0, handle1, TRUE);
    DrawGraph((int)back2, 0, handle1, TRUE);
}
