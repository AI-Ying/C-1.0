/******************************************************************
*
*Copyright(c)2015,�ϲ���ѧ���ѧԺʵ��С��(�Ż�������Ȼ�����¾�)
*All rights reserved.
*
*�ļ����ƣ� Reader.h
*�ļ���ʶ�� �����ù���ƻ���
*ժ    Ҫ��  ���ļ���Ҫ�Ƕ��������Reader,���Ը����������ҶԸ�����
*            �����ݳ�Ա�ͳ�Ա��������������
*
*
*��ǰ�汾��1.0
*���ߣ�����Ȼ
*������ڣ�2015/6/3
*��һ���޸ģ�2015/6/1
*�ڶ����޸ģ�2015/6/3
*
********************************************************************/

#ifndef  READER_H            //��ֹReader.h���ظ�����
#define  READER_H

#include "Main.h"            //�����Զ���ķǱ�׼�⺯��
#include <vector>            //���ñ�׼�⺯��
#include <algorithm>         //���ñ�׼�⺯��




/*************************************************************************************
*������      Reader
*
*���Ա���ԣ�protected
*���ݳ�Ա��
*            string Name;                    //����
*            string Sex;                     //�Ա�
*            string Code;                    //֤����
*            string Dept;                    //������λ
*            int Tag;                        //��ʧ״̬��0-������1-��ʧ��
*            int Number                      //���߽�������
*
*���Ա���ԣ�public
*��Ա������
*            string GetName();               //��������
*            string GetSex();                //�����Ա�
*            string GetCode();               //����֤����
*            string GetDept();               //���ع�����λ
*            int GetTag();                   //���ع�ʧ״̬
*            int GetNumber();                //���ؽ�������
*
*            string SetName(string name);    //�޸�����
*            string SetSex(string sex);      //�޸��Ա�
*            string SetCode(string code);    //�޸�֤����
*            string SetDept(string dept);    //�޸Ĺ�����λ
*            int SetTag(int tag);            //�޸Ĺ�ʧ״̬
*            int SetNumber(int number);      //�޸Ľ���ͼ�������
*
*            //�޲ι��캯��
*            Reader();
*            //���ι��캯��
*            Reader(string name, string sex, string code, string dept, int tag, int number);
*            //�������������Ϣ
*            void Print();
*            //���������Ϣ
*            void BrowseReader(vector<Reader> &Reader_vec);
*            //���Ӷ�����Ϣ
*            void AddReader(vector<Reader> &Reader_vec);
*            //����֤���Ų�ѯ������Ϣ
*            void FindReaderByCode(vector<Reader> &Reader_vec);
*            //����������ѯ������Ϣ
*            void FindReaderByName(vector<Reader> &Reader_vec);
*            //�޸Ķ�����Ϣ
*            void ModifyReader(vector<Reader> &Reader_vec);
*            //ɾ��������Ϣ
*            void DeleteReader(vector<Reader> &Reader_vec);
*            //֤����ʧ
*            void LostReader(vector<Reader> &Reader_vec);
*            //����д�ķ�ʽ���������Ϣ
*            void SaveReader(vector<Reader> &Reader_vec);
*            //��׷���ļ�β�ķ�ʽ���������Ϣ
*            void SaveReaderApp(vector<Reader> &Reader_vec);
*            //��ȡ�ļ���Ϣ��������
*            void ReadFileToReaderVector(vector<Reader> &Reader_vec);
*            //��������
*            ~Reader();
*
******************************************************************************************/
class Reader
{
protected:
    //����
    string Name;
    //�Ա�
    string Sex;
    //֤����
    string Code;
    //������λ
    string Dept;
    //��ʧ״̬��0-������1-��ʧ��
    int Tag;
    //��¼���߽�������
    int Number;
public:
    //��������
    string GetName();
    //�����Ա�
    string GetSex();
    //����֤����
    string GetCode();
    //���ع�����λ
    string GetDept();
    //���ع�ʧ״̬
    int GetTag();
    //���ؽ�������
    int GetNumber();

    //�޸�����
    string SetName(string name);
    //�޸��Ա�
    string SetSex(string sex);
    //�޸�֤����
    string SetCode(string code);
    //�޸Ĺ�����λ
    string SetDept(string dept);
    //�޸Ĺ�ʧ״̬
    int SetTag(int tag);
    //�޸Ľ���ͼ�������
    int SetNumber(int number);

    //�޲ι��캯��
    Reader();
    //���ι��캯��
    Reader(string name, string sex, string code, string dept, int tag, int number);
    //�������������Ϣ
    void Print();
    //���������Ϣ
    void BrowseReader(vector<Reader> &Reader_vec);
    //���Ӷ�����Ϣ
    void AddReader(vector<Reader> &Reader_vec);
    //����֤���Ų�ѯ������Ϣ
    void FindReaderByCode(vector<Reader> &Reader_vec);
    //����������ѯ������Ϣ
    void FindReaderByName(vector<Reader> &Reader_vec);
    //�޸Ķ�����Ϣ
    void ModifyReader(vector<Reader> &Reader_vec);
    //ɾ��������Ϣ
    void DeleteReader(vector<Reader> &Reader_vec);
    //֤����ʧ
    void LostReader(vector<Reader> &Reader_vec);
    //����д�ķ�ʽ���������Ϣ
    void SaveReader(vector<Reader> &Reader_vec);
    //��׷���ļ�β�ķ�ʽ���������Ϣ
    void SaveReaderApp(vector<Reader> &Reader_vec);
    //��ȡ�ļ���Ϣ��������
    void ReadFileToReaderVector(vector<Reader> &Reader_vec);
    //��������
    ~Reader();
};


#endif // READER_H
