/***********************************************************************
*
*Copyright(c)2015,南昌大学软件学院实验小组(张欢，王沛然，闫致敬)
*All rights reserved.
*
*文件名称： Reader.cpp
*文件标识： 见配置管理计划书
*
*摘    要： 本文件主要是对读者管理功能函数的实现。在对读者的数据进行
*            操作时，使用了向量容器vector，方便了数据在各个函数之间
*            的调用，也更容易理解。
*
*
*当前版本：1.0
*作者：王沛然
*完成日期：2015/6/3
*第一次修改：2015/6/1
*第二次修改：2015/6/3
*
**********************************************************************/

#include  "Reader.h"           //引用非标准库函数Reader.h



/***************************************************
*函数名：    Reader()
*函数功能：  创建对象没有初始化，调用无参构造函数
*
*
*函数参数：  无
***************************************************/
Reader::Reader()
{}


/**************************************************
*函数名：    Reader()
*函数功能：  构造函数，对对象进行初始化。
*
*
*函数参数:  姓名:     string name
*            性别：    string sex
*            证件号：  string code
*            工作单位：string dept
*            挂失状态：int tag
*            借书数量：int number
****************************************************/
Reader::Reader(string name, string sex, string code, string dept, int tag, int number)
{
    this->Name = name;
    this->Sex = sex;
    this->Code = code;
    this->Dept = dept;
    this->Tag = tag;
    this->Number = number;
}


/*********************************************************
*函数名：   GetName()
*函数功能： 获取读者姓名信息
*
*函数参数：  void
*函数返回值：Name
**********************************************************/
string Reader::GetName()
{
    return Name;
}
/*********************************************************
*函数名：    SetName()
*函数功能：  对读者姓名进行修改
*
*函数参数：  读者姓名：string name
*函数返回值: Name
*********************************************************/
string Reader::SetName(string name)
{
    this -> Name = name;
    return Name;
}


/*********************************************************
*函数名：    GetSex()
*函数功能：  获取读者性别信息
*
*函数参数：  void
*函数返回值：Sex
*********************************************************/
string Reader::GetSex()
{
    return Sex;
}
/*********************************************************
*函数名：    SetSex()
*函数功能：  对读者的性别信息进行修改
*
*函数参数：  读者性别：string sex
*函数返回值：Sex
*********************************************************/
string Reader::SetSex(string sex)
{
    this -> Sex = sex;
    return Sex;
}


/*********************************************************
*函数名：    GetCode()
*函数功能：  获取读者证件号信息
*
*函数参数：  void
*函数返回值：Code
*********************************************************/
string Reader::GetCode()
{
    return Code;
}
/*********************************************************
*函数名：    SetCode()
*函数功能：  对读者的证件号信息进行修改
*
*函数参数：  读者证件号：string code
*函数返回值：Code
*********************************************************/
string Reader::SetCode(string code)
{
    this->Code = code;
    return Code;
}


/*********************************************************
*函数名：    GetDept()
*函数功能：  获取读者的工作单位信息
*
*函数参数：  void
*函数返回值：Dept
*********************************************************/
string Reader::GetDept()
{
    return Dept;
}
/*********************************************************
*函数名：    SetDept()
*函数功能：  对读者的工作单位信息进行修改
*
*函数参数：  读者工作单位：string dept
*函数返回值：Dept
*********************************************************/
string Reader::SetDept(string dept)
{
    this -> Dept = dept;
    return Dept;
}


/*********************************************************
*函数名：    GetTag()
*函数功能：  获取读者的挂失状态信息
*
*函数参数：  void
*函数返回值：Tag
*********************************************************/
int Reader::GetTag()
{
    return Tag;
}
/*********************************************************
*函数名：    SetTag()
*函数功能：  对读者的挂失状态信息进行修改
*
*函数参数：  读者挂失状态：int tag
*函数返回值：Tag
*********************************************************/
int Reader::SetTag(int tag)
{
    this->Tag = tag;
    return Tag;
}


/*********************************************************
*函数名：    GetNumber()
*函数功能：  获取读者的借阅图书数量的信息
*
*函数参数：  void
*函数返回值：Number
*********************************************************/
int Reader::GetNumber()
{
    return Number;
}
/*********************************************************
*函数名：    SetNumber()
*函数功能：  对读者的借阅图书数量的信息进行修改
*
*函数参数：  读者借书数量：int number
*函数返回值：Number
*********************************************************/
int Reader::SetNumber(int number)
{
    this->Number = number;
    return Number;
}


/*********************************************************
*函数名：    Print()
*函数功能：  输入单个读者的全部信息
*
*函数参数：  void
*函数返回值：void
*********************************************************/
void Reader::Print()
{
    cout << GetName() << '\t' << GetSex() << '\t';
    cout << GetCode() << '\t' << GetDept() << '\t';
    cout << setw(5) << GetTag() << setw(15) << GetNumber() << endl;
}


/****************************************************************
*函数名：    AddReader()
*函数功能：  添加读者信息
*
*函数参数：  Reader容器作为函数参数：vector<Reader> &Reader_vec
*
*函数返回值：void
*****************************************************************/
void Reader::AddReader(vector<Reader> &Reader_vec)
{
    cout << "\n\n\t\t\t\t添加读者信息\n\n" << endl;
    //读者姓名
    string name;
    //读者性别
    string sex;
    //读者证件号
    string code;
    //读者工作单位
    string dept;
    //用户输入选择
    char reply;

    do
    {
        cout << "\n请输入读者的姓名：";
        cin >> name;
        cout << "请输入读者的性别：";
        cin >> sex;
        cout << "请输入读者的证件号：";
        cin >> code;
        cout << "请输入读者的工作单位：";
        cin >> dept;

        cout << "您要继续输入吗？（(Y/h)/(N/n)）：";
        cin  >> reply;

        //创建对象object,并调用构造函数
        Reader object(name, sex, code, dept, 0, 0);
        //将创建的读者信息送入Reader容器中
        Reader_vec.push_back(object);

    }while(reply == 'Y' || reply == 'y');

    cout << "\n是否保存输入的信息？（(Y/y)/(N/n)）：";
    char choose;
    cin  >> choose;
    if (choose == 'Y' || choose == 'y')
    {
        //调用SaveReaderApp()函数，保存读者信息到reader.txt文件中
        SaveReaderApp(Reader_vec);
        cout << "\n\t\t\t文件保存成功！\n\n" << endl;
    }
    else
    {
        cout << "\n\t\t\t文件没有保存！\n\n" << endl;
    }
}



/******************************************************************
*函数名：    BrowseReader()
*函数功能：  浏览读者信息
*
*函数参数：  Reader容器作为函数参数：vector<Reader> &Reader_vec
*函数返回值：void
*******************************************************************/
void Reader::BrowseReader(vector<Reader> &Reader_vec)
{
    cout << "\n\n\t\t\t\t浏览读者信息\n\n" << endl;
    cout << "=================================================================================" << endl;
    cout << "姓名\t性别\t证件号\t\t工作单位\t\t挂失状态\t借书本数" << endl;
    cout << "=================================================================================\n" << endl;

    //定义迭代器 R，用来遍历和输出读者信息
    vector<Reader>::iterator R = Reader_vec.begin();
    while (R != Reader_vec.end())
    {
        //调用Print()函数，输出读者信息
        (*R).Print();
        R++;
    }
    cout << "\n=================================================================================\n\n" << endl;
}



/******************************************************************
*函数名：    FindReaderByName()
*函数功能：  根据读者的姓名来查找读者信息
*
*函数参数：  Reader容器作为函数参数：vector<Reader> &Reader_vec
*函数返回值：void
******************************************************************/
void Reader::FindReaderByName(vector<Reader> &Reader_vec)
{
    cout << "\n\n\t\t\t\t根据读者姓名查询读者信息\n\n" << endl;
    //定义标志变量
    int flag = 0;
    //要查询的姓名
    string name;

    cout << "请输入您要查询读者的姓名：";
    cin  >> name;

    //定义迭代器 R，用来遍历和查找读者信息
    vector<Reader>::iterator R = Reader_vec.begin();
    while (R != Reader_vec.end())
    {
        if( R -> GetName() == name )
        {
            //flag = 1表示找到读者信息
            flag = 1;
            cout << "=================================================================================" << endl;
            cout << "姓名\t性别\t证件号\t\t工作单位\t\t挂失状态\t借书本数" << endl;
            cout << "=================================================================================\n" << endl;

            //调用Print()函数，输出读者信息
            (*R).Print();
            cout << "\n=================================================================================\n\n" << endl;
            break;
        }
        R++;
    }
    if (!flag)
    {
        cout << "\n\t\t\t没有此读者的信息！\n\n" << endl;
    }
}



/******************************************************************
*函数名：    FindReaderByCode()
*函数功能：  根据读者的证件号来查找读者信息
*
*函数参数：  Reader容器作为函数参数：vector<Reader> &Reader_vec
*函数返回值：void
******************************************************************/
void Reader::FindReaderByCode(vector<Reader> &Reader_vec)
{
    cout << "\n\n\t\t\t\t根据读者证件号查询读者信息\n\n" << endl;
    //定义标志变量
    int flag = 0;
    //要查询的读者证件号
    string code;

    cout << "请输入您要查询读者的证件号：";
    cin  >> code;

    //定义迭代器 R，用来遍历和查找读者信息
    vector<Reader>::iterator R = Reader_vec.begin();
    while (R != Reader_vec.end())
    {
        if( R -> GetCode() == code )
        {
            //flag = 1表示找到读者信息
            flag = 1;
            cout << "=================================================================================" << endl;
            cout << "姓名\t性别\t证件号\t\t工作单位\t\t挂失状态\t借书本数" << endl;
            cout << "=================================================================================\n" << endl;

            //调用Print()函数，输出读者信息
            (*R).Print();
            cout << "\n=================================================================================\n\n" << endl;
            break;
        }
        R++;
    }

    if (!flag)
    {
        cout << "\n\t\t\t没有此读者的信息！\n\n" << endl;
    }
}



/******************************************************************
*函数名：    ModifyReader()
*函数功能：  修改读者信息
*
*函数参数：  Reader容器作为函数参数：vector<Reader> &Reader_vec
*函数返回值：void
******************************************************************/
void Reader::ModifyReader(vector<Reader> &Reader_vec)
{
    cout << "\n\n\t\t\t\t修改读者信息\n\n" << endl;
    //定义标志变量
    int flag = 0;
    //修改后的读者姓名
    string name;
    //修改后的读者性别
    string sex;
    //修改后的读者证件号
    string code;
    //修改后的读者工作单位
    string dept;
    //修改后的读者挂失状态
    int tag;
    //读者借书数量，这里不允许修改，默认原借书本数
    int number;

    cout << "请输入要修改的读者证件号：";
    cin  >> code;

    //定义迭代器 R，用来遍历、查找和修改读者信息
    vector<Reader>::iterator R = Reader_vec.begin();
    while (R != Reader_vec.end())
    {
        if( R -> GetCode() == code )
        {
            //flag = 1表示修改读者信息成功
            flag = 1;
            cout << "您要修改的读者信息：" << endl;
            cout << "=================================================================================" << endl;
            cout << "姓名\t性别\t证件号\t\t工作单位\t\t挂失状态\t借书本数" << endl;
            cout << "=================================================================================\n" << endl;

            //调用Print()函数，输出读者信息
            (*R).Print();

            cout << "请输入读者的姓名：";
            cin >> name;
            cout << "请输入读者的性别：";
            cin >> sex;
            cout << "请输入读者的证件号：";
            cin >> code;
            cout << "请输入读者的工作单位：";
            cin >> dept;
            cout << "请输入读者信息的挂失状态（0-正常、1-挂失）：" << endl;
            //缓冲作用
            cin.get();
            cin >> tag;

            //调用SetName()函数，修改姓名
            R->SetName(name);
            //调用SetSex()函数，修改性别
            R->SetSex(sex);
            //调用SetCode()函数，修改证件号
            R->SetCode(code);
            //调用SetDept()函数，修改工作单位
            R->SetDept(dept);
            //调用SetTag()函数，修改挂失状态
            R->SetTag(tag);
            //调用GetNumber(),获取借书数量
            number = R->GetNumber();
            //调用SetNumber()函数。借书数量不能随意修改
            R->SetNumber(number);

            cout << "\n\t\t\t修改成功！\n\n" << endl;
            cout << "\n=================================================================================\n\n" << endl;
            break;
        }
        R++;
    }
    if(!flag)
    {
        cout << "\n\t\t\t修改失败！\n\n" << endl;
    }

    //调用SaveRader()函数，保存修改后的信息到reader.txt文件中。
    SaveReader(Reader_vec);
}


/******************************************************************
*函数名：    DeleteReader()
*函数功能：  删除读者信息
*
*函数参数：  Reader容器作为函数参数：vector<Reader> &Reader_vec
*函数返回值：void
*******************************************************************/
void Reader::DeleteReader(vector<Reader> &Reader_vec)
{
    cout << "\n\n\t\t\t\t删除读者信息\n\n" << endl;
    //定义标志变量
    int flag = 0;
    //要删除读者信息的证件号
    string code;

    cout << "请输入要删除的读者证件号：";
    cin  >> code;

    //定义迭代器 R，用来遍历、查找和删除读者信息
    vector<Reader>::iterator R = Reader_vec.begin();
    while (R != Reader_vec.end())
    {
        if( R -> GetCode() == code )
        {
            //flag = 1表示读者信息删除成功
            flag=1;
            cout << "您要删除的读者信息：" << endl;
            cout << "=================================================================================" << endl;
            cout << "姓名\t性别\t证件号\t\t工作单位\t\t挂失状态\t借书本数" << endl;
            cout << "=================================================================================\n" << endl;

            //调用Print()函数，输出读者信息
            (*R).Print();

            //释放指向该读者信息的迭代器，也即删除该读者的信息
            Reader_vec.erase(R++);
            cout << "\n\t\t\t删除成功！\n\n" << endl;
            cout << "\n=================================================================================\n\n" << endl;
            break;
        }
        else
        {
            R++;
        }
    }
    if(!flag)
    {
        cout << "\n\t\t\t删除失败！\n\n\n" << endl;
    }

    //调用SaveReader()函数，删除后的读者信息到reader.txt文件中
    SaveReader(Reader_vec);
}


/******************************************************************
*函数名：    LostReader()
*函数功能：  读者信息挂失
*
*函数参数：  Reader容器作为函数参数：vector<Reader> &Reader_vec
*函数返回值：void
******************************************************************/
void Reader::LostReader(vector<Reader> &Reader_vec)
{
    cout << "\n\n\t\t\t\t挂失读者信息\n\n" << endl;
    //定义标志变量
    int flag = 0;
    //要挂失读者的证件号
    string code;

    cout << "请输入挂失的读者证件号：";
    cin  >> code;

    //定义迭代器 R，用来遍历、查找和挂失读者信息
    vector<Reader>::iterator R = Reader_vec.begin();
    while (R != Reader_vec.end())
    {
        if( R -> GetCode() == code )
        {
            //flag = 1表示读者信息挂失成功
            flag = 1;
            cout << "您要挂失的读者信息：" << endl;
            cout << "=================================================================================" << endl;
            cout << "姓名\t性别\t证件号\t\t工作单位\t\t挂失状态\t借书本数" << endl;
            cout << "=================================================================================\n" << endl;

            //调用Print()函数，输出读者信息
            (*R).Print();

            //调用SetTag()函数，对读者挂失状态进行修改
            R->SetTag(1);
            cout << "\n\t\t\t挂失成功！\n\n" << endl;
            cout << "\n=================================================================================\n\n" << endl;
            break;
        }
        R++;
    }
    if(!flag)
    {
        cout << "\n\t\t\t挂失失败！\n\n" << endl;
    }

    //调用SaveReader()函数，保存挂失后的读者信息到reader.txt文件中
    SaveReader(Reader_vec);
}



/******************************************************************
*函数名：    SaveReader()
*函数功能：  以重写的方式，保存读者信息到reader.txt文件中。
*
*函数参数：  Reader容器作为函数参数：vector<Reader> &Reader_vec
*函数返回值：void
******************************************************************/
void Reader::SaveReader(vector<Reader> &Reader_vec)
{
    //创建reader.txt文件。
    ofstream out ("reader.txt", ios::out);

    //判读文件是否创建成功
    if (!out)
    {
        cout << "\n\t\t\t文件创建失败！\n\n";
        exit(0);
    }

    //定义迭代器 R，用来遍历和写入读者信息到Reader.txt文件中
    vector<Reader>::iterator R;
    for (R = Reader_vec.begin(); R != Reader_vec.end(); R++)
    {
        out << R->GetName() << '\t' << R->GetSex() << '\t';
        out << R->GetCode() << '\t' << R->GetDept() << '\t';
        out << R->GetTag()  << '\t' << R->GetNumber() << endl;
    }

    //关闭文件
    out.close();
}



/******************************************************************
*函数名：    SaveReaderApp()
*函数功能：  以添加到文件尾方式，保存读者信息到reader.txt文件中。
*
*函数参数：  Reader容器作为函数参数：vector<Reader> &Reader_vec
*函数返回值：void
******************************************************************/
void Reader::SaveReaderApp(vector<Reader> &Reader_vec)
{
    //创建reader.txt文件。
    ofstream out ("reader.txt", ios::out | ios::app);

    //判读文件是否创建成功
    if (!out)
    {
        cout << "\n\t\t\t文件打开失败！\n\n";
        exit(0);
    }

    //定义迭代器 R，用来遍历和写入读者信息到Reader.txt文件中
    vector<Reader>::iterator R;
    for (R = Reader_vec.begin(); R != Reader_vec.end(); R++)
    {
        out << R->GetName() << '\t' << R->GetSex() << '\t';
        out << R->GetCode() << '\t' << R->GetDept() << '\t';
        out << R->GetTag()  << '\t' << R->GetNumber() << endl;
    }

    //关闭文件
    out.close();
}



/******************************************************************
*函数名：    ReaderFileToVector()
*函数功能：  读取文件信息到Reader容器中,供其他函数调用容器数据。
*
*函数参数：  Reader容器作为函数参数：vector<Reader> &Reader_vec
*函数返回值：void
******************************************************************/
void Reader::ReadFileToReaderVector(vector<Reader> &Reader_vec)
{
    //读者姓名
    string name;
    //读者性别
    string sex;
    //读者证件号
    string code;
    //读者工作单位
    string dept;
    //读者挂失状态（0-正常，1-挂失）
    int tag;
    //读者借书数量
    int number;

    //读取文件信息到Reader容器中
    ifstream in("reader.txt", ios::in);
    //判读文件打开是否成功
    if (!in)
    {
        cout << "\n\t\t\t文件打开失败！\n\n" << endl;
        exit(0);
    }

    //先进行读者信息的读取后放进Reader容器，防止最后一条信息遗漏
    in >> name >>  sex >>  code >> dept >> tag >> number;
    while (!in.eof())
    {
        //创建读者对象object,并调用Reader()构造函数。
        Reader object(name, sex, code, dept, tag, number);

        //读取后的读者信息放入Reader容器中
        Reader_vec.push_back(object);
        in >> name >>  sex >>  code >> dept >> tag >> number;
    }

    //关闭文件
    in.close();
}


/**************************************************
*函数名：    ~Reader()
*函数功能：  对象生存期结束时，系统调用析构函数
*
*
*函数参数：  无
**************************************************/
Reader::~Reader()
{}
