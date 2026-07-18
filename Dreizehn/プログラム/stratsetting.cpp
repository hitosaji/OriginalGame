#include "DxLib.h"
#include <iostream>
#include "Startsetting.h"

//スタート開始時のコンストラクト
Startsetting::Startsetting()
{
}

//
void Startsetting::Update()
{
    //
    int now = CheckHitKey(KEY_INPUT_SPACE);

    // 押した瞬間
    if (now == 1 && prev == 0) 
    {
        if (!isPlaying)
        {   
            pressCount++;

            if (pressCount >= 3)
            {
                isPlaying = true; // ゲーム開始
            }
        }
    }
    if (isPlaying)
    {
        // 通常の処理
      // y += vy;
    }
    else
    {
        // 待機状態（固定）
        y = 200; // 中央に固定
        vy = 0;
    }

    if (!isPlaying)
    {
        DrawString(320, 330, "三回押しでスタート", GetColor(255, 255, 255));  
    }
    prev = now;
}
