/******************************************************************
*
*Copyright(c)2015,南昌大学软件学院实验小组(张欢，王沛然，闫致敬)
*All rights reserved.
*
*文件名称： Circulate.h
*文件标识： 见配置管理计划书
*摘    要：  本文件在主要包括图书流通的功能函数的声明，以及对
*            读者借阅信息BorrowLink结构体，日期Date结构体的声明。
*            建立图书流通Circulate类，并对Circulate类做出声明。
*
*
*当前版本：1.0
*作者：闫致敬
*完成日期：2015/6/10
*第一次修改：2015/6/14
*第二次修改：2015/6/20
*
********************************************************************/

#ifndef   CIRCULATE_H             //防止Circulate.h被重复引用
#define   CIRCULATE_H


#include "Main.h"                 //引用非标准库函数
#include "Reader.h"               //引用非标准库函数
#include "Book.h"                 //引用非标准库函数
#define  MAX_BOOK   6             //读者最多只能借阅6本数
#define  MAX_DAY    60            //读者一次借书最长期限




/*********************************************************************
*结构体名称：Date
*
*结构体成员属性：public
*数据成员：
*                 int Year;      //年
*                 int Month;     //月
*                 int Day;       //日
**********************************************************************/
typedef struct Date
{
public:
    //年
    int Year;
    //月
    int Month;
    //日
    int Day;
}Date;



/******************************************************************
*结构体名：BorrowLink
*
*结构体成员属性：public
*数据成员：
*        string Code;         //读者证件号
*        string ISBN;         //读者所借图书的ISBN号
*        Date BorrowDate;     //读者借书日期
*        Date LastDate;       //读者应还日期
*        Date ReturnDate;     //读者实际还书日期
*        string Tag;          //读者借书、还书状态（借出，归还）
*
*        struct BorrowLink *next;  //定义一个结构体指针
********************************************************************/
typedef struct BorrowLink
{
public:
    //读者证件号
	string Code;
	//读者所借图书的ISBN号
	string ISBN;
	//读者借书日期
	Date BorrowDate;
	//读者应还日期
	Date LastDate;
	//读者实际还书日期
	Date ReturnDate;
    //读者借书、还书状态
    //借出，归还
	string Tag;

    //定义一个结构体指针
	struct BorrowLink *next;
}BorrowLink;


/*************************************************************************************
*类名：      Book
*
*类成员属性：protected
*数据成员：
*             struct BorrowLink L;     //读者借阅信息结构体
*             struct Date D;           //日期结构体
*
*
*类成员属性：public
*成员函数：
*             //创建读者借书信息链表
*             BorrowLink *CreatBorrowLink();
*             //保存借阅的读者信息信息
*             void SaveBorrowB(string Code, string ISBN);
*             //保存读者还书的信息
*             void SaveBorrowR(string Code, string ISBN);
*             //查询读者借阅信息
*             void FindBorrow();
*             //释放链表内存
*             void DeleteMemory(BorrowLink *head);
*             //读者借书
*             void ReaderBorrow(vector<Reader> &Reader_vec);
*             //读者还书
*             void ReaderReturn(vector<Reader> &Reader_vec);
******************************************************************************************/
class Circulate
{
private:
    //读者借阅结构体
    struct BorrowLink L;
    //日期结构体
    struct Date D;
public:
    //创建读者借书信息链表
    BorrowLink *CreatBorrowLink();
    //保存借阅的读者信息信息
    void SaveBorrowB(string Code, string ISBN);
    //保存读者还书的信息
    void SaveBorrowR(string Code, string ISBN);
    //查询读者借阅信息
    void FindBorrow();
    //释放链表内存
    void DeleteMemory(BorrowLink *head);
    //读者借书
    void ReaderBorrow(vector<Reader> &Reader_vec);
    //读者还书
    void ReaderReturn(vector<Reader> &Reader_vec);
};




#endif // CIRCULATE_H

