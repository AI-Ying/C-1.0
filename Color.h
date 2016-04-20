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
#ifndef   COLOR_H
#define   COLOR_H

#include  "Main.h"

//在窗口控制颜色区域。
void ConPrintAt(int x, int y, char CharBuffer[], int len);
//控制整个窗口的字体颜色和背景颜色。
void SetColor(int Forc, int BackC);

#endif
