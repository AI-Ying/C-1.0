/******************************************************************
*
*Copyright(c)2015,�ϲ���ѧ���ѧԺʵ��С��(�Ż�������Ȼ�����¾�)
*All rights reserved.
*
*�ļ����ƣ� Circulate.h
*�ļ���ʶ�� �����ù���ƻ���
*ժ    Ҫ��  ���ļ�����Ҫ����ͼ����ͨ�Ĺ��ܺ������������Լ���
*            ���߽�����ϢBorrowLink�ṹ�壬����Date�ṹ���������
*            ����ͼ����ͨCirculate�࣬����Circulate������������
*
*
*��ǰ�汾��1.0
*���ߣ����¾�
*������ڣ�2015/6/10
*��һ���޸ģ�2015/6/14
*�ڶ����޸ģ�2015/6/20
*
********************************************************************/

#ifndef   CIRCULATE_H             //��ֹCirculate.h���ظ�����
#define   CIRCULATE_H


#include "Main.h"                 //���÷Ǳ�׼�⺯��
#include "Reader.h"               //���÷Ǳ�׼�⺯��
#include "Book.h"                 //���÷Ǳ�׼�⺯��
#define  MAX_BOOK   6             //�������ֻ�ܽ���6����
#define  MAX_DAY    60            //����һ�ν��������




/*********************************************************************
*�ṹ�����ƣ�Date
*
*�ṹ���Ա���ԣ�public
*���ݳ�Ա��
*                 int Year;      //��
*                 int Month;     //��
*                 int Day;       //��
**********************************************************************/
typedef struct Date
{
public:
    //��
    int Year;
    //��
    int Month;
    //��
    int Day;
}Date;



/******************************************************************
*�ṹ������BorrowLink
*
*�ṹ���Ա���ԣ�public
*���ݳ�Ա��
*        string Code;         //����֤����
*        string ISBN;         //��������ͼ���ISBN��
*        Date BorrowDate;     //���߽�������
*        Date LastDate;       //����Ӧ������
*        Date ReturnDate;     //����ʵ�ʻ�������
*        string Tag;          //���߽��顢����״̬��������黹��
*
*        struct BorrowLink *next;  //����һ���ṹ��ָ��
********************************************************************/
typedef struct BorrowLink
{
public:
    //����֤����
	string Code;
	//��������ͼ���ISBN��
	string ISBN;
	//���߽�������
	Date BorrowDate;
	//����Ӧ������
	Date LastDate;
	//����ʵ�ʻ�������
	Date ReturnDate;
    //���߽��顢����״̬
    //������黹
	string Tag;

    //����һ���ṹ��ָ��
	struct BorrowLink *next;
}BorrowLink;


/*************************************************************************************
*������      Book
*
*���Ա���ԣ�protected
*���ݳ�Ա��
*             struct BorrowLink L;     //���߽�����Ϣ�ṹ��
*             struct Date D;           //���ڽṹ��
*
*
*���Ա���ԣ�public
*��Ա������
*             //�������߽�����Ϣ����
*             BorrowLink *CreatBorrowLink();
*             //������ĵĶ�����Ϣ��Ϣ
*             void SaveBorrowB(string Code, string ISBN);
*             //������߻������Ϣ
*             void SaveBorrowR(string Code, string ISBN);
*             //��ѯ���߽�����Ϣ
*             void FindBorrow();
*             //�ͷ������ڴ�
*             void DeleteMemory(BorrowLink *head);
*             //���߽���
*             void ReaderBorrow(vector<Reader> &Reader_vec);
*             //���߻���
*             void ReaderReturn(vector<Reader> &Reader_vec);
******************************************************************************************/
class Circulate
{
private:
    //���߽��Ľṹ��
    struct BorrowLink L;
    //���ڽṹ��
    struct Date D;
public:
    //�������߽�����Ϣ����
    BorrowLink *CreatBorrowLink();
    //������ĵĶ�����Ϣ��Ϣ
    void SaveBorrowB(string Code, string ISBN);
    //������߻������Ϣ
    void SaveBorrowR(string Code, string ISBN);
    //��ѯ���߽�����Ϣ
    void FindBorrow();
    //�ͷ������ڴ�
    void DeleteMemory(BorrowLink *head);
    //���߽���
    void ReaderBorrow(vector<Reader> &Reader_vec);
    //���߻���
    void ReaderReturn(vector<Reader> &Reader_vec);
};




#endif // CIRCULATE_H

