#include <iostream>
#include <cstdlib>
#include "GameSetting.h"
#include "PrintInfo.h"
#include "Snake.h"
#include "Functions.h"

using std::cin;
using std::cout;

const int GameSetting::SPEED[5] = {300, 240, 180, 120, 60};

int main()
{
    GameSetting setting;
    PrintInfo print_info;
    setting.GameInit();
    print_info.DrawChoiceInfo();

    char ch;
    ch = _getch();
    while (ch != 'Q' && ch != 'q' && ch != '\r')
    {
        gotoxy(GameSetting::window_height / 2 - 17, GameSetting::window_width / 2);
        cout << "请按下回车或Q\n";
        ch = _getch();
    }
    if(ch == 'Q' || ch == 'q')
    {
        gotoxy(GameSetting::window_width / 2 - 6, GameSetting::window_height / 2);
        cout << "再见！";
        _getch();
        return 0;
    }

    //gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height / 2 + 3);
    while(true)
    {
        bool flag;
        GameSetting::speed = 0;
        Snake snake;

        print_info.DrawMap();
        print_info.DrawHelp();

        Food food(snake.m_coordinate);      //生成食物

        while (true)
        {
            print_info.DrawInfo(snake.GetSnakeSize(), GameSetting::speed);
            food.DrawFood();
            snake.ClearSnake();
            snake.IsEatFood(food);
            snake.MoveSnake(GameSetting::speed);
            snake.DrawSnake();
            if (!snake.SnakeIsAlive())
            {
                print_info.GameOver(snake.GetSnakeSize());
                flag = setting.restart();
                break;
            }
            Sleep(GameSetting::SPEED[GameSetting::speed]);
        }
        if (!flag)
            break;
    }
    return 0;
}