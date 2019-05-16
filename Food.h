//
// Created by CMC on 2019/02/12.
//

#ifndef GLUTTONOUSSNAKE_FOOD_H
#define GLUTTONOUSSNAKE_FOOD_H

#include <windows.h>
#include <vector>
#include <iostream>
#include "GameSetting.h"
#include "Functions.h"

using std::vector;
using std::cout;
using std::endl;

//食物类
class Food
{
private:
    COORD m_coordinate;     //食物坐标
    //坐标范围
    //x : [1, GameSetting::window_width - 30]
    //y : [1, GameSetting::window_height - 2]
public:
    void RandomXY(vector<COORD> & coord);
    Food(vector<COORD> & coord) { RandomXY(coord); }
    void DrawFood();
    COORD GetFoofCoordinate() { return m_coordinate; }
};

void Food::RandomXY(vector<COORD> &coord)
{
    m_coordinate.X = rand() % (GameSetting::window_width - 30) + 1;
    m_coordinate.Y = rand() % (GameSetting::window_height - 2) + 1;
    while (true)
    {
        bool flag = true;
        for (int i = 0; i < coord.size(); i++)
        {
            if(coord[i].X == m_coordinate.X && coord[i].Y == m_coordinate.Y)
            {
                flag = false;
                m_coordinate.X = rand() % (GameSetting::window_width - 30) + 1;
                m_coordinate.Y = rand() % (GameSetting::window_height - 2) + 1;
                break;
            }
        }
        if (flag)
            break;
    }
}

void Food::DrawFood()
{
    setColor(FRED | FI, 0);
    gotoxy(m_coordinate.X, m_coordinate.Y);
    cout << "@";
    setColor();
}

#endif //GLUTTONOUSSNAKE_FOOD_H
