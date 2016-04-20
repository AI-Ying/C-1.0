/******************************************************************
*
*Copyright(c)2015,南昌大学软件学院实验小组(张欢，王沛然，闫致敬)
*All rights reserved.
*
*文件名称： Color.h
*文件标识： 见配置管理计划书
*摘    要：  本文件主要是对控制台颜色函数的声明，没有定义成类，
*            主要是为了考虑其他类对该函数的访问方便。
*
*
*当前版本：1.0
*作者：张欢
*完成日期：2015/6/15
*
********************************************************************/

#include  "Color.h"                   //引用非标准库头文件



/***************************************************
*函数名：    ConPrintAt()
*函数功能：  对一段字符串实现颜色
*
*
*函数参数：  颜色起始位置坐标（x,y）
*             要实现颜色的字符串 char CharBuffer[]
*             实现颜色的区域长度  int len
*函数返回值：void
***************************************************/
void ConPrintAt(int x, int y, char CharBuffer[], int len)
{
   DWORD number;
   COORD coord = {x, y};
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorPosition(hStdOut, coord);
   WriteConsole(hStdOut, CharBuffer, len, &number, NULL);
}



/***************************************************
*函数名：    SetColor()
*函数功能：  对一段字符串实现颜色
*
*
*函数参数：  字体颜色：ForgC
*             背景颜色：BackC
*函数返回值：void
***************************************************/
void SetColor(int ForgC, int BackC)
{
   WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
