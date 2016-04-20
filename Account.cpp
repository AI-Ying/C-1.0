/********************************************************************************
*
*Copyright(c)2015,南昌大学软件学院实验小组(张欢，王沛然，闫致敬)
*All rights reserved.
*
*文件名称： Book.cpp
*文件标识： 见配置管理计划书
*
*摘    要：  本文件主要是对账户管理功能函数的实现。在对管理员账户的数据
*            进行操作时，使用了向量容器vector，方便了数据在各个函数之
*            间的调用，也更容易理解。
*
*
*当前版本：1.0
*作者：张欢
*完成日期：2015/6/5
*第一次修改：2015/6/8
*第二次修改：2015/6/16
*
**********************************************************************************/

#include  "Account.h"         //引用非标准库函数





/***************************************************
*函数名：    Account()
*函数功能：  创建对象没有初始化，调用无参构造函数
*
*函数参数：  无
***************************************************/
Account::Account()
{
}



/**************************************************
*函数名：    Account()
*函数功能：  构造函数，对对象进行初始化。
*
*
*函数参数:
*            string username       //管理员用户名
*            string name           //管理员姓名
*            string id             //管理员ID
*            string password       //管理员密码
****************************************************/
Account::Account(string username, string name, string id, string password)
{
    this->UserName = username;
    this->Name = name;
    this->ID = id;
    this->Password = password;
}



/*********************************************************
*函数名：   GetUserName()
*函数功能： 获取管理员用户名
*
*函数参数：  void
*函数返回值：UserName
**********************************************************/
string Account::GetUserName()
{
    return UserName;
}
/*********************************************************
*函数名：    SetUserName()
*函数功能：  对管理员用户名进行修改
*
*函数参数：  string username    //管理员用户名
*函数返回值: UserName
*********************************************************/
string Account::SetUserName(string username)
{
    this->UserName = username;
    return UserName;
}



/*********************************************************
*函数名：   GetName()
*函数功能： 获取管理员姓名
*
*函数参数：  void
*函数返回值：Name
**********************************************************/
string Account::GetName()
{
    return Name;
}
/*********************************************************
*函数名：    SetName()
*函数功能：  对管理员姓名进行修改
*
*函数参数：  string name    //管理员姓名
*函数返回值: Name
*********************************************************/
string Account::SetName(string name)
{
    this->Name = name;
    return Name;
}



/*********************************************************
*函数名：   GetID()
*函数功能： 获取管理员ID号
*
*函数参数：  void
*函数返回值：ID
**********************************************************/
string Account::GetID()
{
    return ID;
}
/*********************************************************
*函数名：    SetID()
*函数功能：  对管理员ID号进行修改
*
*函数参数：  string id    //管理员ID号
*函数返回值: ID
*********************************************************/
string Account::SetID(string id)
{
    this->ID = id;
    return ID;
}



/*********************************************************
*函数名：   GetPassword()
*函数功能： 获取管理员密码
*
*函数参数：  void
*函数返回值：Password
**********************************************************/
string Account::GetPassword()
{
    return Password;
}
/*********************************************************
*函数名：    SetPassword()
*函数功能：  对管理员密码进行修改
*
*函数参数：  string password    //管理员密码
*函数返回值: Password
*********************************************************/
string Account::SetPassword(string password)
{
    this->Password = password;
    return Password;
}



/*********************************************************
*函数名：    Print()
*函数功能：  输入单个账户的全部信息
*
*函数参数：  void
*函数返回值：void
*********************************************************/
void Account::Print()
{
    cout << GetUserName() << '\t' << GetName() << '\t';
    cout << GetID() << '\t' << GetPassword() << endl;
}



/********************************************************************
*函数名：    Login()
*函数功能：  管理员账户注册
*
*函数参数：  Account容器作为函数参数：vector<Account> &Account_vec
*
*函数返回值：void
*********************************************************************/
void Account::Login(vector<Account> &Account_vec)
{
    cout << "\n\n\t\t注册账户\n\n" << endl;
    //管理员用户名
    string username;
    //管理员姓名
    string name;
    //管理员工号
    string id;
    //管理员密码
    string password;
    //确认密码
    string Confirmpassword;
    //标志变量
    int flag = 0;

    cout << "注册信息：\n";
    cout << "请输入用户名：";
    cin  >> username;
    cout << "请输入姓名：";
    cin  >> name;
    cout << "请输入ID：";
    cin  >> id;
    cout << "请输入密码：";
    cin  >> password;
    cout << "请确认密码：";
    cin  >> Confirmpassword;

    if (password.compare(Confirmpassword) == 0)
    {
        //flag=1,表示再次输入的密码与原密码一致
        flag = 1;
        //创建对象object,并调用构造函数
        Account object(username, name, id, password);
        //将创建的管理员信息送入Account集中
        Account_vec.push_back(object);
        //调用SaveAccount()函数，保存管理员信息到account.txt文件中
        SaveAccountApp(Account_vec);
        cout << "\n\t\t注册成功！\n" << endl;
    }
    if (!flag)
    {
        cout << "\n\t\t注册失败！\n" << endl;
    }
}



/**********************************************************************
*函数名：    ModifyAccount()
*函数功能：  修改账户信息
*
*函数参数：  Account容器作为函数参数：vector<Account> &Account_vec
*函数返回值：void
**********************************************************************/
void Account::ModifyAccount(vector<Account> &Account_vec)
{
    cout << "\n\n\t\t修改账户信息\n\n" << endl;
    //定义标志变量
    int flag = 0;
    //管理员用户名
    string username;
    //管理员姓名
    string name;
    //管理员工号
    string id;
    //管理员密码
    string password;

    cout << "请输入ID：";
    //缓冲键
    cin.get();
    cin >> id;
    //定义迭代器 A，用来遍历、查找、修改管理员信息
    vector<Account>::iterator A = Account_vec.begin();
    while (A != Account_vec.end())
    {
        if( A -> GetID() == id )
        {
            cout << "请输入密码：";
            cin >> password;

            if( A -> GetPassword() == password)
            {
                //flag = 1表示修改账户信息成功
                flag = 1;
                cout << "您要修改的账户信息：" << endl;
                cout << "===========================" << endl;
                cout << "用户名\t姓名\tID\n" << endl;
                cout << "===========================\n" << endl;
                cout << A->GetUserName() << '\t' << A->GetName() << '\t';
                cout << A->GetID() << endl;
                cout << "\n===========================\n" << endl;

                cout << "请输入用户名：";
                cin >> username;
                cout << "请输入姓名：";
                cin >> name;
                cout << "请输入ID：";
                cin >> id;

                //SetUserName()函数，修改用户名
                A->SetUserName(username);
                //调用SetName()函数，修改姓名
                A->SetName(name);
                //调用SetID()函数，修改id
                A->SetID(id);

                cout << "\n\t\t账户修改成功！" << endl;
                break;
            }
            else
            {
                cout << "\n\t\t\t密码错误！\n" << endl;
                break;
            }
        }
        A++;
    }
    if(!flag)
    {
        cout << "\n\t\t\t没有此账户的信息！请先注册账户。\n" << endl;
    }

    //调用SaveRader()函数，保存修改后的信息到reader.txt文件中。
    SaveAccount(Account_vec);
}



/**********************************************************************
*函数名：    ChangePassword()
*函数功能：  修改管理员密码
*
*函数参数：  Account容器作为函数参数：vector<Account> &Account_vec
*函数返回值：void
**********************************************************************/
void Account::ChangePassword(vector<Account> &Account_vec)
{
    cout << "\n\n\t\t修改密码\n\n" << endl;
    //定义标志变量
    int flag = 0;
    //管理员工号
    string id;
    //管理员密码
    string password;
    //确认密码
    string Confirmpassword;

    cout << "请输入ID：";
    //缓冲键
    cin.get();
    cin >> id;

    //定义迭代器 A，用来遍历、查找、修改管理员密码
    vector<Account>::iterator A = Account_vec.begin();
    while (A != Account_vec.end())
    {
        if( A -> GetID() == id )
        {
            cout << "请输入原密码：";
            cin >> password;

            if( A -> GetPassword() == password)
            {
                //flag = 1表示修改密码成功
                flag = 1;
                cout << "您要修改的账户信息：" << endl;
                cout << "===========================" << endl;
                cout << "用户名\t姓名\tID\n" << endl;
                cout << "===========================\n" << endl;
                cout << A->GetUserName() << '\t' << A->GetName() << '\t';
                cout << A->GetID() << endl;
                cout << "\n===========================\n" << endl;

                cout << "请输入新密码：";
                cin >> password;

                cout << "确认输入密码：";
                cin >> Confirmpassword;

                //判断前后密码是否输入一致
                if (Confirmpassword.compare(password) == 0)
                {
                    A->SetPassword(password);
                    SaveAccount(Account_vec);
                    cout << "\n\t\t密码修改成功！\n" << endl;
                }
                else
                {
                    cout << "\n\t\t\t密码不一致，请重新修改密码！\n" << endl;
                }
                break;
            }
            else
            {
                cout << "\n\t\t\t密码错误！\n" << endl;
            }
        }
        A++;
    }
    if(!flag)
    {
        cout << "\n\t\t\t没有此账户的信息！请先注册账户。\n" << endl;
    }

    //调用SaveRader()函数，保存修改后的信息到reader.txt文件中。
    SaveAccount(Account_vec);
}



/******************************************************************
*函数名：    FindAccount()
*函数功能：  查询账户信息
*
*函数参数：  Account容器作为函数参数：vector<Account> &Account_ve
*函数返回值：void
******************************************************************/
void Account::FindAccount(vector<Account> &Account_vec)
{
    cout << "\n\n\t\t查询管理员信息\n\n" << endl;
    //定义标志变量
    int flag = 0;
    //要查询的ID
    string id;

    cout << "请输入您要查询的ID：";
    //缓冲键
    cin.get();
    cin >> id;

    //定义迭代器 A，用来遍历和查找管理员信息
    vector<Account>::iterator A = Account_vec.begin();
    while (A != Account_vec.end())
    {
        if( A -> GetID() == id )
        {
            //flag = 1表示找到管理员信息
            flag = 1;
            cout << "==========================================" << endl;
            cout << "用户名\t姓名\tID\t\t密码\n" << endl;
            cout << "==========================================\n" << endl;

            //调用Print()函数，输出管理员信息
            (*A).Print();
            cout << "\n==========================================\n" << endl;
            break;
        }
        A++;
    }

    if (!flag)
    {
        cout << "\n\t\t\t没有此管理员的信息！请先注册账户。\n" << endl;
    }
}



/*******************************************************************
*函数名：    DeleteAccount()
*函数功能：  删除管理员信息
*
*函数参数：  Account容器作为函数参数：vector<Account> &Account_vec
*函数返回值：void
********************************************************************/
void Account::DeleteAccount(vector<Account> &Account_vec)
{
    cout << "\n\n\t\t删除账户\n\n" << endl;
    //定义标志变量
    int flag = 0;
    //要删除管理员信息的证件号
    string id;

    cout << "请输入要删除的管理员ID：";
    //缓冲键
    cin.get();
    cin >> id;

    //定义迭代器 A，用来遍历、查找和管理员信息
    vector<Account>::iterator A = Account_vec.begin();
    while (A != Account_vec.end())
    {
        if( A -> GetID() == id )
        {
            //flag = 1表示管理员信息删除成功
            flag=1;
            cout << "您要删除的管理员信息：" << endl;
            cout << "==========================================" << endl;
            cout << "用户名\t姓名\tID\t\t密码\n" << endl;
            cout << "==========================================\n" << endl;

            //调用Print()函数，输出读者信息
            (*A).Print();

            //释放指向该管理员信息的迭代器，也即删除该管理员的信息
            Account_vec.erase(A++);
            cout << "\n\t\t删除成功！\n" << endl;
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
        cout << "\n\t\t\t没有此管理员的信息！请先注册账户。\n" << endl;
    }

    //调用SaveReader()函数，删除后的读者信息到reader.txt文件中
    SaveAccount(Account_vec);
}



/********************************************************************
*函数名：    SaveAccount()
*函数功能：  以重写的方式，保存管理员信息到account.txt文件中。
*
*函数参数：  Account容器作为函数参数：vector<Account> &Account_vec
*函数返回值：void
********************************************************************/
void Account::SaveAccount(vector<Account> &Account_vec)
{
    //创建account.txt文件。
    ofstream out ("account.txt", ios::out);

    //判读文件是否创建成功
    if (!out)
    {
        cout << "\n\t\t\t文件打开失败！";
        exit(0);
    }

    //定义迭代器 A，用来遍历和输出读者信息
    vector<Account>::iterator A;
    for (A = Account_vec.begin(); A != Account_vec.end(); A++)
    {
        out << A->GetUserName() << '\t' << A->GetName() << '\t';
        out << A->GetID() << '\t' << A->GetPassword() << endl;
    }

    //关闭文件
    out.close();
}


/**********************************************************************
*函数名：    SaveAccountApp()
*函数功能：  以追加到文件尾方式，保存管理员信息到account.txt文件中。
*
*函数参数：  Account容器作为函数参数：vector<Account> &Account_vec
*函数返回值：void
**********************************************************************/
void Account::SaveAccountApp(vector<Account> &Account_vec)
{
    //创建account.txt文件。
    ofstream out ("account.txt", ios::out | ios::app);

    //判读文件是否创建成功
    if (!out)
    {
        cout << "\n\t\t\t文件打开失败！";
        exit(0);
    }

    //定义迭代器 A，用来遍历和输出读者信息
    vector<Account>::iterator A;
    for (A = Account_vec.begin(); A != Account_vec.end(); A++)
    {
        out << A->GetUserName() << '\t' << A->GetName() << '\t';
        out << A->GetID() << '\t' << A->GetPassword() << endl;
    }

    //关闭文件
    out.close();
}



/********************************************************************
*函数名：    ReadFileToAccountVector()
*函数功能：  读取文件信息到Account容器中,供其他函数调用容器数据。
*
*函数参数：  Account容器作为函数参数：vector<Account> &Account_vec
*函数返回值：void
********************************************************************/
void Account::ReadFileToAccountVector(vector<Account> &Account_vec)
{
    //管理员用户名
    string username;
    //管理员姓名
    string name;
    //管理员工号
    string id;
    //管理员密码
    string password;

    //读取文件信息
    ifstream in("account.txt", ios::in);
    //判读文件打开是否成功
    if (!in)
    {
        cout << "\n\t\t\t文件打开失败";
        exit(0);
    }

    //先进行管理员信息的读取后放进Account容器，防止最后一条信息遗漏
    in >> username >>  name >>  id >> password;
    while (!in.eof())
    {
        //创建管理员对象object,并调用Account()构造函数。
        Account object(username, name, id, password);

        //读取后的管理员信息放入Account容器中
        Account_vec.push_back(object);
        in >> username >>  name >>  id >> password;
    }

    //关闭文件
    in.close();
}



/**************************************************
*函数名：    ~Account()
*函数功能：  对象生存期结束时，系统调用析构函数
*
*
*函数参数：  无
**************************************************/
Account::~Account()
{}
