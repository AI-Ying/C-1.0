/******************************************************************
*
*Copyright(c)2015,�ϲ���ѧ���ѧԺʵ��С��(�Ż�������Ȼ�����¾�)
*All rights reserved.
*
*�ļ����ƣ� Book.h
*�ļ���ʶ�� �����ù���ƻ���
*ժ    Ҫ��  ���ļ���Ҫ�Ƕ���ͼ����Book,���Ը����������ҶԸ����ڵ�
*            ���ݳ�Ա�ͳ�Ա��������������
*
*��ǰ�汾��1.0
*���ߣ��Ż�
*������ڣ�2015/6/5
*��һ���޸ģ�2015/6/8
*�ڶ����޸ģ�2015/6/16
*
********************************************************************/

#ifndef  BOOK_H            //��ֹBook.h���ظ�����
#define  BOOK_H

#include "Main.h"            //���÷Ǳ�׼�⺯��
#include <vector>            //���ñ�׼�⺯��
#include <algorithm>         //���ñ�׼�⺯��


/*************************************************************************************
*������      Book
*
*���Ա���ԣ�protected
*���ݳ�Ա��
*             string ISBN;            //ͼ��ISBN���
*             string Title;           //ͼ������
*             string Author;          //ͼ������
*             string Publisher;       //ͼ�������
*             string Date;            //ͼ���������
*             float  Price;           //ͼ��۸�
*             string CatalogNum;      //ͼ�������
*             int Number;             //ͼ�������
*
*
*���Ա���ԣ�public
*��Ա������
*             string GetISBN();                        //��ȡͼ��ISBN���
*             string GetTitle();                       //��ȡͼ������
*             string GetAuthor();                      //��ȡͼ������
*             string GetPublisher();                   //��ȡͼ�������
*             string GetDate();                        //��ȡͼ���������
*             float  GetPrice();                       //��ȡͼ��۸�
*             string GetCatalogNum();                  //��ȡͼ�������
*             int GetNumber();                         //��ȡͼ������
*             string SetISBN(string isbn);             //����ͼ��ISBN���
*             string SetTitle(string title);           //����ͼ������
*             string SetAuthor(string author);         //����ͼ������
*             string SetPublisher(string publisher);   //����ͼ�������
*             string SetDate(string date);             //����ͼ���������
*             float  SetPrice(float price);            //����ͼ��۸�
*             string SetCatalogNum(string catalognum); //����ͼ�������
*             int SetNumber(int number);               //����ͼ������
*
*             //�޲ι��캯��
*             Book();
*             //���ι��캯��
*             Book(string isbn, string title, string author, string publisher, string date, float price, string catalognum, int number);
*             //�������ͼ����Ϣ
*             void Print();
*             //���ͼ����Ϣ
*             void AddBook(vector<Book> &Book_vec);
*             //���ͼ����Ϣ
*             void BrowseBook(vector<Book> &Book_vec);
*             //�޸�ͼ����Ϣ
*             void ModifyBook(vector<Book> &Book_vec);
*             //ɾ��ͼ����Ϣ
*             void DeleteBook(vector<Book> &Book_vec);
*             //����ͼ��ISBN���������ͼ��
*             void FindBookByISBN(vector<Book> &Book_vec);
*             //����ͼ������������ͼ��
*             void FindBookByTitle(vector<Book> &Book_vec);
*             //����ͼ�������������ͼ��
*             void FindBookByPublisher(vector<Book> &Book_vec);
*             //����ͼ������������ͼ��
*             void FindBookByAuthor(vector<Book> &Book_vec);
*             //����д�ķ�ʽ����ͼ����Ϣ��book.txt�ļ���
*             void SaveBook(vector<Book> &Book_vec);
*             //��׷���ļ�β���ķ�ʽ����ͼ����Ϣ��book.txt�ļ���
*             void SaveBookApp(vector<Book> &Book_vec);
*             //��ȡͼ����Ϣ��Book����
*             void ReadFileToBookVector(vector<Book> &Book_vec);
*             //��������
*             ~Book();
******************************************************************************************/
class Book
{
protected:
    //ͼ��ISBN���
    string ISBN;
    //ͼ������
    string Title;
    //ͼ������
    string Author;
    //ͼ�������
    string Publisher;
    //ͼ���������
    string Date;
    //ͼ��۸�
    float  Price;
    //ͼ�������
    string CatalogNum;
    //ͼ�������
    int Number;
public:
    //��ȡͼ��ISBN���
    string GetISBN();
    //��ȡͼ������
    string GetTitle();
    //��ȡͼ������
    string GetAuthor();
    //��ȡͼ�������
    string GetPublisher();
    //��ȡͼ���������
    string GetDate();
    //��ȡͼ��۸�
    float  GetPrice();
    //��ȡͼ�������
    string GetCatalogNum();
    //��ȡͼ������
    int GetNumber();

    //����ͼ��ISBN���
    string SetISBN(string isbn);
    //����ͼ������
    string SetTitle(string title);
    //����ͼ������
    string SetAuthor(string author);
    //����ͼ�������
    string SetPublisher(string publisher);
    //����ͼ���������
    string SetDate(string date);
    //����ͼ��۸�
    float  SetPrice(float price);
    //����ͼ�������
    string SetCatalogNum(string catalognum);
    //����ͼ������
    int SetNumber(int number);

    //�޲ι��캯��
    Book();
    //���ι��캯��
    Book(string isbn, string title, string author, string publisher, string date, float price, string catalognum, int number);
    //�������ͼ����Ϣ
    void Print();
    //���ͼ����Ϣ
    void AddBook(vector<Book> &Book_vec);
    //���ͼ����Ϣ
    void BrowseBook(vector<Book> &Book_vec);
    //�޸�ͼ����Ϣ
    void ModifyBook(vector<Book> &Book_vec);
    //ɾ��ͼ����Ϣ
    void DeleteBook(vector<Book> &Book_vec);
    //����ͼ��ISBN���������ͼ��
    void FindBookByISBN(vector<Book> &Book_vec);
    //����ͼ������������ͼ��
    void FindBookByTitle(vector<Book> &Book_vec);
    //����ͼ�������������ͼ��
    void FindBookByPublisher(vector<Book> &Book_vec);
    //����ͼ������������ͼ��
    void FindBookByAuthor(vector<Book> &Book_vec);
    //����д�ķ�ʽ����ͼ����Ϣ��book.txt�ļ���
    void SaveBook(vector<Book> &Book_vec);
    //��׷���ļ�β���ķ�ʽ����ͼ����Ϣ��book.txt�ļ���
    void SaveBookApp(vector<Book> &Book_vec);
    //��ȡͼ����Ϣ��Book����
    void ReadFileToBookVector(vector<Book> &Book_vec);
    //��������
    ~Book();
};





#endif   //BOOK_H
