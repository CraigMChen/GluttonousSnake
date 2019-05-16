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
    int m_direction;                    //�ƶ�����
    bool m_is_alive;                    //���Ƿ���
    COORD map_size;                     //��ͼ��С
public:
    vector<COORD> m_coordinate;         //��������
    Snake();                            //Ĭ�Ϲ��캯��
    void ListenKeyboard(int & speed);     //��������
    void MoveSnake(int & speed);          //�ƶ�̰����
    bool IsEatFood(Food & f);           //�ж��Ƿ�Ե�ʳ��
    bool SnakeIsAlive();                //�ж�̰�����Ƿ���
    void DrawSnake();                   //����̰����
    void ClearSnake();                  //���̰����
    int GetSnakeSize() { return m_coordinate.size(); }
};

Snake::Snake()
{
    map_size.X = GameSetting::window_width - 29 + 1;
    map_size.Y = GameSetting::window_height;

    m_direction = 1;                   //��ʼ�ƶ���������
    m_is_alive = true;
    COORD snake_head;
    snake_head.X = GameSetting::window_width / 2 - 15;
    snake_head.Y = GameSetting::window_height / 2 + 15;

    m_coordinate.push_back(snake_head);
    snake_head.Y++;
    m_coordinate.push_back(snake_head);
    snake_head.Y++;
    m_coordinate.push_back(snake_head); //�����ʼ����Ϊ3
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
                cout << "��Ϸ��ͣ�������������";
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
    //�Ե�ʳ�ʳ���������ɣ���ɾ����β
    if (m_coordinate[HEAD].X == food_coordinate.X && m_coordinate[HEAD].Y == food_coordinate.Y)
    {
        f.RandomXY(m_coordinate);
        return true;
    }
        //û�гԵ�ʳ�ɾ����β
    else
    {
        m_coordinate.erase(m_coordinate.end() - 1);
        return false;
    }
}

bool Snake::SnakeIsAlive()
{
    //�����߽�
    if (m_coordinate[HEAD].X <= 0 || m_coordinate[HEAD].X >= GameSetting::window_width - 29 ||
        m_coordinate[HEAD].Y <= 0 || m_coordinate[HEAD].Y >= GameSetting::window_height - 1)
    {
        m_is_alive = false;
        return m_is_alive;
    }

    //���Լ�ײ��һ��
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
    setColor(FRED | FI, BGREEN | BI);        //������ɫ
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
