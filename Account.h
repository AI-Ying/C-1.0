/******************************************************************
*
*Copyright(c)2015,�ϲ���ѧ���ѧԺʵ��С��(�Ż�������Ȼ�����¾�)
*All rights reserved.
*
*�ļ����ƣ� Account.h
*�ļ���ʶ�� �����ù���ƻ���
*ժ    Ҫ��  ���ļ���Ҫ�Ƕ����˻���Account,���Ը����������ҶԸ����ڵ�
*            ���ݳ�Ա�ͳ�Ա��������������
*
*
*��ǰ�汾��1.0
*���ߣ��Ż�
*������ڣ�2015/6/8
*��һ���޸ģ�2015/6/8
*�ڶ����޸ģ�2015/6/16
*
********************************************************************/

#ifndef  ACCOUNT_H            //��ֹAccount.h���ظ�����
#define  ACCOUNT_H

#include "Main.h"             //���÷Ǳ�׼�⺯��
#include <vector>             //���ñ�׼�⺯��
#include <algorithm>          //���ñ�׼�⺯��

/*************************************************************************************
*������      Book
*
*���Ա���ԣ�protected
*���ݳ�Ա��
*             string UserName;        //����Ա�û���
*             string Name;            //����Ա����
*             string ID;              //����Ա����
*             string Password;        //����Ա����
*
*
*���Ա���ԣ�public
*��Ա������
*
*             string GetUserName();                 //��ȡ����Ա�û���
*             string GetName();                     //��ȡ����Ա����
*             string GetID();                       //��ȡ����ԱID��
*             string GetPassword();                 //��ȡ����Ա����
*             string SetUserName(string username);  //���ù���Ա�û���
*             string SetName(string name);          //���ù���Ա����
*             string SetID(string id);              //���ù���ԱID��
*             string SetPassword(string password);  //��������
*             //�޲ι��캯��
*             Account();
*             //���ι��캯��
*             Account(string username, string name, string id, string password);
*             //�����������Ա��Ϣ
*             void Print();
*             //ע���˻�
*             void Login(vector<Account> &Account_vec);
*             //�޸�����
*             void ChangePassword(vector<Account> &Account_vec);
*             //ɾ���˻�
*             void DeleteAccount(vector<Account> &Account_vec);
*             //�����˻�
*             void FindAccount(vector<Account> &Account_vec);
*             //�޸��˻�
*             void ModifyAccount(vector<Account> &Account_vec);
*             //��ȡ����Ա�ʻ���Ϣ��Account����
*             void ReadFileToAccountVector(vector<Account> &Account_vec);
*             //����д�ķ�ʽ�������Ա��Ϣ��Account.txt��
*             void SaveAccount(vector<Account> &Account_vec);
*             //��׷�ӵ��ļ�β���ķ�ʽ�������Ա��Ϣ��Account.txt��
*             void SaveAccountApp(vector<Account> &Account_vec);
*             //��������
*             ~Account();
******************************************************************************************/
class Account
{
protected:
    //����Ա�û���
    string UserName;
    //����Ա����
    string Name;
    //����Ա����
    string ID;
    //����Ա����
    string Password;
public:
    //��ȡ����Ա�û���
    string GetUserName();
    //��ȡ����Ա����
    string GetName();
    //��ȡ����ԱID��
    string GetID();
    //��ȡ����Ա����
    string GetPassword();

    //���ù���Ա�û���
    string SetUserName(string username);
    //���ù���Ա����
    string SetName(string name);
    //���ù���ԱID��
    string SetID(string id);
    //��������
    string SetPassword(string password);

    //�޲ι��캯��
    Account();
    //���ι��캯��
    Account(string username, string name, string id, string password);
    //�����������Ա��Ϣ
    void Print();
    //ע���˻�
    void Login(vector<Account> &Account_vec);
    //�޸�����
    void ChangePassword(vector<Account> &Account_vec);
    //ɾ���˻�
    void DeleteAccount(vector<Account> &Account_vec);
    //�����˻�
    void FindAccount(vector<Account> &Account_vec);
    //�޸��˻�
    void ModifyAccount(vector<Account> &Account_vec);
    //��ȡ����Ա�ʻ���Ϣ��Account����
    void ReadFileToAccountVector(vector<Account> &Account_vec);
    //����д�ķ�ʽ�������Ա��Ϣ��Account.txt��
    void SaveAccount(vector<Account> &Account_vec);
    //��׷�ӵ��ļ�β���ķ�ʽ�������Ա��Ϣ��Account.txt��
    void SaveAccountApp(vector<Account> &Account_vec);
    //��������
    ~Account();
};



#endif  //ACCOUNT_H
