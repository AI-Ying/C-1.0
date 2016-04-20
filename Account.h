/******************************************************************
*
*Copyright(c)2015,南昌大学软件学院实验小组(张欢，王沛然，闫致敬)
*All rights reserved.
*
*文件名称： Account.h
*文件标识： 见配置管理计划书
*摘    要：  本文件主要是定义账户类Account,并对该类声明，且对该类内的
*            数据成员和成员函数进行声明。
*
*
*当前版本：1.0
*作者：张欢
*完成日期：2015/6/8
*第一次修改：2015/6/8
*第二次修改：2015/6/16
*
********************************************************************/

#ifndef  ACCOUNT_H            //防止Account.h被重复引用
#define  ACCOUNT_H

#include "Main.h"             //引用非标准库函数
#include <vector>             //引用变准库函数
#include <algorithm>          //引用标准库函数

/*************************************************************************************
*类名：      Book
*
*类成员属性：protected
*数据成员：
*             string UserName;        //管理员用户名
*             string Name;            //管理员姓名
*             string ID;              //管理员工号
*             string Password;        //管理员密码
*
*
*类成员属性：public
*成员函数：
*
*             string GetUserName();                 //获取管理员用户名
*             string GetName();                     //获取管理员姓名
*             string GetID();                       //获取管理员ID号
*             string GetPassword();                 //获取管理员密码
*             string SetUserName(string username);  //设置管理员用户名
*             string SetName(string name);          //设置管理员姓名
*             string SetID(string id);              //设置管理员ID号
*             string SetPassword(string password);  //设置密码
*             //无参构造函数
*             Account();
*             //含参构造函数
*             Account(string username, string name, string id, string password);
*             //输出单个管理员信息
*             void Print();
*             //注册账户
*             void Login(vector<Account> &Account_vec);
*             //修改密码
*             void ChangePassword(vector<Account> &Account_vec);
*             //删除账户
*             void DeleteAccount(vector<Account> &Account_vec);
*             //查找账户
*             void FindAccount(vector<Account> &Account_vec);
*             //修改账户
*             void ModifyAccount(vector<Account> &Account_vec);
*             //读取管理员帐户信息到Account集中
*             void ReadFileToAccountVector(vector<Account> &Account_vec);
*             //以重写的方式保存管理员信息到Account.txt中
*             void SaveAccount(vector<Account> &Account_vec);
*             //以追加到文件尾部的方式保存管理员信息到Account.txt中
*             void SaveAccountApp(vector<Account> &Account_vec);
*             //析构函数
*             ~Account();
******************************************************************************************/
class Account
{
protected:
    //管理员用户名
    string UserName;
    //管理员姓名
    string Name;
    //管理员工号
    string ID;
    //管理员密码
    string Password;
public:
    //获取管理员用户名
    string GetUserName();
    //获取管理员姓名
    string GetName();
    //获取管理员ID号
    string GetID();
    //获取管理员密码
    string GetPassword();

    //设置管理员用户名
    string SetUserName(string username);
    //设置管理员姓名
    string SetName(string name);
    //设置管理员ID号
    string SetID(string id);
    //设置密码
    string SetPassword(string password);

    //无参构造函数
    Account();
    //含参构造函数
    Account(string username, string name, string id, string password);
    //输出单个管理员信息
    void Print();
    //注册账户
    void Login(vector<Account> &Account_vec);
    //修改密码
    void ChangePassword(vector<Account> &Account_vec);
    //删除账户
    void DeleteAccount(vector<Account> &Account_vec);
    //查找账户
    void FindAccount(vector<Account> &Account_vec);
    //修改账户
    void ModifyAccount(vector<Account> &Account_vec);
    //读取管理员帐户信息到Account集中
    void ReadFileToAccountVector(vector<Account> &Account_vec);
    //以重写的方式保存管理员信息到Account.txt中
    void SaveAccount(vector<Account> &Account_vec);
    //以追加到文件尾部的方式保存管理员信息到Account.txt中
    void SaveAccountApp(vector<Account> &Account_vec);
    //析构函数
    ~Account();
};



#endif  //ACCOUNT_H
