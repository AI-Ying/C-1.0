
/********************************************************************************
*
*Copyright(c)2015,�ϲ���ѧ���ѧԺʵ��С��(�Ż�������Ȼ�����¾�)
*All rights reserved.
*
*�ļ����ƣ� Menu.cpp
*�ļ���ʶ�� �����ù���ƻ���
*
*ժ    Ҫ�� ���ļ���Ҫ����ͼ�����ϵͳ�����漰�Ĳ˵���
*           ͼ�������ڲ˵���  InterfaceOfMenu();
*           ͼ��������˵�������MainofMenu(),MainOfMenu_Choose();
*           ���߹����Ӳ˵�������ReaderOfMenu(),ReaderOfMenu_Choose();
*           ͼ������Ӳ˵�������CatalogOfMenu(),CatalogOfMenu_Choose();
*           ��Ŀ�����Ӳ˵�������BookOfMenu(), BookOfMenu_Choose();
*           ͼ����ͨ�Ӳ˵�������CirculationOfMenu(),CirculationOfMenu_Choose();
*
*
*��ǰ�汾��1.0
*���ߣ�����Ȼ
*������ڣ�2015/5/27
*��һ���޸ģ�2015/6/1
*�ڶ����޸ģ�2015/6/3
*
**********************************************************************************/



#include "Main.h"             //���÷Ǳ�׼�⺯��
#include "Menu.h"             //���÷Ǳ�׼�⺯��
#include "Reader.h"           //���÷Ǳ�׼�⺯��
#include "Book.h"             //���÷Ǳ�׼�⺯��
#include "Account.h"          //���÷Ǳ�׼�⺯��
#include "Catalog.h"          //���÷Ǳ�׼�⺯��
#include "Circulate.h"        //���÷Ǳ�׼�⺯��
#include "Color.h"            //���÷Ǳ�׼�⺯��



void Menu::InterfaceOfMenu()
{
    //���õ�ǰ���ڵ�����ͱ�����ɫ
    system("color 5b");

    //��ȡϵͳ��ǰʱ��
    time_t curtime = time(NULL);
    //����һ��ʱ��ṹ��
    tm last;
    //��ϵͳʱ��ת��Ϊ����ʱ��
    last =*localtime(&curtime);
    int day,mon,year, hour, minute, second;
    day  = last.tm_mday;
    mon  = last.tm_mon + 1;
    year = last.tm_year + 1900;
    hour = last.tm_hour;
    minute = last.tm_min;
    second = last.tm_sec;


    cout << "\n\n\n\t\t-------------------------------------------------------\n" << endl;
	cout << "\t\t           ��ӭ�����ϲ���ѧͼ��ݹ���ϵͳ              \n" << endl;
	cout << "\t\t-------------------------------------------------------\n" << endl;
    cout << "\n\t\t\t �� ���T�T�T�T�ԨT�T�T�T�� ��"     << endl;
    cout << "\t\t\t    �U�m�m�m�m���m�m�m�m�U  "  << endl;
    cout << "\t\t\t �� �U�m�m    ���m�m�m  �U ��" << endl;
    cout << "\t\t\t    �U�m�m�m�m���m�m�m�m�U "   << endl;
    cout << "\t\t\t �� �U�m�m�u�v���m�m    �U ��" << endl;
    cout << "\t\t\t    �U�m�m���u���m�m�m�m�U"    << endl;
    cout << "\t\t\t �� ���T�T�T�T�ܨT�T�T�T�� ��\n"     << endl;
    cout << "\n\n\t\t\t\t\t\t��142��"         << endl;
    cout << "\t\t\t\t\t\t�Ż�������Ȼ�����¾�\n"<< endl;
	cout << "\t\t-------------------------------------------------------" << endl;
	cout << "\t\t��ܰ��ʾ��\t\t\t";
    cout << year << "��" << mon << "��" << day << "��" << hour << ":" << minute << ":" << second << endl;
    cout << "\t\t-------------------------------------------------------\n\n\n" << endl;

    system("pause");
    system("cls");

    MainOfMenu();
}



/************************************************************************
*��������    MainOfMenu()
*�������ܣ�  ��ӡͼ��������˵���������MainOfMenu_Choose()���������
*
*����������  void
*��������ֵ��void
*************************************************************************/
void Menu::MainOfMenu(void)
{
    //���õ�ǰ��������ɫ
    system("color 87");
    //�����ַ����ı�����ɫ��������ɫ
    SetColor(9, 14);
    //�����ַ����Ļ�������С
    ConPrintAt(32, 3, " ��ͼ�����ϵͳ���˵��� ", 24);

    SetColor(11,8);
	cout << "\n\n\t\t=======================================================\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==         1.���߹���                                ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==         2.ͼ���Ŀ����                            ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==         3.ͼ��������                            ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==         4.ͼ����ͨ����                            ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==         5.�˻�����                                ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==         0.�˳�                                    ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t=======================================================\n";

	MainOfMenu_Choose();
}


/*************************************************************************
*��������    MainOfMenu_Choose()
*�������ܣ�  ��ͼ�����ϵͳ���˵���������ѡ��
*            ����ѡ�0-5����
*            1.���߹���
*            2.ͼ��������
*            3.ͼ���Ŀ����
*            4.ͼ����ͨ����
*            5.�˻�����
*            0.�˳�
*
*����������  void
*��������ֵ��void
*************************************************************************/
void Menu::MainOfMenu_Choose()
{
    cout << "����������ѡ��";
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
            cout << "����ѡ����ִ������������룡\n";
            system("pause");
            system("cls");
        }
    }
}


/*************************************************************************
*��������    ReaderOfMenu();
*�������ܣ�  ��ӡ���߹����Ӳ˵���������ReaderOfMenu_Choose()���������
*
*����������  void
*��������ֵ��void
*************************************************************************/
void Menu::ReaderOfMenu()
{
    //�����ַ����ı�����ɫ��������ɫ
    SetColor(1, 10);
    //�����ַ����Ļ�������С
    ConPrintAt(33, 3, " ����߹����Ӳ˵��� ", 20);

    SetColor(14, 8);
	cout << "\n\n\t\t=======================================================\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        1.������ж�����Ϣ                         ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        2.���Ӷ�����Ϣ                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        3.��ѯ������Ϣ                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        4.�޸Ķ�����Ϣ                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        5.ɾ��������Ϣ                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        6.֤����ʧ                                 ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        0.������һ��                               ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t=======================================================\n";

	ReaderOfMenu_Choose();
}
/**************************************************************************
*��������    ReaderOfMenu_Choose();
*�������ܣ�  �Զ��߹����Ӳ˵���������ѡ��
*            ����ѡ�0-6����
*            1.������ж�����Ϣ
*            2.���Ӷ�����Ϣ
*            3.��ѯ������Ϣ
*            4.�޸Ķ�����Ϣ
*            5.ɾ��������Ϣ
*            6.֤����ʧ
*            0.������һ��
*
*����������  void
*��������ֵ��void
**************************************************************************/
void Menu::ReaderOfMenu_Choose()
{
    //����Reader��һ������ reader.
    Reader reader;
    //����Reader������������ΪReader_vec
    vector <Reader> Reader_vec;

	cout << "����������ѡ��";
	cin >> choose;
    switch(choose)
	{
	case 1:
		{
		    system("cls");
		    //Ԥ�ȶ�ȡ������Ϣ��Reader������
            reader.ReadFileToReaderVector(Reader_vec);
            //���������Ϣ
		    reader.BrowseReader(Reader_vec);
		    system("pause");
		    system("cls");
		    //���������
		    cin.clear();
		    cin.sync();
			break;
		}
	case 2:
		{
		    system("cls");
		    //��Ӷ�����Ϣ
		    reader.AddReader(Reader_vec);
            system("pause");
            system("cls");
            //���������
		    cin.clear();
		    cin.sync();
			break;
		}
	case 3:
		{
            //Ԥ�ȶ�ȡ������Ϣ��Reader������
            reader.ReadFileToReaderVector(Reader_vec);
            system("cls");
		    int ch;
		    cout << "\n\n\t��ѡ���ѯ��ʽ��1.����/2.֤���ţ���";
		    cin.get();
		    cin >> ch;
		    if (ch == 1)
            {
                system("cls");
                //ͨ�����ߵ��������Ҷ�����Ϣ
                reader.FindReaderByName(Reader_vec);
                system("pause");
                system("cls");
                //���������
                cin.clear();
                cin.sync();
                break;
            }
            else if (ch == 2)
            {
                system("cls");
                //ͨ������֤���Ų��Ҷ�����Ϣ
                reader.FindReaderByCode(Reader_vec);
                system("pause");
                system("cls");
                //���������
                cin.clear();
                cin.sync();
                break;
            }

		}
	case 4:
		{
            system("cls");
            //Ԥ�ȶ�ȡ������Ϣ��Reader������
            reader.ReadFileToReaderVector(Reader_vec);
            //�޸Ķ�����Ϣ
            reader.ModifyReader(Reader_vec);
            system("pause");
            system("cls");
            //���������
		    cin.clear();
		    cin.sync();
			break;
		}
	case 5:
		{
		    system("cls");
            //Ԥ�ȶ�ȡ������Ϣ��Reader������
            reader.ReadFileToReaderVector(Reader_vec);
            //ɾ��������Ϣ
            reader.DeleteReader(Reader_vec);
            system("pause");
            system("cls");
            //���������
		    cin.clear();
		    cin.sync();
			break;
		}
	case 6:
		{   system("cls");
            //Ԥ�ȶ�ȡ������Ϣ��Reader������
            reader.ReadFileToReaderVector(Reader_vec);
            //������Ϣ��ʧ
            reader.LostReader(Reader_vec);
            system("pause");
            system("cls");
            //���������
		    cin.clear();
		    cin.sync();
			break;
		}
	case 0:
		{
			system("cls");
			//�������˵�
			MainOfMenu();
			system("cls");
			//���������
		    cin.clear();
		    cin.sync();
			break;
		}
	default :
		{
			cout << "����ѡ����ִ������������룡\n";
			system("pause");
			system("cls");
			//���������
		    cin.clear();
		    cin.sync();
		}
	}
}



/**************************************************************************
*��������    BookOfMenu();
*�������ܣ�  ��ӡͼ���Ŀ�����Ӳ˵��������ú���BookOfMenu_Choose();
*
*����������  void
*��������ֵ��void
**************************************************************************/
void Menu::BookOfMenu()
{
    //�����ַ����ı�����ɫ��������ɫ
    SetColor(2, 11);
    //�����ַ����Ļ�������С
    ConPrintAt(33, 3, " ���Ŀ�����Ӳ˵��� ", 20);

    SetColor(14, 8);
	cout << "\n\n\t\t=======================================================\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        1.����¼��                                 ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        2.���ͼ����Ϣ                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        3.�޸�ͼ����Ϣ                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        4.ɾ��ͼ����Ϣ                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        5.��ѯͼ����Ϣ                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        0.������һ��                               ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t=======================================================\n";
	BookOfMenu_Choose();
}
/**************************************************************************
*��������    BookOfMenu_Choose();
*�������ܣ�  ��ͼ���Ŀ�����Ӳ˵���������ѡ��
*            ����ѡ�0-5��
*            1.����¼��
*            2.���ͼ����Ϣ
*            3.�޸�ͼ����Ϣ
*            4.ɾ��ͼ����Ϣ
*            5.��ѯͼ����Ϣ
*            0.������һ��
*
*����������  void
*��������ֵ��void
**************************************************************************/
void Menu::BookOfMenu_Choose()
{
    //����һ��ͼ�����
    Book book;
    //����Book������������ΪBook_vec
    vector<Book> Book_vec;

    cout << "����������ѡ��";
    cin >> choose;
	switch(choose)
	{
	case 1:
		{
		    system("cls");
		    //���ͼ����Ϣ
		    book.AddBook(Book_vec);
		    system("pause");
		    system("cls");
		    //���������
		    cin.clear();
		    cin.sync();
			break;
		}
	case 2:
		{
            system("cls");
            //���ļ���ȡͼ�����ݵ�Book������
            book.ReadFileToBookVector(Book_vec);
            //���ͼ����Ϣ
		    book.BrowseBook(Book_vec);
		    system("pause");
		    system("cls");
		    //���������
		    cin.clear();
		    cin.sync();
			break;
		}
	case 3:
		{
		    system("cls");
		    //���ļ���ȡͼ�����ݵ�Book������
            book.ReadFileToBookVector(Book_vec);
            //�޸�ͼ����Ϣ
		    book.ModifyBook(Book_vec);
		    system("pause");
		    system("cls");
		    //���������
		    cin.clear();
		    cin.sync();
			break;
		}
	case 4:
		{
		    system("cls");
		    //���ļ���ȡͼ�����ݵ�Book������
            book.ReadFileToBookVector(Book_vec);
		    book.DeleteBook(Book_vec);
		    system("pause");
		    system("cls");
		    //���������
		    cin.clear();
		    cin.sync();
			break;
		}
	case 5:
		{
		    //���ļ���ȡͼ�����ݵ�Book������
            book.ReadFileToBookVector(Book_vec);
		    int num;
		    cout << "�������ѯ��ʽ��1.ISBN/2.����/3.����/4�����̣���";
		    cin.get();
		    cin >> num;
		    if (num == 1)
            {
                system("cls");
                //����ͼ���ISBN�������ѯͼ����Ϣ
                book.FindBookByISBN(Book_vec);
                system("pause");
                system("cls");
                //���������
                cin.clear();
                cin.sync();
                break;
            }
            else if (num == 2)
            {
                system("cls");
                //����ͼ�����������ѯͼ����Ϣ
                book.FindBookByTitle(Book_vec);
                system("pause");
                system("cls");
                //���������
                cin.clear();
                cin.sync();
                break;
            }
            else if (num == 3)
            {
                system("cls");
                //����ͼ�����������ѯͼ����Ϣ
                book.FindBookByAuthor(Book_vec);
                system("pause");
                system("cls");
                //���������
                cin.clear();
                cin.sync();
                break;
            }
            else if (num == 4)
            {
                system("cls");
                //����ͼ��ĳ���������ѯͼ����Ϣ
                book.FindBookByPublisher(Book_vec);
                system("pause");
                system("cls");
                //���������
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
			//�������˵�
			MainOfMenu_Choose();
			//���������
		    cin.clear();
		    cin.sync();
			break;
		}
	default :
		{
			cout << "����ѡ����ִ������������룡\n";
			system("pause");
			system("cls");
			//���������
		    cin.clear();
		    cin.sync();
		}
	}
}



/**************************************************************************
*��������    CatalogOfMenu();
*�������ܣ�  ���ͼ���������Ӳ˵���������CatalogOfMenu_Choose();
*
*����������  void
*��������ֵ��void
**************************************************************************/
void Menu::CatalogOfMenu()
{
    //�����ַ����ı�����ɫ��������ɫ
    SetColor(2, 13);
    //�����ַ����Ļ�������С
    ConPrintAt(32, 3, " �����Ŀ¼�����Ӳ˵��� ", 24);

    SetColor(14, 8);
	cout << "\n\n\t\t=======================================================\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        1.���ͼ�����                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        2.����ͼ�����                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        3.ɾ��ͼ�����                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        4.�޸�ͼ�����                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        5.��ѯͼ�����                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        6.������η�����                           ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        0.������һ��                               ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t=======================================================\n";
	CatalogOfMenu_Choose();
}
/**************************************************************************
*��������    CatalogOfMenu_Choose();
*�������ܣ�  ��ͼ���������Ӳ˵���������ѡ��
*            ����ѡ�0-5��
*            1.���ͼ�����
*            2.����ͼ�����
*            3.ɾ��ͼ�����
*            4.�޸�ͼ�����
*            5.��ѯͼ�����
*            6.������η�����
*            0.������һ��
*
*����������  void
*��������ֵ��void
**************************************************************************/
void Menu::CatalogOfMenu_Choose()
{
    Catalog catalog;
    cout << "����������ѡ��";
	cin >> choose;

	switch(choose)
	{
        case 1:
        {
            system("cls");
            catalog.PrintCatalog();
		    system("pause");
		    system("cls");
		    //���������
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
		    //���������
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
		    //���������
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
		    //���������
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
		    //���������
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
		    //���������
		    cin.clear();
		    cin.sync();
            break;
        }
        case 0:
        {
            system("cls");
            MainOfMenu();
            MainOfMenu_Choose();
            //���������
		    cin.clear();
		    cin.sync();
            break;
        }
        default :
        {
            cout << "����ѡ����ִ������������룡\n";
            system("pause");
            system("cls");
            //���������
		    cin.clear();
		    cin.sync();
        }
	}
}



/**************************************************************************
*��������    CirculationOfMenu();
*�������ܣ�  ��ӡͼ����ͨ�����Ӳ˵��������ú���CirculationOfMenu_Choose();
*
*����������  void
*��������ֵ��void
**************************************************************************/
void Menu::CirculationOfMenu()
{
    //�����ַ����ı�����ɫ��������ɫ
    SetColor(2, 12);
    //�����ַ����Ļ�������С
    ConPrintAt(32, 3, " ��ͼ����ͨ�����Ӳ˵��� ", 24);

    SetColor(14, 8);
	cout << "\n\n\t\t=======================================================\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        1.���ͼ��                                 ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        2.����                                     ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        3.����                                     ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        4.ͼ�����                                 ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        5.ͼ��������                             ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        6.��ѯͼ����ļ�¼                         ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        0.������һ��                               ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t=======================================================\n";

	CirculationOfMenu_Choose();
}
/**************************************************************************
*��������    CirculationOfMenu_Choose();
*�������ܣ�  ��ͼ����ͨ�����Ӳ˵���������ѡ��
*            ����ѡ�0-7��
*            1.���ͼ��
*            2.����
*            3.����
*            4.����
*            5.ͼ�����
*            6.ͼ��������
*            7.��ѯͼ����ļ�¼
*            0.������һ��
*
*����������  void
*��������ֵ��void
**************************************************************************/
void Menu::CirculationOfMenu_Choose()
{
    //����һ������ͼ��Ķ���
	Catalog Catalog;
	Circulate borrow;
	Reader reader;
	Book book;

	cout << "����������ѡ��";
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
		    //���������
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
		    //���������
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
		    //���������
		    cin.clear();
		    cin.sync();
			break;
		}
	case 4:
		{
		    vector<Book> Book_vec;
            book.ReadFileToBookVector(Book_vec);
		    int num;
		    cout << "�������ѯ��ʽ��1.ISBN/2.����/3.����/4�����̣���";
		    cin.get();
		    cin >> num;
		    if (num == 1)
            {
                system("cls");
                book.FindBookByISBN(Book_vec);
                system("pause");
                system("cls");
                //���������
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
                //���������
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
                //���������
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
                //���������
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
		    //���������
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
		    //���������
		    cin.clear();
		    cin.sync();
			break;
		}
	case 0:
		{
			system("cls");
			MainOfMenu();
			MainOfMenu_Choose();
			//���������
		    cin.clear();
		    cin.sync();
			break;
		}
	default :
		{
			cout << "����ѡ����ִ������������룡\n";
			system("pause");
			system("cls");
			//���������
		    cin.clear();
		    cin.sync();
		}
	}
}



/**************************************************************************
*��������    AccountOfMenu();
*�������ܣ�  ��ӡ�˻������Ӳ˵��������ú���AccountOfMenu_Choose();
*
*����������  void
*��������ֵ��void
**************************************************************************/
void Menu::AccountOfMenu()
{
    //�����ַ����ı�����ɫ��������ɫ
    SetColor(0, 7);
    //�����ַ����Ļ�������С
    ConPrintAt(33, 3, " ���˻������Ӳ˵��� ", 20);

    SetColor(14, 8);
	cout << "\n\n\t\t=======================================================\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        1.ע���˻�                                 ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        2.�޸�����                                 ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        3.�޸��˻�                                 ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        4.��ѯ�˻�                                 ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        5.ɾ���˻�                                 ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t==        0.������һ��                               ==\n";
	cout << "\t\t==                                                   ==\n";
	cout << "\t\t=======================================================\n";
	AccountOfMenu_Choose();
}
/**************************************************************************
*��������    AccountOfMenu_Choose();
*�������ܣ�  ��ͼ����ͨ�����Ӳ˵���������ѡ��
*            ����ѡ�0-5��
*            1.ע���˻�
*            2.�޸�����
*            3.�޸��˻�
*            4.��ѯ�˻�
*            5.ɾ���˻�
*            0.������һ��
*
*����������  void
*��������ֵ��void
**************************************************************************/
void Menu::AccountOfMenu_Choose()
{
    //����һ���˻����� account
    Account account;
    //����һ���˻�����������ΪAccount_vec
    vector<Account> Account_vec;
	cout << "����������ѡ��";
	cin >> choose;

    switch(choose)
    {
    case 1:
        {
            system("cls");
            //ע����Ϣ
            account.Login(Account_vec);
            system("pause");
            system("cls");
            //���������
            cin.clear();
            cin.sync();
            break;
        }
    case 2:
        {
            system("cls");
            //���ļ��ж�ȡ�˻���Ϣ��Account������
            account.ReadFileToAccountVector(Account_vec);
            //�޸��˻�����
            account.ChangePassword(Account_vec);
            system("pause");
            system("cls");
            //���������
            cin.clear();
            cin.sync();
            break;
        }
    case 3:
        {
            system("cls");
            //���ļ��ж�ȡ�˻���Ϣ��Account������
            account.ReadFileToAccountVector(Account_vec);
            //�޸��˻���Ϣ
            account.ModifyAccount(Account_vec);
            system("pause");
            system("cls");
            //���������
            cin.clear();
            cin.sync();
            break;
        }
    case 4:
        {
            system("cls");
            //���ļ��ж�ȡ�˻���Ϣ��Account������
            account.ReadFileToAccountVector(Account_vec);
            //��ѯ�˻���Ϣ
            account.FindAccount(Account_vec);
            system("pause");
            system("cls");
            //���������
            cin.clear();
            cin.sync();
            break;
        }
    case 5:
        {
            system("cls");
            //���ļ��ж�ȡ�˻���Ϣ��Account������
            account.ReadFileToAccountVector(Account_vec);
            //ɾ���˻���Ϣ
            account.DeleteAccount(Account_vec);
            system("pause");
            system("cls");
            //���������
            cin.clear();
            cin.sync();
            break;
        }
    case 0:
        {
            system("cls");
            //�������˵�
            MainOfMenu();
            MainOfMenu_Choose();
            //���������
            cin.clear();
            cin.sync();
            break;
        }
    default :
        {
			cout << "����ѡ����ִ������������룡\n";
			system("pause");
			system("cls");
			//���������
            cin.clear();
            cin.sync();
        }
    }
}
