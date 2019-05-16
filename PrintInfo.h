//
// Created by CMC on 2019/02/12.
//

#ifndef GLUTTONOUSSNAKE_PRINTINFO_H
#define GLUTTONOUSSNAKE_PRINTINFO_H

#include <cstdlib>
#include <iostream>
#include "GameSetting.h"
#include "Functions.h"

using std::cout;
using std::endl;

class PrintInfo
{
public:
    static void DrawChoiceInfo();           //选择模式
    static void DrawMap();                  //画地图边界
    static void GameOver(int score);        //游戏结束
    static void DrawInfo(int score, int speed);        //游戏信息
    static void DrawHelp();                 //游戏操作说明
};

void PrintInfo::DrawChoiceInfo()
{
    gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height / 2 - 7);
    setColor(FRED | FGREEN | FI, 0);
    cout << "*******贪吃蛇*******\n";
    gotoxy(GameSetting::window_width /2 - 10, GameSetting::window_height / 2 - 6);
    cout << "*                  *\n";

    gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height / 2 - 5);
    setColor(FBLUE | FI, 0);
    cout << "* 按回车键开始游戏 *\n";
    gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height / 2 - 4);
    cout << "*                  *\n";

    gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height / 2 - 3);
    setColor(FGREEN | FI, 0);
    cout << "*   按下Q退出游戏  *\n";
    gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height /2 - 2);
    cout << "********************\n";

    gotoxy(GameSetting::window_width - 21, GameSetting::window_height - 1);
    setColor(FBLUE | FI, BRED | BI);
    cout << "作者：CMC， 版本：1.1";

    setColor();
}

void PrintInfo::DrawMap()
{
    system("cls");
    setColor(FRED | FGREEN | FBLUE | FI, 0);
    for (int i = 0; i < GameSetting::window_width; i++)
        cout << "=";
    cout << endl;
    for (int i = 0; i < GameSetting::window_height - 2; i++)
    {
        for (int j = 0; j < GameSetting::window_width; j++)
        {
            if (i == 13 && j >= GameSetting::window_width - 29)
                cout << "=";
            else if (j == 0 || j == GameSetting::window_width - 29 || j == GameSetting::window_width -1)
                cout << "|";
            else
                cout << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < GameSetting::window_width; i++)
        cout << "=";

    setColor();
}

void PrintInfo::DrawInfo(int score, int speed)
{
    setColor(FBLUE | FGREEN | FI, 0);
    gotoxy(GameSetting::window_width - 22, 6);
    cout << "当前玩家分数：" << score << endl;
    gotoxy(GameSetting::window_width - 22, 8);
    cout << "当前游戏速度：" << speed + 1 << endl;
    setColor();
}

void PrintInfo::GameOver(int score)
{
    setColor(FRED | FI);
    gotoxy(GameSetting::window_width / 2 - 20, GameSetting::window_height / 2 - 5);
    cout << "游戏结束！\n";
    gotoxy(GameSetting::window_width / 2 - 20, GameSetting::window_height / 2 - 3);
    cout << "你的得分为：" << score << endl;
    gotoxy(GameSetting::window_width / 2 - 20, GameSetting::window_height / 2 - 1);
    cout << "按回车键重新开始\n";
    gotoxy(GameSetting::window_width / 2 - 20, GameSetting::window_height / 2);
    cout << "任意键退出游戏\n";
    setColor();
}

void PrintInfo::DrawHelp()
{
    setColor(FGREEN | FI);
    gotoxy(GameSetting::window_width - 22, 18);
    cout << "游戏操作说明：\n";
    gotoxy(GameSetting::window_width - 22, 20);
    cout << "W：上    S：下\n";
    gotoxy(GameSetting::window_width - 22, 22);
    cout << "A：左    D：右\n";

    gotoxy(GameSetting::window_width - 22, 24);
    cout << "调节游戏速度：\n";
    gotoxy(GameSetting::window_width - 22, 26);
    cout << "小键盘 + ：加快\n";
    gotoxy(GameSetting::window_width - 22, 28);
    cout << "小键盘 - ：减慢\n";
    gotoxy(GameSetting::window_width - 22, 30);
    cout << "空格键暂停\n";

    gotoxy(GameSetting::window_width - 22, 32);
    cout << "作者： CMC\n";
    gotoxy(GameSetting::window_width - 22, 34);
    cout << "版本： 1.1\n";
    setColor();
}

#endif //GLUTTONOUSSNAKE_PRINTINFO_H
