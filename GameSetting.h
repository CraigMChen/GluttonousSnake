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
    static const int window_height = 40;    //��Ϸ���ڳ���
    static const int window_width = 80;     //��Ϸ���ڿ��
    static const int SPEED[5];
    static int speed;                       //��Ϸ�ٶ�

    static void GameInit();
    static bool restart();
};

int GameSetting::speed = 0;

void GameSetting::GameInit() {
    //������Ϸ���ڴ�С
    char buffer[32];
    sprintf(buffer, "mode con cols=%d lines=%d", window_width, window_height);
    system(buffer);

    //���ع��
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);      //��ȡ����̨�����Ϣ
    CursorInfo.bVisible = false;                    //���ؿ���̨���
    SetConsoleCursorInfo(handle, &CursorInfo);      //���ÿ���̨���״̬

    //��ʼ�����������
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
