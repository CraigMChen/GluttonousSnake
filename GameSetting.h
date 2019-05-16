//
// Created by CMC on 2019/02/12.
//

#ifndef GLUTTONOUSSNAKE_GAMESETTING_H
#define GLUTTONOUSSNAKE_GAMESETTING_H

#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <conio.h>

class GameSetting
{
public:
    static const int window_height = 40;    //游戏窗口长度
    static const int window_width = 80;     //游戏窗口宽度
    static const int SPEED[5];
    static int speed;                       //游戏速度

    static void GameInit();
    static bool restart();
};

int GameSetting::speed = 0;

void GameSetting::GameInit() {
    //设置游戏窗口大小
    char buffer[32];
    sprintf(buffer, "mode con cols=%d lines=%d", window_width, window_height);
    system(buffer);

    //隐藏光标
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);      //获取控制台光标信息
    CursorInfo.bVisible = false;                    //隐藏控制台光标
    SetConsoleCursorInfo(handle, &CursorInfo);      //设置控制台光标状态

    //初始化随机数种子
    srand((unsigned int)time(0));
}

bool GameSetting::restart()
{
    char ch = _getch();
    if (ch == '\r')
        return true;
    return false;

}

#endif //GLUTTONOUSSNAKE_GAMESETTING_H
