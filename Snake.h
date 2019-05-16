//
// Created by CMC on 2019/02/12.
//

#ifndef GLUTTONOUSSNAKE_SNAKE_H
#define GLUTTONOUSSNAKE_SNAKE_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include "Food.h"
#include "GameSetting.h"
using std::vector;
using std::cin;

const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;
const int HEAD = 0;

class Snake
{
private:
    int m_direction;                    //移动方向
    bool m_is_alive;                    //蛇是否存活
    COORD map_size;                     //地图大小
public:
    vector<COORD> m_coordinate;         //蛇身坐标
    Snake();                            //默认构造函数
    void ListenKeyboard(int & speed);     //监听键盘
    void MoveSnake(int & speed);          //移动贪吃蛇
    bool IsEatFood(Food & f);           //判断是否吃到食物
    bool SnakeIsAlive();                //判断贪吃蛇是否存活
    void DrawSnake();                   //画出贪吃蛇
    void ClearSnake();                  //清除贪吃蛇
    int GetSnakeSize() { return m_coordinate.size(); }
};

Snake::Snake()
{
    map_size.X = GameSetting::window_width - 29 + 1;
    map_size.Y = GameSetting::window_height;

    m_direction = 1;                   //初始移动方向向上
    m_is_alive = true;
    COORD snake_head;
    snake_head.X = GameSetting::window_width / 2 - 15;
    snake_head.Y = GameSetting::window_height / 2 + 15;

    m_coordinate.push_back(snake_head);
    snake_head.Y++;
    m_coordinate.push_back(snake_head);
    snake_head.Y++;
    m_coordinate.push_back(snake_head); //蛇身初始长度为3
}

void Snake::ListenKeyboard(int & speed)
{
    char ch;
    if(kbhit())
    {
        ch = _getch();
        switch (ch)
        {
            case 'w':
            case 'W':
                if (m_direction == DOWN)
                    break;
                m_direction = UP;
                break;
            case 's':
            case 'S':
                if (m_direction == UP)
                    break;
                m_direction = DOWN;
                break;
            case 'a':
            case 'A':
                if (m_direction == RIGHT)
                    break;
                m_direction = LEFT;
                break;
            case 'd':
            case 'D':
                if (m_direction == LEFT)
                    break;
                m_direction = RIGHT;
                break;
            case '+':
                if (speed < 5)
                    speed++;
                break;
            case '-':
                if (speed > 0)
                    speed--;
                break;
            case ' ':
                gotoxy(1, 1);
                cout << "游戏暂停，按任意键继续";
                _getch();
                gotoxy(1, 1);
                cout << "                     ";
                break;
        }
    }
}

void Snake::MoveSnake(int & speed)
{
    ListenKeyboard(speed);
    COORD head = m_coordinate[0];
    switch (m_direction)
    {
        case UP:
            head.Y--;
            break;
        case DOWN:
            head.Y++;
            break;
        case LEFT:
            head.X--;
            break;
        case RIGHT:
            head.X++;
            break;
    }
    m_coordinate.insert(m_coordinate.begin(), head);
}

bool Snake::IsEatFood(Food & f)
{
    COORD food_coordinate = f.GetFoofCoordinate();
    //吃到食物，食物重新生成，不删除蛇尾
    if (m_coordinate[HEAD].X == food_coordinate.X && m_coordinate[HEAD].Y == food_coordinate.Y)
    {
        f.RandomXY(m_coordinate);
        return true;
    }
        //没有吃到食物，删除蛇尾
    else
    {
        m_coordinate.erase(m_coordinate.end() - 1);
        return false;
    }
}

bool Snake::SnakeIsAlive()
{
    //超出边界
    if (m_coordinate[HEAD].X <= 0 || m_coordinate[HEAD].X >= GameSetting::window_width - 29 ||
        m_coordinate[HEAD].Y <= 0 || m_coordinate[HEAD].Y >= GameSetting::window_height - 1)
    {
        m_is_alive = false;
        return m_is_alive;
    }

    //和自己撞到一起
    for (unsigned int i = 1; i < m_coordinate.size(); i++)
    {
        if (m_coordinate[i].X == m_coordinate[HEAD].X && m_coordinate[i].Y == m_coordinate[HEAD].Y)
        {
            m_is_alive = false;
            return m_is_alive;
        }
    }

    m_is_alive = true;
    return m_is_alive;

}

void Snake::DrawSnake()
{
    setColor(FRED | FI, BGREEN | BI);        //设置颜色
    for (unsigned int i = 0; i < m_coordinate.size(); i++)
    {
        gotoxy(m_coordinate[i].X, m_coordinate[i].Y);
        cout << "O";
    }

    setColor();
}

void Snake::ClearSnake()
{
    gotoxy(m_coordinate[m_coordinate.size() - 1].X, m_coordinate[m_coordinate.size() - 1].Y);
    cout << " ";
}

#endif //GLUTTONOUSSNAKE_SNAKE_H
