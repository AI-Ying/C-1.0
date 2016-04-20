/******************************************************************
*
*Copyright(c)2015,南昌大学软件学院实验小组(张欢，王沛然，闫致敬)
*All rights reserved.
*
*文件名称： Menu.h
*文件标识： 见配置管理计划书
*摘    要：  本文件主要是定义菜单类Menu,并对该类声明，且对该类内的
*            数据成员和成员函数进行声明。
*
*
*当前版本：1.0
*作者：王沛然
*完成日期：2015/5/27
*第一次修改：2015/6/1
*第二次修改：2015/6/3
*
********************************************************************/

#ifndef  MENU_H                            //防止Main.h被重复引用
#define  MENU_H


/****************************************************************************
*类名：      Menu
*
*类成员属性：private
*类成员：    int choose;                    //定义用户选择，减少了多次定义
*
*类成员属性：Public
*类成员函数：
*      1.void MainOfMenu();                 //图书管理系统主菜单
*      2.void MainOfMenu_Choose();          //图书管理系统主菜单选项
*      3.void ReaderOfMenu();               //读者管理子菜单
*      4.void ReaderOfMenu_Choose();        //读者管理子菜单选项
*      5.void BookOfMenu();                 //编目管理子菜单
*      6.void BookOfMenu_Choose();          //编目管理子菜单选项
*      7.void CatalogOfMenu();              //分类目录管理子菜单
*      8.void CatalogOfMenu_Choose();       //分类目录管理子菜单选项
*      9.void CirculationOfMenu();          //图书流通管理子菜单
*     10.void CirculationOfMenu_Choose();   //图书流通管理子菜单选项
*     11.void AccountOfMenu();              //账户管理子菜单
*     12.void AccountOfMenu_Choose();       //账户管理子菜单选项
*     13.void InterfaceOfMenu();            //图书管理系统入口菜单
*************************************************************************/
class Menu
{
private:
    //菜单选项选择；
    int choose;
public :
    //图书管理系统主菜单
    void MainOfMenu();
    //图书管理系统主菜单选项
    void MainOfMenu_Choose();
    //读者管理子菜单
    void ReaderOfMenu();
    //读者管理子菜单选项
    void ReaderOfMenu_Choose();
    //编目管理子菜单
    void BookOfMenu();
    //编目管理子菜单选项
    void BookOfMenu_Choose();
    //分类目录管理子菜单
    void CatalogOfMenu();
    //分类目录管理子菜单选项
    void CatalogOfMenu_Choose();
    //图书流通管理子菜单
    void CirculationOfMenu();
    //图书流通管理子菜单选项
    void CirculationOfMenu_Choose();
    //账户管理子菜单
    void AccountOfMenu();
    //账户管理子菜单选项
    void AccountOfMenu_Choose();
    //主界面菜单
    void InterfaceOfMenu();
};


#endif // MENU_H



