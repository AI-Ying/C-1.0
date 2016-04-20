/******************************************************************
*
*Copyright(c)2015,南昌大学软件学院实验小组(张欢，王沛然，闫致敬)
*All rights reserved.
*
*文件名称： Reader.h
*文件标识： 见配置管理计划书
*摘    要：  本文件主要是定义读者类Reader,并对该类声明，且对该类内
*            的数据成员和成员函数进行声明。
*
*
*当前版本：1.0
*作者：王沛然
*完成日期：2015/6/3
*第一次修改：2015/6/1
*第二次修改：2015/6/3
*
********************************************************************/

#ifndef  READER_H            //防止Reader.h被重复引用
#define  READER_H

#include "Main.h"            //引用自定义的非标准库函数
#include <vector>            //引用变准库函数
#include <algorithm>         //引用标准库函数




/*************************************************************************************
*类名：      Reader
*
*类成员属性：protected
*数据成员：
*            string Name;                    //姓名
*            string Sex;                     //性别
*            string Code;                    //证件号
*            string Dept;                    //工作单位
*            int Tag;                        //挂失状态（0-正常，1-挂失）
*            int Number                      //读者借书数量
*
*类成员属性：public
*成员函数：
*            string GetName();               //返回姓名
*            string GetSex();                //返回性别
*            string GetCode();               //返回证件号
*            string GetDept();               //返回工作单位
*            int GetTag();                   //返回挂失状态
*            int GetNumber();                //返回借书数量
*
*            string SetName(string name);    //修改姓名
*            string SetSex(string sex);      //修改性别
*            string SetCode(string code);    //修改证件号
*            string SetDept(string dept);    //修改工作单位
*            int SetTag(int tag);            //修改挂失状态
*            int SetNumber(int number);      //修改借阅图书的数量
*
*            //无参构造函数
*            Reader();
*            //含参构造函数
*            Reader(string name, string sex, string code, string dept, int tag, int number);
*            //输出单个读者信息
*            void Print();
*            //浏览读者信息
*            void BrowseReader(vector<Reader> &Reader_vec);
*            //增加读者信息
*            void AddReader(vector<Reader> &Reader_vec);
*            //根据证件号查询读者信息
*            void FindReaderByCode(vector<Reader> &Reader_vec);
*            //根据姓名查询读者信息
*            void FindReaderByName(vector<Reader> &Reader_vec);
*            //修改读者信息
*            void ModifyReader(vector<Reader> &Reader_vec);
*            //删除读者信息
*            void DeleteReader(vector<Reader> &Reader_vec);
*            //证件挂失
*            void LostReader(vector<Reader> &Reader_vec);
*            //以重写的方式保存读者信息
*            void SaveReader(vector<Reader> &Reader_vec);
*            //以追加文件尾的方式保存读者信息
*            void SaveReaderApp(vector<Reader> &Reader_vec);
*            //读取文件信息到容器中
*            void ReadFileToReaderVector(vector<Reader> &Reader_vec);
*            //析构函数
*            ~Reader();
*
******************************************************************************************/
class Reader
{
protected:
    //姓名
    string Name;
    //性别
    string Sex;
    //证件号
    string Code;
    //工作单位
    string Dept;
    //挂失状态（0-正常，1-挂失）
    int Tag;
    //记录读者借书数量
    int Number;
public:
    //返回姓名
    string GetName();
    //返回性别
    string GetSex();
    //返回证件号
    string GetCode();
    //返回工作单位
    string GetDept();
    //返回挂失状态
    int GetTag();
    //返回借书数量
    int GetNumber();

    //修改姓名
    string SetName(string name);
    //修改性别
    string SetSex(string sex);
    //修改证件号
    string SetCode(string code);
    //修改工作单位
    string SetDept(string dept);
    //修改挂失状态
    int SetTag(int tag);
    //修改借阅图书的数量
    int SetNumber(int number);

    //无参构造函数
    Reader();
    //含参构造函数
    Reader(string name, string sex, string code, string dept, int tag, int number);
    //输出单个读者信息
    void Print();
    //浏览读者信息
    void BrowseReader(vector<Reader> &Reader_vec);
    //增加读者信息
    void AddReader(vector<Reader> &Reader_vec);
    //根据证件号查询读者信息
    void FindReaderByCode(vector<Reader> &Reader_vec);
    //根据姓名查询读者信息
    void FindReaderByName(vector<Reader> &Reader_vec);
    //修改读者信息
    void ModifyReader(vector<Reader> &Reader_vec);
    //删除读者信息
    void DeleteReader(vector<Reader> &Reader_vec);
    //证件挂失
    void LostReader(vector<Reader> &Reader_vec);
    //以重写的方式保存读者信息
    void SaveReader(vector<Reader> &Reader_vec);
    //以追加文件尾的方式保存读者信息
    void SaveReaderApp(vector<Reader> &Reader_vec);
    //读取文件信息到容器中
    void ReadFileToReaderVector(vector<Reader> &Reader_vec);
    //析构函数
    ~Reader();
};


#endif // READER_H
