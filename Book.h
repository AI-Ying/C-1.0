/******************************************************************
*
*Copyright(c)2015,南昌大学软件学院实验小组(张欢，王沛然，闫致敬)
*All rights reserved.
*
*文件名称： Book.h
*文件标识： 见配置管理计划书
*摘    要：  本文件主要是定义图书类Book,并对该类声明，且对该类内的
*            数据成员和成员函数进行声明。
*
*当前版本：1.0
*作者：张欢
*完成日期：2015/6/5
*第一次修改：2015/6/8
*第二次修改：2015/6/16
*
********************************************************************/

#ifndef  BOOK_H            //防止Book.h被重复引用
#define  BOOK_H

#include "Main.h"            //引用非标准库函数
#include <vector>            //引用变准库函数
#include <algorithm>         //引用标准库函数


/*************************************************************************************
*类名：      Book
*
*类成员属性：protected
*数据成员：
*             string ISBN;            //图书ISBN编号
*             string Title;           //图书名称
*             string Author;          //图书作者
*             string Publisher;       //图书出版商
*             string Date;            //图书出版日期
*             float  Price;           //图书价格
*             string CatalogNum;      //图书分类编号
*             int Number;             //图书的数量
*
*
*类成员属性：public
*成员函数：
*             string GetISBN();                        //获取图书ISBN编号
*             string GetTitle();                       //获取图书名称
*             string GetAuthor();                      //获取图书作者
*             string GetPublisher();                   //获取图书出版商
*             string GetDate();                        //获取图书出版日期
*             float  GetPrice();                       //获取图书价格
*             string GetCatalogNum();                  //获取图书分类编号
*             int GetNumber();                         //获取图书数量
*             string SetISBN(string isbn);             //设置图书ISBN编号
*             string SetTitle(string title);           //设置图书名称
*             string SetAuthor(string author);         //设置图书作者
*             string SetPublisher(string publisher);   //设置图书出版商
*             string SetDate(string date);             //设置图书出版日期
*             float  SetPrice(float price);            //设置图书价格
*             string SetCatalogNum(string catalognum); //设置图书分类编号
*             int SetNumber(int number);               //设置图书数量
*
*             //无参构造函数
*             Book();
*             //含参构造函数
*             Book(string isbn, string title, string author, string publisher, string date, float price, string catalognum, int number);
*             //输出单个图书信息
*             void Print();
*             //添加图书信息
*             void AddBook(vector<Book> &Book_vec);
*             //浏览图书信息
*             void BrowseBook(vector<Book> &Book_vec);
*             //修改图书信息
*             void ModifyBook(vector<Book> &Book_vec);
*             //删除图书信息
*             void DeleteBook(vector<Book> &Book_vec);
*             //根据图书ISBN编号来查找图书
*             void FindBookByISBN(vector<Book> &Book_vec);
*             //根据图书名称来查找图书
*             void FindBookByTitle(vector<Book> &Book_vec);
*             //根据图书出版商来查找图书
*             void FindBookByPublisher(vector<Book> &Book_vec);
*             //根据图书作者来查找图书
*             void FindBookByAuthor(vector<Book> &Book_vec);
*             //以重写的方式保存图书信息到book.txt文件中
*             void SaveBook(vector<Book> &Book_vec);
*             //以追加文件尾部的方式保存图书信息到book.txt文件中
*             void SaveBookApp(vector<Book> &Book_vec);
*             //读取图书信息到Book集中
*             void ReadFileToBookVector(vector<Book> &Book_vec);
*             //析构函数
*             ~Book();
******************************************************************************************/
class Book
{
protected:
    //图书ISBN编号
    string ISBN;
    //图书名称
    string Title;
    //图书作者
    string Author;
    //图书出版商
    string Publisher;
    //图书出版日期
    string Date;
    //图书价格
    float  Price;
    //图书分类编号
    string CatalogNum;
    //图书的数量
    int Number;
public:
    //获取图书ISBN编号
    string GetISBN();
    //获取图书名称
    string GetTitle();
    //获取图书作者
    string GetAuthor();
    //获取图书出版商
    string GetPublisher();
    //获取图书出版日期
    string GetDate();
    //获取图书价格
    float  GetPrice();
    //获取图书分类编号
    string GetCatalogNum();
    //获取图书数量
    int GetNumber();

    //设置图书ISBN编号
    string SetISBN(string isbn);
    //设置图书名称
    string SetTitle(string title);
    //设置图书作者
    string SetAuthor(string author);
    //设置图书出版商
    string SetPublisher(string publisher);
    //设置图书出版日期
    string SetDate(string date);
    //设置图书价格
    float  SetPrice(float price);
    //设置图书分类编号
    string SetCatalogNum(string catalognum);
    //设置图书数量
    int SetNumber(int number);

    //无参构造函数
    Book();
    //含参构造函数
    Book(string isbn, string title, string author, string publisher, string date, float price, string catalognum, int number);
    //输出单个图书信息
    void Print();
    //添加图书信息
    void AddBook(vector<Book> &Book_vec);
    //浏览图书信息
    void BrowseBook(vector<Book> &Book_vec);
    //修改图书信息
    void ModifyBook(vector<Book> &Book_vec);
    //删除图书信息
    void DeleteBook(vector<Book> &Book_vec);
    //根据图书ISBN编号来查找图书
    void FindBookByISBN(vector<Book> &Book_vec);
    //根据图书名称来查找图书
    void FindBookByTitle(vector<Book> &Book_vec);
    //根据图书出版商来查找图书
    void FindBookByPublisher(vector<Book> &Book_vec);
    //根据图书作者来查找图书
    void FindBookByAuthor(vector<Book> &Book_vec);
    //以重写的方式保存图书信息到book.txt文件中
    void SaveBook(vector<Book> &Book_vec);
    //以追加文件尾部的方式保存图书信息到book.txt文件中
    void SaveBookApp(vector<Book> &Book_vec);
    //读取图书信息到Book集中
    void ReadFileToBookVector(vector<Book> &Book_vec);
    //析构函数
    ~Book();
};





#endif   //BOOK_H
