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
    static void DrawChoiceInfo();           //ѡ��ģʽ
    static void DrawMap();                  //����ͼ�߽�
    static void GameOver(int score);        //��Ϸ����
    static void DrawInfo(int score, int speed);        //��Ϸ��Ϣ
    static void DrawHelp();                 //��Ϸ����˵��
};

void PrintInfo::DrawChoiceInfo()
{
    gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height / 2 - 7);
    setColor(FRED | FGREEN | FI, 0);
    cout << "*******̰����*******\n";
    gotoxy(GameSetting::window_width /2 - 10, GameSetting::window_height / 2 - 6);
    cout << "*                  *\n";

    gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height / 2 - 5);
    setColor(FBLUE | FI, 0);
    cout << "* ���س�����ʼ��Ϸ *\n";
    gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height / 2 - 4);
    cout << "*                  *\n";

    gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height / 2 - 3);
    setColor(FGREEN | FI, 0);
    cout << "*   ����Q�˳���Ϸ  *\n";
    gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height /2 - 2);
    cout << "********************\n";

    gotoxy(GameSetting::window_width - 21, GameSetting::window_height - 1);
    setColor(FBLUE | FI, BRED | BI);
    cout << "���ߣ�CMC�� �汾��1.1";

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
    cout << "��ǰ��ҷ�����" << score << endl;
    gotoxy(GameSetting::window_width - 22, 8);
    cout << "��ǰ��Ϸ�ٶȣ�" << speed + 1 << endl;
    setColor();
}

void PrintInfo::GameOver(int score)
{
    setColor(FRED | FI);
    gotoxy(GameSetting::window_width / 2 - 20, GameSetting::window_height / 2 - 5);
    cout << "��Ϸ������\n";
    gotoxy(GameSetting::window_width / 2 - 20, GameSetting::window_height / 2 - 3);
    cout << "��ĵ÷�Ϊ��" << score << endl;
    gotoxy(GameSetting::window_width / 2 - 20, GameSetting::window_height / 2 - 1);
    cout << "���س������¿�ʼ\n";
    gotoxy(GameSetting::window_width / 2 - 20, GameSetting::window_height / 2);
    cout << "������˳���Ϸ\n";
    setColor();
}

void PrintInfo::DrawHelp()
{
    setColor(FGREEN | FI);
    gotoxy(GameSetting::window_width - 22, 18);
    cout << "��Ϸ����˵����\n";
    gotoxy(GameSetting::window_width - 22, 20);
    cout << "W����    S����\n";
    gotoxy(GameSetting::window_width - 22, 22);
    cout << "A����    D����\n";

    gotoxy(GameSetting::window_width - 22, 24);
    cout << "������Ϸ�ٶȣ�\n";
    gotoxy(GameSetting::window_width - 22, 26);
    cout << "С���� + ���ӿ�\n";
    gotoxy(GameSetting::window_width - 22, 28);
    cout << "С���� - ������\n";
    gotoxy(GameSetting::window_width - 22, 30);
    cout << "�ո����ͣ\n";

    gotoxy(GameSetting::window_width - 22, 32);
    cout << "���ߣ� CMC\n";
    gotoxy(GameSetting::window_width - 22, 34);
    cout << "�汾�� 1.1\n";
    setColor();
}

#endif //GLUTTONOUSSNAKE_PRINTINFO_H
