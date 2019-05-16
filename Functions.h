//
// Created by CMC on 2019/02/12.
//

#ifndef GLUTTONOUSSNAKE_MYFUNCTIONS_H
#define GLUTTONOUSSNAKE_MYFUNCTIONS_H

#include <windows.h>

#define  FRED FOREGROUND_RED
#define FBLUE FOREGROUND_BLUE
#define  FGREEN FOREGROUND_GREEN
#define FI FOREGROUND_INTENSITY
#define BRED BACKGROUND_RED
#define BBLUE BACKGROUND_BLUE
#define BGREEN BACKGROUND_GREEN
#define BI BACKGROUND_INTENSITY

//将光标移动到(x,y)位置
void gotoxy(short x, short y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//设置颜色
void setColor(unsigned short ForeColor = FRED | FBLUE | FGREEN, unsigned short BackGroundColor = 0)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, ForeColor | BackGroundColor);
}

#endif //GLUTTONOUSSNAKE_MYFUNCTIONS_H
