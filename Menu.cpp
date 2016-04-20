
/********************************************************************************
*
*Copyright(c)2015,南昌大学软件学院实验小组(张欢，王沛然，闫致敬)
*All rights reserved.
*
*文件名称： Menu.cpp
*文件标识： 见配置管理计划书
*
*摘    要： 本文件主要包括图书管理系统的所涉及的菜单。
*           图书管理入口菜单：  InterfaceOfMenu();
*           图书管理主菜单函数：MainofMenu(),MainOfMenu_Choose();
*           读者管理子菜单函数：ReaderOfMenu(),ReaderOfMenu_Choose();
*           图书分类子菜单函数：CatalogOfMenu(),CatalogOfMenu_Choose();
*           编目管理子菜单函数：BookOfMenu(), BookOfMenu_Choose();
*           图书流通子菜单函数：CirculationOfMenu(),CirculationOfMenu_Choose();
*
*
*当前版本：1.0
*作者：王沛然
*完成日期：2015/5/27
*第一次修改：2015/6/1
*第二次修改：2015/6/3
*
**********************************************************************************/



#include "Main.h"             //引用非标准库函数
#include "Menu.h"             //引用非标准库函数
#include "Reader.h"           //引用非标准库函数
#include "Book.h"             //引用非标准库函数
#include "Account.h"          //引用非标准库函数
#include "Catalog.h"          //引用非标准库函数
#include "Circulate.h"        //引用非标准库函数
#include "Color.h"            //引用非标准库函数



void Menu::InterfaceOfMenu()
{
    //设置当前窗口的字体和背景颜色
    system("color 5b");

    //获取系统当前时间
    time_t curtime = time(NULL);
    //定义一个时间结构体
    tm last;
    //把系统时间转化为日历时间
    last =*localtime(&curtime);
    int day,mon,year, hour, minute, second;
    day  = last.tm_mday;
    mon  = last.tm_mon + 1;
    year = last.tm_year + 1900;
    hour = last.tm_hour;
    minute = last.tm_min;
    second = last.tm_sec;


    cout << "\n\n\n\t\t-------------------------------------------------------\n" << endl;
	cout << "\t\t           欢迎来到南昌大学图书馆管理系统              \n" << endl;
	cout << "\t\t-------------------------------------------------------\n" << endl;
    cout << "\n\t\t\t 厚 ┎════┰════┒ 格"     << endl;
    cout << "\t\t\t    ║﹎﹎﹎﹎┃﹎﹎﹎﹎║  "  << endl;
    cout << "\t\t\t 德 ║﹎﹎    ┃﹎﹎﹎  ║ 物" << endl;
    cout << "\t\t\t    ║﹎﹎﹎﹎┃﹎﹎﹎﹎║ "   << endl;
    cout << "\t\t\t 泽 ║﹎﹎╱╲┃﹎﹎    ║ 致" << endl;
    cout << "\t\t\t    ║﹎﹎◣╱┃﹎﹎﹎﹎║"    << endl;
    cout << "\t\t\t 人 ┖════┸════┚ 新\n"     << endl;
    cout << "\n\n\t\t\t\t\t\t软工142班"         << endl;
    cout << "\t\t\t\t\t\t张欢、王沛然、闫致敬\n"<< endl;
	cout << "\t\t-------------------------------------------------------" << endl;
	cout << "\t\t温馨提示：\t\t\t";
    cout << year << "年" << mon << "月" << day << "日" << hour << ":" << minute << ":" << second << endl;
    cout << "\t\t-------------------------------------------------------\n\n\n" << endl;

    system("pause");
    system("cls");

    MainOfMenu();
}



/************************************************************************
*函数名：    MainOfMenu()
*函数功能：  打印图书馆里主菜单，并调用MainOfMenu_Choose()这个函数。
*
*函数参数：  void
*函数返回值：void
*************************************************************************/
void Menu::MainOfMenu(void)
{
    //设置当前缓冲区颜色
    system("color 87");
    //设置字符串的背景颜色和字体颜色
    SetColor(9, 14);
    //设置字符串的缓冲区大小
    ConPrintAt(32, 3, " ★图书管理系统主菜单★ ", 24);

    SetColor(11,8);
	cout << "\n\n\t\t=======================================================\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==         1.读者管理                                ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==         2.图书编目管理                            ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==         3.图书分类管理                            ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==         4.图书流通管理                            ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==         5.账户管理                                ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==         0.退出                                    ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t=======================================================\n";

	MainOfMenu_Choose();
}


/*************************************************************************
*函数名：    MainOfMenu_Choose()
*函数功能：  对图书管理系统主菜单进行数字选择。
*            输入选项（0-5）：
*            1.读者管理
*            2.图书分类管理
*            3.图书编目管理
*            4.图书流通管理
*            5.账户管理
*            0.退出
*
*函数参数：  void
*函数返回值：void
*************************************************************************/
void Menu::MainOfMenu_Choose()
{
    cout << "请输入您的选择：";
    cin  >> choose;

    switch(choose)
    {
    case 1:
        {
            system("cls");
            while(1)
            {
				ReaderOfMenu();
            }
            system("cls");
            break;
        }
    case 2:
        {
            system("cls");
            while (1)
            {
                BookOfMenu();
            }
            system("cls");
            break;
        }
    case 3:
        {
            system("cls");
            while (1)
            {
                CatalogOfMenu();
            }
            system("cls");
            break;
        }
    case 4:
        {
            system("cls");
            while (1)
            {
                CirculationOfMenu();
            }
            system("cls");
            break;
        }
    case 5:
        {
            system("cls");
            while (1)
            {
                AccountOfMenu();
            }
            system("cls");
            break;
        }
    case 0:
        {
            exit(0);
        }
    default :
        {
            cout << "您的选择出现错误，请重新输入！\n";
            system("pause");
            system("cls");
        }
    }
}


/*************************************************************************
*函数名：    ReaderOfMenu();
*函数功能：  打印读者管理子菜单，并调用ReaderOfMenu_Choose()这个函数。
*
*函数参数：  void
*函数返回值：void
*************************************************************************/
void Menu::ReaderOfMenu()
{
    //设置字符串的背景颜色和字体颜色
    SetColor(1, 10);
    //设置字符串的缓冲区大小
    ConPrintAt(33, 3, " ★读者管理子菜单★ ", 20);

    SetColor(14, 8);
	cout << "\n\n\t\t=======================================================\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        1.浏览所有读者信息                         ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        2.增加读者信息                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        3.查询读者信息                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        4.修改读者信息                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        5.删除读者信息                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        6.证件挂失                                 ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        0.返回上一级                               ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t=======================================================\n";

	ReaderOfMenu_Choose();
}
/**************************************************************************
*函数名：    ReaderOfMenu_Choose();
*函数功能：  对读者管理子菜单进行数字选择。
*            输入选项（0-6）：
*            1.浏览所有读者信息
*            2.增加读者信息
*            3.查询读者信息
*            4.修改读者信息
*            5.删除读者信息
*            6.证件挂失
*            0.返回上一级
*
*函数参数：  void
*函数返回值：void
**************************************************************************/
void Menu::ReaderOfMenu_Choose()
{
    //创建Reader的一个对象 reader.
    Reader reader;
    //创建Reader容器，并命名为Reader_vec
    vector <Reader> Reader_vec;

	cout << "请输入您的选择：";
	cin >> choose;
    switch(choose)
	{
	case 1:
		{
		    system("cls");
		    //预先读取读者信息到Reader容器中
            reader.ReadFileToReaderVector(Reader_vec);
            //浏览读者信息
		    reader.BrowseReader(Reader_vec);
		    system("pause");
		    system("cls");
		    //清除缓存区
		    cin.clear();
		    cin.sync();
			break;
		}
	case 2:
		{
		    system("cls");
		    //添加读者信息
		    reader.AddReader(Reader_vec);
            system("pause");
            system("cls");
            //清除缓存区
		    cin.clear();
		    cin.sync();
			break;
		}
	case 3:
		{
            //预先读取读者信息到Reader容器中
            reader.ReadFileToReaderVector(Reader_vec);
            system("cls");
		    int ch;
		    cout << "\n\n\t请选择查询方式（1.姓名/2.证件号）：";
		    cin.get();
		    cin >> ch;
		    if (ch == 1)
            {
                system("cls");
                //通过读者的姓名查找读者信息
                reader.FindReaderByName(Reader_vec);
                system("pause");
                system("cls");
                //清除缓存区
                cin.clear();
                cin.sync();
                break;
            }
            else if (ch == 2)
            {
                system("cls");
                //通过读者证件号查找读者信息
                reader.FindReaderByCode(Reader_vec);
                system("pause");
                system("cls");
                //清除缓存区
                cin.clear();
                cin.sync();
                break;
            }

		}
	case 4:
		{
            system("cls");
            //预先读取读者信息到Reader容器中
            reader.ReadFileToReaderVector(Reader_vec);
            //修改读者信息
            reader.ModifyReader(Reader_vec);
            system("pause");
            system("cls");
            //清除缓存区
		    cin.clear();
		    cin.sync();
			break;
		}
	case 5:
		{
		    system("cls");
            //预先读取读者信息到Reader容器中
            reader.ReadFileToReaderVector(Reader_vec);
            //删除读者信息
            reader.DeleteReader(Reader_vec);
            system("pause");
            system("cls");
            //清除缓存区
		    cin.clear();
		    cin.sync();
			break;
		}
	case 6:
		{   system("cls");
            //预先读取读者信息到Reader容器中
            reader.ReadFileToReaderVector(Reader_vec);
            //读者信息挂失
            reader.LostReader(Reader_vec);
            system("pause");
            system("cls");
            //清除缓存区
		    cin.clear();
		    cin.sync();
			break;
		}
	case 0:
		{
			system("cls");
			//返回主菜单
			MainOfMenu();
			system("cls");
			//清除缓存区
		    cin.clear();
		    cin.sync();
			break;
		}
	default :
		{
			cout << "您的选择出现错误，请重新输入！\n";
			system("pause");
			system("cls");
			//清除缓存区
		    cin.clear();
		    cin.sync();
		}
	}
}



/**************************************************************************
*函数名：    BookOfMenu();
*函数功能：  打印图书编目管理子菜单，并调用函数BookOfMenu_Choose();
*
*函数参数：  void
*函数返回值：void
**************************************************************************/
void Menu::BookOfMenu()
{
    //设置字符串的背景颜色和字体颜色
    SetColor(2, 11);
    //设置字符串的缓冲区大小
    ConPrintAt(33, 3, " ★编目管理子菜单★ ", 20);

    SetColor(14, 8);
	cout << "\n\n\t\t=======================================================\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        1.新书录入                                 ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        2.浏览图书信息                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        3.修改图书信息                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        4.删除图书信息                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        5.查询图书信息                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        0.返回上一级                               ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t=======================================================\n";
	BookOfMenu_Choose();
}
/**************************************************************************
*函数名：    BookOfMenu_Choose();
*函数功能：  对图书编目管理子菜单进行数字选择。
*            输入选项（0-5）
*            1.新书录入
*            2.浏览图书信息
*            3.修改图书信息
*            4.删除图书信息
*            5.查询图书信息
*            0.返回上一级
*
*函数参数：  void
*函数返回值：void
**************************************************************************/
void Menu::BookOfMenu_Choose()
{
    //定义一个图书对象
    Book book;
    //创建Book容器，并命名为Book_vec
    vector<Book> Book_vec;

    cout << "请输入您的选择：";
    cin >> choose;
	switch(choose)
	{
	case 1:
		{
		    system("cls");
		    //添加图书信息
		    book.AddBook(Book_vec);
		    system("pause");
		    system("cls");
		    //清除缓存区
		    cin.clear();
		    cin.sync();
			break;
		}
	case 2:
		{
            system("cls");
            //从文件读取图书数据到Book容器中
            book.ReadFileToBookVector(Book_vec);
            //浏览图书信息
		    book.BrowseBook(Book_vec);
		    system("pause");
		    system("cls");
		    //清除缓存区
		    cin.clear();
		    cin.sync();
			break;
		}
	case 3:
		{
		    system("cls");
		    //从文件读取图书数据到Book容器中
            book.ReadFileToBookVector(Book_vec);
            //修改图书信息
		    book.ModifyBook(Book_vec);
		    system("pause");
		    system("cls");
		    //清除缓存区
		    cin.clear();
		    cin.sync();
			break;
		}
	case 4:
		{
		    system("cls");
		    //从文件读取图书数据到Book容器中
            book.ReadFileToBookVector(Book_vec);
		    book.DeleteBook(Book_vec);
		    system("pause");
		    system("cls");
		    //清除缓存区
		    cin.clear();
		    cin.sync();
			break;
		}
	case 5:
		{
		    //从文件读取图书数据到Book容器中
            book.ReadFileToBookVector(Book_vec);
		    int num;
		    cout << "请输入查询方式（1.ISBN/2.书名/3.作者/4出版商）：";
		    cin.get();
		    cin >> num;
		    if (num == 1)
            {
                system("cls");
                //根据图书的ISBN编号来查询图书信息
                book.FindBookByISBN(Book_vec);
                system("pause");
                system("cls");
                //清除缓存区
                cin.clear();
                cin.sync();
                break;
            }
            else if (num == 2)
            {
                system("cls");
                //根据图书的名称来查询图书信息
                book.FindBookByTitle(Book_vec);
                system("pause");
                system("cls");
                //清除缓存区
                cin.clear();
                cin.sync();
                break;
            }
            else if (num == 3)
            {
                system("cls");
                //根据图书的作者来查询图书信息
                book.FindBookByAuthor(Book_vec);
                system("pause");
                system("cls");
                //清除缓存区
                cin.clear();
                cin.sync();
                break;
            }
            else if (num == 4)
            {
                system("cls");
                //根据图书的出版商来查询图书信息
                book.FindBookByPublisher(Book_vec);
                system("pause");
                system("cls");
                //清除缓存区
                cin.clear();
                cin.sync();
                break;
            }
			break;
		}
	case 0:
		{
			system("cls");
			MainOfMenu();
			//返回主菜单
			MainOfMenu_Choose();
			//清除缓存区
		    cin.clear();
		    cin.sync();
			break;
		}
	default :
		{
			cout << "您的选择出现错误，请重新输入！\n";
			system("pause");
			system("cls");
			//清除缓存区
		    cin.clear();
		    cin.sync();
		}
	}
}



/**************************************************************************
*函数名：    CatalogOfMenu();
*函数功能：  输出图书分类管理子菜单，并调用CatalogOfMenu_Choose();
*
*函数参数：  void
*函数返回值：void
**************************************************************************/
void Menu::CatalogOfMenu()
{
    //设置字符串的背景颜色和字体颜色
    SetColor(2, 13);
    //设置字符串的缓冲区大小
    ConPrintAt(32, 3, " ★分类目录管理子菜单★ ", 24);

    SetColor(14, 8);
	cout << "\n\n\t\t=======================================================\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        1.输出图书分类                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        2.增加图书分类                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        3.删除图书分类                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        4.修改图书分类                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        5.查询图书分类                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        6.输出树形分类树                           ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        0.返回上一级                               ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t=======================================================\n";
	CatalogOfMenu_Choose();
}
/**************************************************************************
*函数名：    CatalogOfMenu_Choose();
*函数功能：  对图书分类管理子菜单进行数字选择。
*            输入选项（0-5）
*            1.输出图书分类
*            2.增加图书分类
*            3.删除图书分类
*            4.修改图书分类
*            5.查询图书分类
*            6.输出树形分类树
*            0.返回上一级
*
*函数参数：  void
*函数返回值：void
**************************************************************************/
void Menu::CatalogOfMenu_Choose()
{
    Catalog catalog;
    cout << "请输入您的选择：";
	cin >> choose;

	switch(choose)
	{
        case 1:
        {
            system("cls");
            catalog.PrintCatalog();
		    system("pause");
		    system("cls");
		    //清除缓存区
		    cin.clear();
		    cin.sync();
            break;
        }
        case 2:
        {
            system("cls");
		    catalog.AddCatalog();
		    system("pause");
		    system("cls");
		    //清除缓存区
		    cin.clear();
		    cin.sync();
            break;
        }
        case 3:
        {
            system("cls");
		    catalog.DeleteCatalog();
		    system("pause");
		    system("cls");
		    //清除缓存区
		    cin.clear();
		    cin.sync();
            break;
        }
        case 4:
        {
            system("cls");
		    catalog.ModifyCatalog();
		    system("pause");
		    system("cls");
		    //清除缓存区
		    cin.clear();
		    cin.sync();
            break;
        }
        case 5:
        {
            system("cls");
		    catalog.QueryCatalog();
		    system("pause");
		    system("cls");
		    //清除缓存区
		    cin.clear();
		    cin.sync();
            break;
        }
        case 6:
        {
            system("cls");
		    catalog.CreatCatalogTree();
		    system("pause");
		    system("cls");
		    //清除缓存区
		    cin.clear();
		    cin.sync();
            break;
        }
        case 0:
        {
            system("cls");
            MainOfMenu();
            MainOfMenu_Choose();
            //清除缓存区
		    cin.clear();
		    cin.sync();
            break;
        }
        default :
        {
            cout << "您的选择出现错误，请重新输入！\n";
            system("pause");
            system("cls");
            //清除缓存区
		    cin.clear();
		    cin.sync();
        }
	}
}



/**************************************************************************
*函数名：    CirculationOfMenu();
*函数功能：  打印图书流通管理子菜单，并调用函数CirculationOfMenu_Choose();
*
*函数参数：  void
*函数返回值：void
**************************************************************************/
void Menu::CirculationOfMenu()
{
    //设置字符串的背景颜色和字体颜色
    SetColor(2, 12);
    //设置字符串的缓冲区大小
    ConPrintAt(32, 3, " ★图书流通管理子菜单★ ", 24);

    SetColor(14, 8);
	cout << "\n\n\t\t=======================================================\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        1.浏览图书                                 ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        2.借书                                     ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        3.还书                                     ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        4.图书检索                                 ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        5.图书分类浏览                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        6.查询图书借阅记录                         ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        0.返回上一级                               ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t=======================================================\n";

	CirculationOfMenu_Choose();
}
/**************************************************************************
*函数名：    CirculationOfMenu_Choose();
*函数功能：  对图书流通管理子菜单进行数字选择。
*            输入选项（0-7）
*            1.浏览图书
*            2.还书
*            3.续借
*            4.罚款
*            5.图书检索
*            6.图书分类浏览
*            7.查询图书借阅记录
*            0.返回上一级
*
*函数参数：  void
*函数返回值：void
**************************************************************************/
void Menu::CirculationOfMenu_Choose()
{
    //定义一个分类图书的对象
	Catalog Catalog;
	Circulate borrow;
	Reader reader;
	Book book;

	cout << "请输入您的选择：";
	cin >> choose;
	switch(choose)
	{
	case 1:
		{
		    system("cls");
		    vector<Book> Book_vec;
            book.ReadFileToBookVector(Book_vec);
		    book.BrowseBook(Book_vec);
		    system("pause");
		    system("cls");
		    //清除缓存区
		    cin.clear();
		    cin.sync();
			break;
		}
	case 2:
		{
		    system("cls");
		    vector<Reader> Reader_vec;
            reader.ReadFileToReaderVector(Reader_vec);
            borrow.ReaderBorrow(Reader_vec);
            system("pause");
		    system("cls");
		    //清除缓存区
		    cin.clear();
		    cin.sync();
			break;
		}
	case 3:
		{
		    system("cls");
		    vector<Reader> Reader_vec;
            reader.ReadFileToReaderVector(Reader_vec);
		    borrow.ReaderReturn(Reader_vec);
            system("pause");
		    system("cls");
		    //清除缓存区
		    cin.clear();
		    cin.sync();
			break;
		}
	case 4:
		{
		    vector<Book> Book_vec;
            book.ReadFileToBookVector(Book_vec);
		    int num;
		    cout << "请输入查询方式（1.ISBN/2.书名/3.作者/4出版商）：";
		    cin.get();
		    cin >> num;
		    if (num == 1)
            {
                system("cls");
                book.FindBookByISBN(Book_vec);
                system("pause");
                system("cls");
                //清除缓存区
		    cin.clear();
		    cin.sync();
                break;
            }
            else if (num == 2)
            {
                system("cls");
                book.FindBookByTitle(Book_vec);
                system("pause");
                system("cls");
                //清除缓存区
		    cin.clear();
		    cin.sync();
                break;
            }
            else if (num == 3)
            {
                system("cls");
                vector<Reader> Reader_vec;
                book.FindBookByAuthor(Book_vec);
                system("pause");
                system("cls");
                //清除缓存区
		    cin.clear();
		    cin.sync();
                break;
            }
            else if (num == 4)
            {
                system("cls");
                book.FindBookByPublisher(Book_vec);
                system("pause");
                system("cls");
                //清除缓存区
		    cin.clear();
		    cin.sync();
                break;
            }
		}
	case 5:
		{
		    system("cls");
		    Catalog.CreatCatalogTree();
		    system("pause");
		    system("cls");
		    //清除缓存区
		    cin.clear();
		    cin.sync();
			break;
		}
	case 6:
		{
		    system("cls");
		    borrow.FindBorrow();
		    system("pause");
		    system("cls");
		    //清除缓存区
		    cin.clear();
		    cin.sync();
			break;
		}
	case 0:
		{
			system("cls");
			MainOfMenu();
			MainOfMenu_Choose();
			//清除缓存区
		    cin.clear();
		    cin.sync();
			break;
		}
	default :
		{
			cout << "您的选择出现错误，请重新输入！\n";
			system("pause");
			system("cls");
			//清除缓存区
		    cin.clear();
		    cin.sync();
		}
	}
}



/**************************************************************************
*函数名：    AccountOfMenu();
*函数功能：  打印账户管理子菜单，并调用函数AccountOfMenu_Choose();
*
*函数参数：  void
*函数返回值：void
**************************************************************************/
void Menu::AccountOfMenu()
{
    //设置字符串的背景颜色和字体颜色
    SetColor(0, 7);
    //设置字符串的缓冲区大小
    ConPrintAt(33, 3, " ★账户管理子菜单★ ", 20);

    SetColor(14, 8);
	cout << "\n\n\t\t=======================================================\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        1.注册账户                                 ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        2.修改密码                                 ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        3.修改账户                                 ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        4.查询账户                                 ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        5.删除账户                                 ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        0.返回上一级                               ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t=======================================================\n";
	AccountOfMenu_Choose();
}
/**************************************************************************
*函数名：    AccountOfMenu_Choose();
*函数功能：  对图书流通管理子菜单进行数字选择。
*            输入选项（0-5）
*            1.注册账户
*            2.修改密码
*            3.修改账户
*            4.查询账户
*            5.删除账户
*            0.返回上一级
*
*函数参数：  void
*函数返回值：void
**************************************************************************/
void Menu::AccountOfMenu_Choose()
{
    //创建一个账户对象 account
    Account account;
    //创建一个账户容器，命名为Account_vec
    vector<Account> Account_vec;
	cout << "请输入您的选择：";
	cin >> choose;

    switch(choose)
    {
    case 1:
        {
            system("cls");
            //注册信息
            account.Login(Account_vec);
            system("pause");
            system("cls");
            //清除缓存区
            cin.clear();
            cin.sync();
            break;
        }
    case 2:
        {
            system("cls");
            //从文件中读取账户信息到Account容器中
            account.ReadFileToAccountVector(Account_vec);
            //修改账户密码
            account.ChangePassword(Account_vec);
            system("pause");
            system("cls");
            //清除缓存区
            cin.clear();
            cin.sync();
            break;
        }
    case 3:
        {
            system("cls");
            //从文件中读取账户信息到Account容器中
            account.ReadFileToAccountVector(Account_vec);
            //修改账户信息
            account.ModifyAccount(Account_vec);
            system("pause");
            system("cls");
            //清除缓存区
            cin.clear();
            cin.sync();
            break;
        }
    case 4:
        {
            system("cls");
            //从文件中读取账户信息到Account容器中
            account.ReadFileToAccountVector(Account_vec);
            //查询账户信息
            account.FindAccount(Account_vec);
            system("pause");
            system("cls");
            //清除缓存区
            cin.clear();
            cin.sync();
            break;
        }
    case 5:
        {
            system("cls");
            //从文件中读取账户信息到Account容器中
            account.ReadFileToAccountVector(Account_vec);
            //删除账户信息
            account.DeleteAccount(Account_vec);
            system("pause");
            system("cls");
            //清除缓存区
            cin.clear();
            cin.sync();
            break;
        }
    case 0:
        {
            system("cls");
            //返回主菜单
            MainOfMenu();
            MainOfMenu_Choose();
            //清除缓存区
            cin.clear();
            cin.sync();
            break;
        }
    default :
        {
			cout << "您的选择出现错误，请重新输入！\n";
			system("pause");
			system("cls");
			//清除缓存区
            cin.clear();
            cin.sync();
        }
    }
}
