/******************************************************************
*
*Copyright(c)2015,�ϲ���ѧ���ѧԺʵ��С��(�Ż�������Ȼ�����¾�)
*All rights reserved.
*
*�ļ����ƣ� Color.h
*�ļ���ʶ�� �����ù���ƻ���
*ժ    Ҫ��  ���ļ���Ҫ�ǶԿ���̨��ɫ������������û�ж�����࣬
*            ��Ҫ��Ϊ�˿���������Ըú����ķ��ʷ��㡣
*
*
*��ǰ�汾��1.0
*���ߣ��Ż�
*������ڣ�2015/6/15
*
********************************************************************/

#include  "Color.h"                   //���÷Ǳ�׼��ͷ�ļ�



/***************************************************
*��������    ConPrintAt()
*�������ܣ�  ��һ���ַ���ʵ����ɫ
*
*
*����������  ��ɫ��ʼλ�����꣨x,y��
*             Ҫʵ����ɫ���ַ��� char CharBuffer[]
*             ʵ����ɫ�����򳤶�  int len
*��������ֵ��void
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
*��������    SetColor()
*�������ܣ�  ��һ���ַ���ʵ����ɫ
*
*
*����������  ������ɫ��ForgC
*             ������ɫ��BackC
*��������ֵ��void
***************************************************/
void SetColor(int ForgC, int BackC)
{
   WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
