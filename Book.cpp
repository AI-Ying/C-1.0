/********************************************************************************
*
*Copyright(c)2015,南昌大学软件学院实验小组(张欢，王沛然，闫致敬)
*All rights reserved.
*
*文件名称： Book.cpp
*文件标识： 见配置管理计划书
*
*摘    要： 本文件主要是对图书编目管理功能函数的实现。在对图书的数据
*            进行操作时，使用了向量容器vector，方便了数据在各个函数
*            之间的调用，也更容易理解。
*
*
*当前版本：1.0
*作者：张欢
*完成日期：2015/6/5
*第一次修改：2015/6/8
*第二次修改：2015/6/16
*
**********************************************************************************/

#include  "Book.h"            //引用非标准库函数





/***************************************************
*函数名：    Book()
*函数功能：  创建对象没有初始化，调用无参构造函数
*
*函数参数：  无
***************************************************/
Book::Book()
{}



/**************************************************
*函数名：    Book()
*函数功能：  构造函数，对对象进行初始化。
*
*
*函数参数:
*            string isbn         //图书ISBN编号
*            string title        //图书名称
*            string author       //图书作者
*            string publisher    //出版商
*            string date         //出版日期
*            float  price        //图书价格
*            string catalognum   //图书分类编号
*            int    number       //图书数量
****************************************************/
Book::Book(string isbn, string title, string author, string publisher, string date, float price, string catalognum, int number)
{
    this->ISBN = isbn;
    this->Title = title;
    this->Author = author;
    this->Publisher = publisher;
    this->Date = date;
    this->Price = price;
    this->CatalogNum = catalognum;
    this->Number = number;
}



/*********************************************************
*函数名：   GetISBN()
*函数功能： 获取图书ISBN编号
*
*函数参数：  void
*函数返回值：ISBN
**********************************************************/
string Book::GetISBN()
{
    return ISBN;
}
/*********************************************************
*函数名：    SetISBN()
*函数功能：  对读者姓名进行修改
*
*函数参数：  string isbn    //图书ISBN编号
*函数返回值: ISBN
*********************************************************/
string Book::SetISBN(string isbn)
{
    this->ISBN = isbn;
    return ISBN;
}



/*********************************************************
*函数名：   GetTitle()
*函数功能： 获取图书名称
*
*函数参数：  void
*函数返回值：Title
**********************************************************/
string Book::GetTitle()
{
    return Title;
}
/*********************************************************
*函数名：    SetTitle()
*函数功能：  对图书名称进行修改
*
*函数参数：  string title     //图书名称
*函数返回值: Title
*********************************************************/
string Book::SetTitle(string title)
{
    this->Title = title;
    return Title;
}



/*********************************************************
*函数名：   GetAuthor()
*函数功能： 获取图书作者
*
*函数参数：  void
*函数返回值：Author
**********************************************************/
string Book::GetAuthor()
{
    return Author;
}
/*********************************************************
*函数名：    SetAuthor()
*函数功能：  对图书作者进行修改
*
*函数参数：  string author     //图书作者
*函数返回值: Author
*********************************************************/
string Book::SetAuthor(string author)
{
    this->Author = author;
    return Author;
}



/*********************************************************
*函数名：   GetPublisher()
*函数功能： 获取图书出版商
*
*函数参数：  void
*函数返回值：Publisher
**********************************************************/
string Book::GetPublisher()
{
    return Publisher;
}
/*********************************************************
*函数名：    SetPublisher()
*函数功能：  对图书出版商进行修改
*
*函数参数：  string publisher     //图书出版商
*函数返回值: Publisher
*********************************************************/
string Book::SetPublisher(string publisher)
{
    this->Publisher = publisher;
    return Publisher;
}



/*********************************************************
*函数名：   GetDate()
*函数功能： 获取图书出版日期
*
*函数参数：  void
*函数返回值：Date
**********************************************************/
string Book::GetDate()
{
    return Date;
}
/*********************************************************
*函数名：    SetDate()
*函数功能：  对图书日期进行修改
*
*函数参数：  string date     //图书日期
*函数返回值: Date
*********************************************************/
string Book::SetDate(string date)
{
    this->Date = date;
    return Date;
}



/*********************************************************
*函数名：   GetPrice()
*函数功能： 获取图书价格
*
*函数参数：  void
*函数返回值：Price
**********************************************************/
float Book::GetPrice()
{
    return Price;
}
/*********************************************************
*函数名：    SetPrice()
*函数功能：  对图书价格进行修改
*
*函数参数：  float  price      //图书价格
*函数返回值: Price
*********************************************************/
float Book::SetPrice(float price)
{
    this->Price = price;
    return Price;
}



/*********************************************************
*函数名：   GetCatalogNum()
*函数功能： 获取图书分类编号
*
*函数参数：  void
*函数返回值：CatalogNum
**********************************************************/
string Book::GetCatalogNum()
{
    return CatalogNum;
}
/*********************************************************
*函数名：    SetCatalogNum()
*函数功能：  对图书分类编号进行修改
*
*函数参数：  string  catalognum    //图书分类编号
*函数返回值: CatalogNum
*********************************************************/
string Book::SetCatalogNum(string catalognum)
{
    this->CatalogNum = catalognum;
    return CatalogNum;
}



/*********************************************************
*函数名：   GetNumber()
*函数功能： 获取图书数量
*
*函数参数：  void
*函数返回值：Number
**********************************************************/
int Book::GetNumber()
{
    return Number;
}
/*********************************************************
*函数名：    SetNumber()
*函数功能：  对图书数量进行修改
*
*函数参数：  int  number       //图书数量
*函数返回值: Number
*********************************************************/
int Book::SetNumber(int number)
{
    this->Number = number;
    return Number;
}



/*********************************************************
*函数名：    Print()
*函数功能：  输入单个图书的全部信息
*
*函数参数：  void
*函数返回值：void
*********************************************************/
void Book::Print()
{
    cout <<  GetISBN()  << '\t'  << GetTitle() << '\t';
    cout << GetAuthor() << '\t'  << GetPublisher() << '\t';
    cout << GetDate() << '\t' << GetPrice();
    cout << setw(10) << GetCatalogNum() << setw(11) << GetNumber() << endl;
}



/****************************************************************
*函数名：    AddBook()
*函数功能：  添加读者信息
*
*函数参数：  Book容器作为函数参数：vector<Book> &Book_vec
*
*函数返回值：void
*****************************************************************/
void Book::AddBook(vector<Book> &Book_vec)
{
    cout << "\n\n\t\t\t\t添加图书信息\n\n" << endl;
    //图书ISBN编号
    string isbn;
    //图书名称
    string title;
    //图书作者
    string author;
    //图书出版商
    string publisher;
    //图书出版日期
    string date;
    //图书价格
    float  price;
    //图书分类编号
    string catalognum;
    //图书数量
    int number;

    //用户输入选择
    char reply;
    do{
        cout << "\n请输入图书的ISBN编号：";
        cin  >> isbn;
        cout << "请输入图书的名称：";
        cin  >> title;
        cout << "请输入图书的作者：";
        cin  >> author;
        cout << "请输入图书的出版商：";
        cin  >> publisher;
        cout << "请输入图书的出版日期：";
        cin  >> date;
        cout << "请输入图书的价格：";
        //缓冲Enter键
        cin.get();
        cin  >> price;
        cout << "请输入图书的分类编号：";
        cin  >> catalognum;
        cout << "请输入图书的数量：";
        cin  >> number;

        //创建对象object,并调用构造函数
        Book object(isbn, title, author, publisher, date, price, catalognum, number);
        //将创建的图书信息送入Book容器中
        Book_vec.push_back(object);

        cout << "你想继续输入吗？（(Y/h)/(N/n)）：";
        cin.get();
        cin.get(reply);
        }while(reply == 'Y' || reply == 'y');

    cout << "\n是否保存输入的信息？（(Y/y) / (N/n)）：";
    char choose;
    //缓冲Enter键
    cin.get();
    cin.get(choose);
    if (choose == 'Y' || choose == 'y')
    {
        //调用SaveBookApp()函数，保存图书信息到book.txt文件中
        SaveBookApp(Book_vec);
    }
    else
    {
        cout << "\n\t\t\t文件没有保存！" << endl;
    }
}



/******************************************************************
*函数名：    BrowseBook()
*函数功能：  浏览读者信息
*
*函数参数：  Book容器作为函数参数：vector<Book> &Book_vec
*函数返回值：void
*******************************************************************/
void Book::BrowseBook(vector<Book> &Book_vec)
{
    cout << "\n\n\t\t\t\t\t\t浏览图书信息\n\n" << endl;
    cout << "==========================================================================================================\n" << endl;
    cout << "ISBN\t\t名称\t\t作者\t\t出版商\t\t出版日期\t价格\t分类编号\t数量\n" << endl;
    cout << "==========================================================================================================\n" << endl;

    //定义迭代器 B，用来遍历和输出图书信息
    vector<Book>::iterator B = Book_vec.begin();
    while (B != Book_vec.end())
    {
        //调用Print()函数，输出图书信息
        (*B).Print();
        B++;
    }
    cout << "\n==========================================================================================================\n" << endl;
}



/******************************************************************
*函数名：    ModifyBook()
*函数功能：  修改图书信息
*
*函数参数：  Book容器作为函数参数：vector<Book> &Book_vec
*函数返回值：void
******************************************************************/
void Book::ModifyBook(vector<Book> &Book_vec)
{
    cout << "\n\n\t\t\t\t\t\t修改图书信息\n\n" << endl;
    //定义标志变量
    int flag = 0;
    //图书ISBN编号
    string isbn;
    //图书名称
    string title;
    //图书作者
    string author;
    //图书出版商
    string publisher;
    //图书出版日期
    string date;
    //图书价格
    float price;
    //图书分类编号
    string catalognum;
    //图书数量
    int  number;

    cout << "请输入要修改的图书ISBN编号：";
    //缓冲Enter键
    cin.get();
    cin >> isbn;

    //定义迭代器 B，用来遍历、查找和修改图书信息
    vector<Book>::iterator B = Book_vec.begin();
    while (B != Book_vec.end())
    {
        if( B -> GetISBN() == isbn )
        {
            //flag = 1表示修改图书信息成功
            flag = 1;
            cout << "您要修改的图书信息：" << endl;
            cout << "==========================================================================================================\n" << endl;
            cout << "ISBN\t\t名称\t\t作者\t\t出版商\t\t出版日期\t价格\t分类编号\t数量\n" << endl;
            cout << "==========================================================================================================\n" << endl;

            //调用Print()函数，输出图书信息
            (*B).Print();

            cout << "请输入图书的ISBN编号：";
            cin  >> isbn;
            cout << "请输入图书的名称：";
            cin  >> title;
            cout << "请输入图书的作者：";
            cin  >> author;
            cout << "请输入图书的出版商：";
            cin  >> publisher;
            cout << "请输入图书的出版日期：";
            cin  >> date;
            cout << "请输入图书的价格：";
            //缓冲Enter键
            cin.get();
            cin  >> price;
            cout << "请输入图书的分类编号：";
            cin  >> catalognum;
            cout << "请输入图书的数量：";
            cin  >> number;

            B->SetISBN(isbn);
            B->SetTitle(title);
            B->SetAuthor(author);
            B->SetPublisher(publisher);
            B->SetDate(date);
            B->SetPrice(price);
            B->SetCatalogNum(catalognum);
            B->SetNumber(number);

            cout << "\n\t\t\t修改成功！" << endl;
            cout << "\n==========================================================================================================\n" << endl;
            break;
        }
        B++;
    }
    if(!flag)
    {
        cout << "\n\t\t\t修改失败！\n" << endl;
    }

    //调用SaveBook()函数，保存修改后的信息到book.txt文件中。
    SaveBook(Book_vec);
}



/******************************************************************
*函数名：    DeleteBook()
*函数功能：  删除读者信息
*
*函数参数：  Book容器作为函数参数：vector<Book> &Book_vec
*函数返回值：void
*******************************************************************/
void Book::DeleteBook(vector<Book> &Book_vec)
{
    cout << "\n\n\t\t\t\t\t\t删除图书信息\n\n" << endl;
    //定义标志变量
    int flag = 0;
    //要删除图书信息的ISBN编号
    string isbn;

    cout << "请输入要删除的图书ISBN编号：";
    //缓冲Enter键
    cin.get();
    cin >> isbn;

    //定义迭代器 B，用来遍历、查找和删除图书信息
    vector<Book>::iterator B = Book_vec.begin();
    while (B != Book_vec.end())
    {
        if( B -> GetISBN() == isbn )
        {
            flag=1;       //flag = 1表示图书信息删除成功
            cout << "您要删除的图书信息：" << endl;
            cout << "==========================================================================================================\n" << endl;
            cout << "ISBN\t\t名称\t\t作者\t\t出版商\t\t出版日期\t价格\t分类编号\t数量\n" << endl;
            cout << "==========================================================================================================\n" << endl;

            //调用Print()函数，输出图书信息
            (*B).Print();

            //释放指向该图书信息的迭代器，也即删除该图书的信息
            Book_vec.erase(B++);
            cout << "\n\t\t\t删除成功！" << endl;
            cout << "\n==========================================================================================================\n" << endl;
            break;
        }
        else
        {
            B++;
        }
    }
    if(!flag)
    {
        cout << "\n\t\t\t删除失败！\n" << endl;
    }

    //调用SaveBook()函数，保存删除图书后的信息到book.txt文件中
    SaveBook(Book_vec);
}



/******************************************************************
*函数名：    FindBookByISBN()
*函数功能：  根据图书的ISBN编号来查找图书信息
*
*函数参数：  Book容器作为函数参数：vector<Book> &Book-vec
*函数返回值：void
******************************************************************/
void Book::FindBookByISBN(vector<Book> &Book_vec)
{
    cout << "\n\n\t\t\t\t\t\t根据图书ISBN编号图书信息\n\n" << endl;
    //定义标志变量
    int flag = 0;
    //要查询图书的ISBN编号
    string isbn;

    cout << "请输入您要查询图书ISBN编号：";
    //缓冲Enter键
    cin.get();
    cin >> isbn;

    //定义迭代器 B，用来遍历、查找图书信息
    vector<Book>::iterator B = Book_vec.begin();
    while (B != Book_vec.end())
    {
        if( B -> GetISBN() == isbn )
        {
            //flag = 1表示找到读者信息
            flag = 1;
            cout << "==========================================================================================================\n" << endl;
            cout << "ISBN\t\t名称\t\t作者\t\t出版商\t\t出版日期\t价格\t分类编号\t数量\n" << endl;
            cout << "==========================================================================================================\n" << endl;

            //调用Print()函数，输出图书信息
            (*B).Print();
            cout << "\n==========================================================================================================\n" << endl;
            break;
        }
        B++;
    }

    if (!flag)
    {
        cout << "\n\t\t\t没有此图书的信息！\n" << endl;
    }
}



/******************************************************************
*函数名：    FindBookByTitle()
*函数功能：  根据图书名称来查找图书信息
*
*函数参数：  Book容器作为函数参数：vector<Book> &Book-vec
*函数返回值：void
******************************************************************/
void Book::FindBookByTitle(vector<Book> &Book_vec)
{
    cout << "\n\n\t\t\t\t\t\t根据图书名称图书信息\n\n" << endl;
    //定义标志变量
    int flag = 0;
    //要查询图书的名称
    string title;

    cout << "请输入您要查询图书名称：";
    //缓冲Enter键
    cin.get();
    cin  >> title;

    //定义迭代器 B，用来遍历、查找图书信息
    vector<Book>::iterator B = Book_vec.begin();
    while (B != Book_vec.end())
    {
        if( B -> GetTitle() == title )
        {
            //flag = 1表示找到读者信息
            flag = 1;
            cout << "==========================================================================================================\n" << endl;
            cout << "ISBN\t\t名称\t\t作者\t\t出版商\t\t出版日期\t价格\t分类编号\t数量\n" << endl;
            cout << "==========================================================================================================\n" << endl;

            //调用Print()函数，输出图书信息
            (*B).Print();
            cout << "\n==========================================================================================================\n" << endl;
            break;
        }
        B++;
    }

    if (!flag)
    {
        cout << "\n\t\t\t没有此图书的信息！\n" << endl;
    }
}



/******************************************************************
*函数名：    FindBookByPublisher()
*函数功能：  根据图书出版商来查找图书信息
*
*函数参数：  Book容器作为函数参数：vector<Book> &Book-vec
*函数返回值：void
******************************************************************/
void Book::FindBookByPublisher(vector<Book> &Book_vec)
{
    cout << "\n\n\t\t\t\t\t\t根据图书出版商查找图书信息\n\n" << endl;
    //定义标志变量
    int flag = 0;
    //要查询图书的名称
    string author;

    cout << "请输入您要查询图书作者：";
    //缓冲Enter键
    cin.get();
    cin >> author;

    //定义迭代器 B，用来遍历、查找图书信息
    vector<Book>::iterator B = Book_vec.begin();
    while (B != Book_vec.end())
    {
        if( B -> GetAuthor() == author )
        {
            //flag = 1表示找到读者信息
            flag = 1;
            cout << "==========================================================================================================\n" << endl;
            cout << "ISBN\t\t名称\t\t作者\t\t出版商\t\t出版日期\t价格\t分类编号\t数量\n" << endl;
            cout << "==========================================================================================================\n" << endl;

            //调用Print()函数，输出图书信息
            (*B).Print();
            cout << "\n==========================================================================================================\n" << endl;
            break;
        }
        B++;
    }

    if (!flag)
    {
        cout << "\n\t\t\t没有此图书的信息！\n" << endl;
    }
}



/******************************************************************
*函数名：    FindBookByAuthor()
*函数功能：  根据图书作者来查找图书信息
*
*函数参数：  Book容器作为函数参数：vector<Book> &Book-vec
*函数返回值：void
******************************************************************/
void Book::FindBookByAuthor(vector<Book> &Book_vec)
{
    cout << "\n\n\t\t\t\t\t\t根据图书作者查找图书信息\n\n" << endl;
    //定义标志变量
    int flag = 0;
    //要查询图书的名称
    string publisher;

    cout << "请输入您要查询图书的出版商：";
    //缓冲Enter键
    cin.get();
    cin >> publisher;

    //定义迭代器 B，用来遍历、查找图书信息
    vector<Book>::iterator B = Book_vec.begin();
    while (B != Book_vec.end())
    {
        if( B -> GetPublisher() == publisher )
        {
            //flag = 1表示找到读者信息
            flag = 1;
            cout << "==========================================================================================================\n" << endl;
            cout << "ISBN\t\t名称\t\t作者\t\t出版商\t\t出版日期\t价格\t分类编号\t数量\n" << endl;
            cout << "==========================================================================================================\n" << endl;

            //调用Print()函数，输出图书信息
            (*B).Print();
            cout << "\n==========================================================================================================\n" << endl;
            break;
        }
        B++;
    }

    if (!flag)
    {
        cout << "\n\t\t\t没有此图书的信息！\n" << endl;
    }
}



/******************************************************************
*函数名：    SaveBook()
*函数功能：  以重写的方式，保存读者信息到book.txt文件中。
*
*函数参数：  Book容器作为函数参数：vector<Book> &Book_vec
*函数返回值：void
******************************************************************/
void Book::SaveBook(vector<Book> &Book_vec)
{
    //创建book.txt文件。
    ofstream out ("book.txt", ios::out);

    //判读文件是否创建成功
    if (!out)
    {
        cout << "\n\t\t\t文件创建失败！";
        exit(0);
    }

    //定义迭代器 B，用来遍历和输出读者信息
    vector<Book>::iterator B;
    for (B = Book_vec.begin(); B != Book_vec.end(); B++)
    {
        out << B->GetISBN() << '\t' << B->GetTitle() << '\t';
        out << B->GetAuthor() << '\t' << B->GetPublisher() << '\t';
        out << B->GetDate() << '\t' << B->GetPrice() << '\t';
        out << B->GetCatalogNum() << '\t' << B->GetNumber() << endl;
    }

    //关闭文件
    out.close();
}



/******************************************************************
*函数名：    SaveBookApp()
*函数功能：  以添加到文件尾方式，保存读者信息到book.txt文件中。
*
*函数参数：  Book容器作为函数参数：vector<Book> &Book_vec
*函数返回值：void
******************************************************************/
void Book::SaveBookApp(vector<Book> &Book_vec)
{
    //创建book.txt文件。
    ofstream out ("book.txt", ios::out | ios::app);

    //判读文件是否创建成功
    if (!out)
    {
        cout << "\n\t\t\t文件创建失败！";
        exit(0);
    }

    //定义迭代器 B，用来遍历和输出读者信息
    vector<Book>::iterator B;
    for (B = Book_vec.begin(); B != Book_vec.end(); B++)
    {
        out << B->GetISBN()   << '\t' << B->GetTitle()      << '\t';
        out << B->GetAuthor() << '\t' << B->GetPublisher()  << '\t';
        out << B->GetDate()   << '\t' << B->GetPrice()      << '\t';
        out << B->GetCatalogNum() << '\t' << B->GetNumber() << endl;
    }

    //关闭文件
    out.close();
}



/******************************************************************
*函数名：    ReadFileToBookVector()
*函数功能：  读取文件信息到Book容器中,供其他函数调用容器数据。
*
*函数参数：  Book容器作为函数参数：vector<Book> &Book_vec
*函数返回值：void
******************************************************************/
void Book::ReadFileToBookVector(vector<Book> &Book_vec)
{
    //图书ISBN编号
    string isbn;
    //图书名称
    string title;
    //图书作者
    string author;
    //图书出版商
    string publisher;
    //图书出版日期
    string date;
    //图书价格
    float price;
    //图书分类编号
    string catalognum;
    //图书数量
    int number;

    //读取文件信息
    ifstream in("book.txt", ios::in);
    //判读文件打开是否成功
    if (!in)
    {
        cout << "\n\t\t\t文件打开失败";
        exit(0);
    }

    //先进行读者信息的读取后放进Book容器，防止最后一条信息遗漏
    in >> isbn >>  title >>  author >> publisher >> date >> price >> catalognum >> number;
    while (!in.eof())
    {
        //创建读者对象object,并调用Book()构造函数。
        Book object(isbn, title, author, publisher, date, price, catalognum, number);

        //读取后的读者信息放入Book容器中
        Book_vec.push_back(object);
        in >> isbn >>  title >>  author >> publisher >> date >> price >> catalognum >> number;
    }

    //关闭文件
    in.close();
}



/**************************************************
*函数名：    ~Book()
*函数功能：  对象生存期结束时，系统调用析构函数
*
*
*函数参数：  无
**************************************************/
Book::~Book()
{}
