/********************************************************************************
*
*Copyright(c)2015,�ϲ���ѧ���ѧԺʵ��С��(�Ż�������Ȼ�����¾�)
*All rights reserved.
*
*�ļ����ƣ� Book.cpp
*�ļ���ʶ�� �����ù���ƻ���
*
*ժ    Ҫ��  ���ļ���Ҫ�Ƕ��˻������ܺ�����ʵ�֡��ڶԹ���Ա�˻�������
*            ���в���ʱ��ʹ������������vector�������������ڸ�������֮
*            ��ĵ��ã�Ҳ��������⡣
*
*
*��ǰ�汾��1.0
*���ߣ��Ż�
*������ڣ�2015/6/5
*��һ���޸ģ�2015/6/8
*�ڶ����޸ģ�2015/6/16
*
**********************************************************************************/

#include  "Account.h"         //���÷Ǳ�׼�⺯��





/***************************************************
*��������    Account()
*�������ܣ�  ��������û�г�ʼ���������޲ι��캯��
*
*����������  ��
***************************************************/
Account::Account()
{
}



/**************************************************
*��������    Account()
*�������ܣ�  ���캯�����Զ�����г�ʼ����
*
*
*��������:
*            string username       //����Ա�û���
*            string name           //����Ա����
*            string id             //����ԱID
*            string password       //����Ա����
****************************************************/
Account::Account(string username, string name, string id, string password)
{
    this->UserName = username;
    this->Name = name;
    this->ID = id;
    this->Password = password;
}



/*********************************************************
*��������   GetUserName()
*�������ܣ� ��ȡ����Ա�û���
*
*����������  void
*��������ֵ��UserName
**********************************************************/
string Account::GetUserName()
{
    return UserName;
}
/*********************************************************
*��������    SetUserName()
*�������ܣ�  �Թ���Ա�û��������޸�
*
*����������  string username    //����Ա�û���
*��������ֵ: UserName
*********************************************************/
string Account::SetUserName(string username)
{
    this->UserName = username;
    return UserName;
}



/*********************************************************
*��������   GetName()
*�������ܣ� ��ȡ����Ա����
*
*����������  void
*��������ֵ��Name
**********************************************************/
string Account::GetName()
{
    return Name;
}
/*********************************************************
*��������    SetName()
*�������ܣ�  �Թ���Ա���������޸�
*
*����������  string name    //����Ա����
*��������ֵ: Name
*********************************************************/
string Account::SetName(string name)
{
    this->Name = name;
    return Name;
}



/*********************************************************
*��������   GetID()
*�������ܣ� ��ȡ����ԱID��
*
*����������  void
*��������ֵ��ID
**********************************************************/
string Account::GetID()
{
    return ID;
}
/*********************************************************
*��������    SetID()
*�������ܣ�  �Թ���ԱID�Ž����޸�
*
*����������  string id    //����ԱID��
*��������ֵ: ID
*********************************************************/
string Account::SetID(string id)
{
    this->ID = id;
    return ID;
}



/*********************************************************
*��������   GetPassword()
*�������ܣ� ��ȡ����Ա����
*
*����������  void
*��������ֵ��Password
**********************************************************/
string Account::GetPassword()
{
    return Password;
}
/*********************************************************
*��������    SetPassword()
*�������ܣ�  �Թ���Ա��������޸�
*
*����������  string password    //����Ա����
*��������ֵ: Password
*********************************************************/
string Account::SetPassword(string password)
{
    this->Password = password;
    return Password;
}



/*********************************************************
*��������    Print()
*�������ܣ�  ���뵥���˻���ȫ����Ϣ
*
*����������  void
*��������ֵ��void
*********************************************************/
void Account::Print()
{
    cout << GetUserName() << '\t' << GetName() << '\t';
    cout << GetID() << '\t' << GetPassword() << endl;
}



/********************************************************************
*��������    Login()
*�������ܣ�  ����Ա�˻�ע��
*
*����������  Account������Ϊ����������vector<Account> &Account_vec
*
*��������ֵ��void
*********************************************************************/
void Account::Login(vector<Account> &Account_vec)
{
    cout << "\n\n\t\tע���˻�\n\n" << endl;
    //����Ա�û���
    string username;
    //����Ա����
    string name;
    //����Ա����
    string id;
    //����Ա����
    string password;
    //ȷ������
    string Confirmpassword;
    //��־����
    int flag = 0;

    cout << "ע����Ϣ��\n";
    cout << "�������û�����";
    cin  >> username;
    cout << "������������";
    cin  >> name;
    cout << "������ID��";
    cin  >> id;
    cout << "���������룺";
    cin  >> password;
    cout << "��ȷ�����룺";
    cin  >> Confirmpassword;

    if (password.compare(Confirmpassword) == 0)
    {
        //flag=1,��ʾ�ٴ������������ԭ����һ��
        flag = 1;
        //��������object,�����ù��캯��
        Account object(username, name, id, password);
        //�������Ĺ���Ա��Ϣ����Account����
        Account_vec.push_back(object);
        //����SaveAccount()�������������Ա��Ϣ��account.txt�ļ���
        SaveAccountApp(Account_vec);
        cout << "\n\t\tע��ɹ���\n" << endl;
    }
    if (!flag)
    {
        cout << "\n\t\tע��ʧ�ܣ�\n" << endl;
    }
}



/**********************************************************************
*��������    ModifyAccount()
*�������ܣ�  �޸��˻���Ϣ
*
*����������  Account������Ϊ����������vector<Account> &Account_vec
*��������ֵ��void
**********************************************************************/
void Account::ModifyAccount(vector<Account> &Account_vec)
{
    cout << "\n\n\t\t�޸��˻���Ϣ\n\n" << endl;
    //�����־����
    int flag = 0;
    //����Ա�û���
    string username;
    //����Ա����
    string name;
    //����Ա����
    string id;
    //����Ա����
    string password;

    cout << "������ID��";
    //�����
    cin.get();
    cin >> id;
    //��������� A���������������ҡ��޸Ĺ���Ա��Ϣ
    vector<Account>::iterator A = Account_vec.begin();
    while (A != Account_vec.end())
    {
        if( A -> GetID() == id )
        {
            cout << "���������룺";
            cin >> password;

            if( A -> GetPassword() == password)
            {
                //flag = 1��ʾ�޸��˻���Ϣ�ɹ�
                flag = 1;
                cout << "��Ҫ�޸ĵ��˻���Ϣ��" << endl;
                cout << "===========================" << endl;
                cout << "�û���\t����\tID\n" << endl;
                cout << "===========================\n" << endl;
                cout << A->GetUserName() << '\t' << A->GetName() << '\t';
                cout << A->GetID() << endl;
                cout << "\n===========================\n" << endl;

                cout << "�������û�����";
                cin >> username;
                cout << "������������";
                cin >> name;
                cout << "������ID��";
                cin >> id;

                //SetUserName()�������޸��û���
                A->SetUserName(username);
                //����SetName()�������޸�����
                A->SetName(name);
                //����SetID()�������޸�id
                A->SetID(id);

                cout << "\n\t\t�˻��޸ĳɹ���" << endl;
                break;
            }
            else
            {
                cout << "\n\t\t\t�������\n" << endl;
                break;
            }
        }
        A++;
    }
    if(!flag)
    {
        cout << "\n\t\t\tû�д��˻�����Ϣ������ע���˻���\n" << endl;
    }

    //����SaveRader()�����������޸ĺ����Ϣ��reader.txt�ļ��С�
    SaveAccount(Account_vec);
}



/**********************************************************************
*��������    ChangePassword()
*�������ܣ�  �޸Ĺ���Ա����
*
*����������  Account������Ϊ����������vector<Account> &Account_vec
*��������ֵ��void
**********************************************************************/
void Account::ChangePassword(vector<Account> &Account_vec)
{
    cout << "\n\n\t\t�޸�����\n\n" << endl;
    //�����־����
    int flag = 0;
    //����Ա����
    string id;
    //����Ա����
    string password;
    //ȷ������
    string Confirmpassword;

    cout << "������ID��";
    //�����
    cin.get();
    cin >> id;

    //��������� A���������������ҡ��޸Ĺ���Ա����
    vector<Account>::iterator A = Account_vec.begin();
    while (A != Account_vec.end())
    {
        if( A -> GetID() == id )
        {
            cout << "������ԭ���룺";
            cin >> password;

            if( A -> GetPassword() == password)
            {
                //flag = 1��ʾ�޸�����ɹ�
                flag = 1;
                cout << "��Ҫ�޸ĵ��˻���Ϣ��" << endl;
                cout << "===========================" << endl;
                cout << "�û���\t����\tID\n" << endl;
                cout << "===========================\n" << endl;
                cout << A->GetUserName() << '\t' << A->GetName() << '\t';
                cout << A->GetID() << endl;
                cout << "\n===========================\n" << endl;

                cout << "�����������룺";
                cin >> password;

                cout << "ȷ���������룺";
                cin >> Confirmpassword;

                //�ж�ǰ�������Ƿ�����һ��
                if (Confirmpassword.compare(password) == 0)
                {
                    A->SetPassword(password);
                    SaveAccount(Account_vec);
                    cout << "\n\t\t�����޸ĳɹ���\n" << endl;
                }
                else
                {
                    cout << "\n\t\t\t���벻һ�£��������޸����룡\n" << endl;
                }
                break;
            }
            else
            {
                cout << "\n\t\t\t�������\n" << endl;
            }
        }
        A++;
    }
    if(!flag)
    {
        cout << "\n\t\t\tû�д��˻�����Ϣ������ע���˻���\n" << endl;
    }

    //����SaveRader()�����������޸ĺ����Ϣ��reader.txt�ļ��С�
    SaveAccount(Account_vec);
}



/******************************************************************
*��������    FindAccount()
*�������ܣ�  ��ѯ�˻���Ϣ
*
*����������  Account������Ϊ����������vector<Account> &Account_ve
*��������ֵ��void
******************************************************************/
void Account::FindAccount(vector<Account> &Account_vec)
{
    cout << "\n\n\t\t��ѯ����Ա��Ϣ\n\n" << endl;
    //�����־����
    int flag = 0;
    //Ҫ��ѯ��ID
    string id;

    cout << "��������Ҫ��ѯ��ID��";
    //�����
    cin.get();
    cin >> id;

    //��������� A�����������Ͳ��ҹ���Ա��Ϣ
    vector<Account>::iterator A = Account_vec.begin();
    while (A != Account_vec.end())
    {
        if( A -> GetID() == id )
        {
            //flag = 1��ʾ�ҵ�����Ա��Ϣ
            flag = 1;
            cout << "==========================================" << endl;
            cout << "�û���\t����\tID\t\t����\n" << endl;
            cout << "==========================================\n" << endl;

            //����Print()�������������Ա��Ϣ
            (*A).Print();
            cout << "\n==========================================\n" << endl;
            break;
        }
        A++;
    }

    if (!flag)
    {
        cout << "\n\t\t\tû�д˹���Ա����Ϣ������ע���˻���\n" << endl;
    }
}



/*******************************************************************
*��������    DeleteAccount()
*�������ܣ�  ɾ������Ա��Ϣ
*
*����������  Account������Ϊ����������vector<Account> &Account_vec
*��������ֵ��void
********************************************************************/
void Account::DeleteAccount(vector<Account> &Account_vec)
{
    cout << "\n\n\t\tɾ���˻�\n\n" << endl;
    //�����־����
    int flag = 0;
    //Ҫɾ������Ա��Ϣ��֤����
    string id;

    cout << "������Ҫɾ���Ĺ���ԱID��";
    //�����
    cin.get();
    cin >> id;

    //��������� A���������������Һ͹���Ա��Ϣ
    vector<Account>::iterator A = Account_vec.begin();
    while (A != Account_vec.end())
    {
        if( A -> GetID() == id )
        {
            //flag = 1��ʾ����Ա��Ϣɾ���ɹ�
            flag=1;
            cout << "��Ҫɾ���Ĺ���Ա��Ϣ��" << endl;
            cout << "==========================================" << endl;
            cout << "�û���\t����\tID\t\t����\n" << endl;
            cout << "==========================================\n" << endl;

            //����Print()���������������Ϣ
            (*A).Print();

            //�ͷ�ָ��ù���Ա��Ϣ�ĵ�������Ҳ��ɾ���ù���Ա����Ϣ
            Account_vec.erase(A++);
            cout << "\n\t\tɾ���ɹ���\n" << endl;
            cout << "\n==========================================\n" << endl;
            break;
        }
        else
        {
            A++;
        }
    }
    if(!flag)
    {
        cout << "\n\t\t\tû�д˹���Ա����Ϣ������ע���˻���\n" << endl;
    }

    //����SaveReader()������ɾ����Ķ�����Ϣ��reader.txt�ļ���
    SaveAccount(Account_vec);
}



/********************************************************************
*��������    SaveAccount()
*�������ܣ�  ����д�ķ�ʽ���������Ա��Ϣ��account.txt�ļ��С�
*
*����������  Account������Ϊ����������vector<Account> &Account_vec
*��������ֵ��void
********************************************************************/
void Account::SaveAccount(vector<Account> &Account_vec)
{
    //����account.txt�ļ���
    ofstream out ("account.txt", ios::out);

    //�ж��ļ��Ƿ񴴽��ɹ�
    if (!out)
    {
        cout << "\n\t\t\t�ļ���ʧ�ܣ�";
        exit(0);
    }

    //��������� A���������������������Ϣ
    vector<Account>::iterator A;
    for (A = Account_vec.begin(); A != Account_vec.end(); A++)
    {
        out << A->GetUserName() << '\t' << A->GetName() << '\t';
        out << A->GetID() << '\t' << A->GetPassword() << endl;
    }

    //�ر��ļ�
    out.close();
}


/**********************************************************************
*��������    SaveAccountApp()
*�������ܣ�  ��׷�ӵ��ļ�β��ʽ���������Ա��Ϣ��account.txt�ļ��С�
*
*����������  Account������Ϊ����������vector<Account> &Account_vec
*��������ֵ��void
**********************************************************************/
void Account::SaveAccountApp(vector<Account> &Account_vec)
{
    //����account.txt�ļ���
    ofstream out ("account.txt", ios::out | ios::app);

    //�ж��ļ��Ƿ񴴽��ɹ�
    if (!out)
    {
        cout << "\n\t\t\t�ļ���ʧ�ܣ�";
        exit(0);
    }

    //��������� A���������������������Ϣ
    vector<Account>::iterator A;
    for (A = Account_vec.begin(); A != Account_vec.end(); A++)
    {
        out << A->GetUserName() << '\t' << A->GetName() << '\t';
        out << A->GetID() << '\t' << A->GetPassword() << endl;
    }

    //�ر��ļ�
    out.close();
}



/********************************************************************
*��������    ReadFileToAccountVector()
*�������ܣ�  ��ȡ�ļ���Ϣ��Account������,���������������������ݡ�
*
*����������  Account������Ϊ����������vector<Account> &Account_vec
*��������ֵ��void
********************************************************************/
void Account::ReadFileToAccountVector(vector<Account> &Account_vec)
{
    //����Ա�û���
    string username;
    //����Ա����
    string name;
    //����Ա����
    string id;
    //����Ա����
    string password;

    //��ȡ�ļ���Ϣ
    ifstream in("account.txt", ios::in);
    //�ж��ļ����Ƿ�ɹ�
    if (!in)
    {
        cout << "\n\t\t\t�ļ���ʧ��";
        exit(0);
    }

    //�Ƚ��й���Ա��Ϣ�Ķ�ȡ��Ž�Account��������ֹ���һ����Ϣ��©
    in >> username >>  name >>  id >> password;
    while (!in.eof())
    {
        //��������Ա����object,������Account()���캯����
        Account object(username, name, id, password);

        //��ȡ��Ĺ���Ա��Ϣ����Account������
        Account_vec.push_back(object);
        in >> username >>  name >>  id >> password;
    }

    //�ر��ļ�
    in.close();
}



/**************************************************
*��������    ~Account()
*�������ܣ�  ���������ڽ���ʱ��ϵͳ������������
*
*
*����������  ��
**************************************************/
Account::~Account()
{}
