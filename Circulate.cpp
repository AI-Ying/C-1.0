/********************************************************************************
*
*Copyright(c)2015,南昌大学软件学院实验小组(张欢，王沛然，闫致敬)
*All rights reserved.
*
*文件名称： Circulate.cpp
*文件标识： 见配置管理计划书
*
*摘    要： 本文件主要包括对图书流通功能函数的实现。在实现的方式用的是采用链表
*            形式，使用链表，在数据进行插入、删除上效率更高。
*
*
*当前版本：1.0
*作者：闫致敬
*完成日期：2015/6/10
*第一次修改：2015/6/14
*第二次修改：2015/6/20
*
**********************************************************************************/


#include "Circulate.h"     //引用非标准库函数




/******************************************************************
*函数名：    ReaderBorrow()
*函数功能：  读者借阅图书功能
*
*函数参数：  Reader容器作为函数参数：vector<Reader> &Reader_vec
*函数返回值：void
*******************************************************************/
void Circulate::ReaderBorrow(vector<Reader> &Reader_vec)
{
    cout << "\n\n\t\t读者借书\n\n" << endl;
    //读者证件号
    string code;

    cout << "请输入借阅读者的证件号：";
    cin >> code;
    //定义标志变量flag
    int flag = 0;
    //定义标志变量flag1
    int flag1 = 0;
    //创建一个读者对象
    Reader reader;
    //创建一个图书对象
    Book book;


    //定义迭代器 R，用来遍历、查找和挂失读者信息
    vector<Reader>::iterator R = Reader_vec.begin();
    while (R != Reader_vec.end())
    {
        if( R -> GetCode() == code )
        {
            //flag = 1表示读者信息挂失成功
            flag = 1;

            cout << "=================================================================================" << endl;
            cout << "姓名\t性别\t证件号\t\t工作单位\t\t挂失状态\t借书本数" << endl;
            cout << "=================================================================================\n" << endl;
            //调用Print()函数，输出读者信息
            (*R).Print();
            cout << "\n=================================================================================\n\n" << endl;
            if (R->GetTag() == 1)
            {
                cout << "\n\t\t\t该读者已挂失，无法借阅图书！\n" << endl;
                break;
            }

            else if (R->GetNumber() >= MAX_BOOK)
            {
                cout << "\n\t\t\t该读者借阅图书已超过6本，无法借阅！\n" << endl;
                break;
            }
            else
            {
                //flag=1；找到读者
                flag1 = 1;
                //创建一个图书容器Book_vec
                vector<Book> Book_vec;
                //从book.txt文件中读取数据到Book_vec容器中
                book.ReadFileToBookVector(Book_vec);

                //图书ISBN编号
                string isbn;
                cout << "请输入图书ISBN编号：" << endl;
                cin >> isbn;
                //定义一个迭代器B,用来遍历、查找图书信息
                vector<Book>::iterator B = Book_vec.begin();
                while (B != Book_vec.end())
                {
                    if( B -> GetISBN() == isbn )
                    {
                        if (B->GetNumber() == 0)
                        {
                            cout << "\n\t\t\t该图书库存为0， 暂时无法借阅！\n" << endl;
                            break;
                        }
                        else
                        {
                            //flag1=1表示找到图书信息
                            flag1 = 1;

                            cout << "==========================================================================================================\n" << endl;
                            cout << "ISBN\t\t名称\t\t作者\t\t出版商\t\t出版日期\t价格\t分类编号\t数量\n" << endl;
                            cout << "==========================================================================================================\n" << endl;

                            //调用Print()函数，输出图书信息
                            (*B).Print();
                            cout << "\n==========================================================================================================\n" << endl;

                            //获取图书数量
                            int BookNumber = B->GetNumber();
                            //调用SetNumber()函数，借书成功后，图书数量自动减一
                            B->SetNumber( BookNumber-1 );
                            //调用SaveBook()函数，保存挂失后的读者信息到reader.txt文件中
                            book.SaveBook(Book_vec);

                            //获取读者借书数量
                            int ReaderNumber = R->GetNumber();
                            //调用SetNumber()函数，借书成功后，读者借书数量自动加一
                            R->SetNumber(ReaderNumber+1);
                            //调用SaveReader()函数，保存借阅后的读者信息到reader.txt文件中
                            reader.SaveReader(Reader_vec);

                            //创建一个读者借阅信息对象borrow
                            Circulate borrow;
                            //保存读者借阅信息
                            borrow.SaveBorrowB(code, isbn);
                            cout << "\n\t\t\t借阅成功！\n" << endl;
                            break;
                        }
                    }
                    B++;
                }
                if (!flag1)
                {
                    cout << "\n\t\t\t此图书信息不存在！\n" << endl;
                }
            }

        }R++;
    }
    if(!flag)
    {
        cout << "\n\t\t\t读者信息不存在，借阅失败！\n" << endl;
    }
}



/******************************************************************
*函数名：    SaveBorrowB()
*函数功能：  保存读者借阅信息
*
*函数参数：  读者证件号：Code
*             图书ISBN编号：isbn
*函数返回值：void
*******************************************************************/
void Circulate::SaveBorrowB(string Code, string ISBN)
{
    //借阅读者证件号
    L.Code.assign(Code);
    //借阅图书的ISBN编号
    L.ISBN.assign(ISBN);

    //定义一个时间变量
    time_t t;
    //获取系统当前时间
    t = time(NULL);
    //定义日历时间结构体
    tm borrowDate, lastDate;
    //把系统时间转化为日历时间
    borrowDate = *localtime(&t);
    int year, month, day;
    day = borrowDate.tm_mday;
    month = borrowDate.tm_mon + 1;
    year = borrowDate.tm_year + 1900;

    //读者借阅图书时间
    L.BorrowDate.Year = year;
    L.BorrowDate.Month = month;
    L.BorrowDate.Day = day;

    //计算图书应还日期
    t = t + MAX_DAY * 86400; //24*60*60

    //把系统时间转化为日历时间
    lastDate = *localtime(&t);
    int year1, month1, day1;
    day1 = lastDate.tm_mday;
    month1 = lastDate.tm_mon + 1;
    year1 = lastDate.tm_year + 1900;

    //读者应还日期
    L.LastDate.Year = year1;
    L.LastDate.Month = month1;
    L.LastDate.Day = day1;

    //初始化读者实际还书日期
    L.ReturnDate.Year  = 0;
    L.ReturnDate.Month = 0;
    L.ReturnDate.Day   = 0;

    //初始化读者借阅
    L.Tag = "借出";
    //定义一个文件对象out，保存读者借阅信息到文件borrow.txt中
    ofstream out ("borrow.txt", ios::out | ios::app);
    if (!out)
    {
        cout << "\n\t\t\t创建文件失败！\n" << endl;
        exit(0);
    }
    out << L.Code << "\t" << L.ISBN << "\t";
    out << L.BorrowDate.Year << " " << L.BorrowDate.Month << " " << L.BorrowDate.Day << "\t";
    out << L.LastDate.Year   << " " << L.LastDate.Month   << " " << L.LastDate.Day   << "\t";
    out << L.ReturnDate.Year << " " << L.ReturnDate.Month << " " << L.ReturnDate.Day << "\t\t";
    out << L.Tag << endl;

    //文件关闭
    out.close();
}



/********************************************************************
*函数名：    CreatBorrowLink()
*函数功能：  读取borrow.txt文件，并创建一个图书流通的链表
*
*函数参数：  无
*
*函数返回值：以头指针的形式的链表：head
*********************************************************************/
BorrowLink* Circulate::CreatBorrowLink()
{
    //定义结构体指针*head, *p, *q;
    BorrowLink *head, *p, *q;
    //使用指针前，对指针初始化为空
    head = NULL;
    q = NULL;
    p = NULL;

    //定义文件对象 in, 并打开文件
    ifstream in ("borrow.txt", ios::in);
    if(!in)
    {
        cout << "\n\t\t\t打开文件失败！\n";
        exit(0);
    }

    //对链表的头指针head申请一个BookCatalongLink大小的动态空间
    head = new BorrowLink;
    //把头指针head的地址赋值给p
    p = head;
    while (!in.eof())
    {
        //对链表的指针q申请一个BookCatalongLink大小的动态空间
        q = new BorrowLink;
        in >> q->Code >> q->ISBN;
        in >> q->BorrowDate.Year >> q->BorrowDate.Month  >> q->BorrowDate.Day;
        in >> q->LastDate.Year   >> q->LastDate.Month    >> q->LastDate.Day;
        in >> q->ReturnDate.Year >> q->ReturnDate.Month  >> q->ReturnDate.Day;
        in >> q->Tag;

        //前一个指针p的指针域指向当前指针q
        p -> next = q;
        //把当前指针q的地址赋值给前一个指针p
        p = q;
    }
   //把链表最后一个指针的指针域置空
    p -> next = NULL;

    //关闭文件
    in.close();
    //返回链表的头指针
    return head;
}



/******************************************************************
*函数名：    ReaderReturn()
*函数功能：  读者还书功能
*
*函数参数：  Reader容器作为函数参数：vector<Reader> &Reader_vec
*函数返回值：void
*******************************************************************/
void Circulate::ReaderReturn(vector<Reader> &Reader_vec)
{
    cout << "\n\n\t\t\t读者还书\n\n" << endl;
    //借阅读者的证件号
    string code;
    //借阅图书的ISBN编号
    string isbn;
    //图书的借阅状态
    string tag = "借出";
    //定义一个标志变量
    int flag = 0;

    //创建一个读者对象 Reader
    Reader reader;
    //创建一个图书对象
    Book book;

    //定义结构体指针*head, *p, *q;
    BorrowLink *head, *p;
    //使用指针前，对指针初始化为空
    head = NULL;
    p = NULL;


    //定义一个时间变量
    time_t t;
    //获取系统当前时间
    t = time(NULL);
    //定义日历时间结构体
    tm returnDate;
    //把系统时间转化为日历时间
    returnDate = *localtime(&t);
    int year, month, day;
    day = returnDate.tm_mday;
    month = returnDate.tm_mon + 1;
    year = returnDate.tm_year + 1900;

    //创建一个链表
    head = CreatBorrowLink();

    cout << "请输入要还书的读者证件号：";
    cin >> code;
    cout << "请输入读者要还的书的ISBN编号：";
    cin >> isbn;
    cout << "============================================================================================" << endl;
    cout << "读者证件号" << "\t" << "图书ISBN编号" << "\t" << "借书日期" << "\t" << "应当归还日期" << "\t" << "还书日期" << '\t' << "借阅状态" << endl;
    cout << "============================================================================================\n" << endl;

    //把头指针head的指针域地址赋值给指针p
    p = head ->next;
    while (p != NULL)
    {
        //判断借阅读者信息存在是否存在，且判断读者是否没有挂失
        if (code.compare(p->Code) == 0 && isbn.compare(p->ISBN) == 0 && tag.compare(p->Tag) == 0)
        {
            //flag = 1;表示找到该借阅信息
            flag = 1;

            //定义迭代器 R，用来遍历、查找和挂失读者信息
            vector<Reader>::iterator R = Reader_vec.begin();
            while (R != Reader_vec.end())
            {
                if (code.compare(R->GetCode()) == 0)
                {
                    //创建一个图书容器Book_vec
                     vector<Book> Book_vec;
                     //读取图书信息到容器Book_vec中
                     book.ReadFileToBookVector(Book_vec);
                     //定义一个迭代器B,用来查找、修改图书信息
                     vector<Book>::iterator B = Book_vec.begin();
                     while (B != Book_vec.end())
                     {
                         if (isbn.compare(B->GetISBN()) == 0)
                         {
                             //获取图书数量
                             int BookNumber = B->GetNumber();
                             //调用SetNumber()函数，还书成功时，图书数量自动加一
                             B->SetNumber( BookNumber+1 );
                             //调用SaveBook()函数，保存挂失后的读者信息到reader.txt文件中
                             book.SaveBook(Book_vec);

                             //获取读者借阅图书数量
                             int ReaderNumber = R->GetNumber();
                             //调用SetNumber()函数，还书成功时，读者借阅图书数量自动减一
                             R->SetNumber(ReaderNumber-1);
                             //调用SaveReader()函数，保存还书后的读者信息到reader.txt文件中
                             reader.SaveReader(Reader_vec);
                         }
                         B++;
                     }
                }
                R++;
            }
            cout << p->Code << "\t" << p->ISBN << "\t";
            cout << p->BorrowDate.Year << "-" << p->BorrowDate.Month << "-" << p->BorrowDate.Day << "\t";
            cout << p->LastDate.Year   << "-" << p->LastDate.Month   << "-" << p->LastDate.Day   << "\t";
            cout << p->ReturnDate.Year << "-" << p->ReturnDate.Month << "-" << p->ReturnDate.Day << "\t\t";
            cout << p->Tag << endl;


            //借阅读者证件号
            L.Code.assign(code);
            //借阅图书的ISBN编号
            L.ISBN.assign(isbn);

            //读者实际还书时间
            p->ReturnDate.Year = year;
            p->ReturnDate.Month = month;
            p->ReturnDate.Day = day;

            //修改读者借阅状态
            p->Tag = "已还";
            cout << "\n\t\t\t读者还书成功！\n" << endl;
        }
        //链表指针向后移一位
        p = p->next;
    }

    //创建文件对象，保存还书后的信息到borrow.txt文件中
    ofstream out ("borrow.txt", ios::out );
    if (!out)
    {
        cout << "\n\t\t\t文件打开失败！\n" << endl;
        exit(0);
    }

    //遍历读者借阅信息链表，并把还书后的信息写入到borrow.txt文件中
    for (p = head->next; p->next != NULL; p = p -> next)
    {
        out << p->Code << "\t" << p->ISBN << "\t";
        out << p->BorrowDate.Year << " " << p->BorrowDate.Month << " " << p->BorrowDate.Day << "\t";
        out << p->LastDate.Year   << " " << p->LastDate.Month   << " " << p->LastDate.Day   << "\t";
        out << p->ReturnDate.Year << " " << p->ReturnDate.Month << " " << p->ReturnDate.Day << "\t\t";
        out << p->Tag << endl;
    }

    //关闭文件
    out.close();

    if (!flag)
    {
        cout << "\n\t\t\t读者信息不存在，或者没有借阅！\n" << endl;
    }

    cout << "\n============================================================================================\n\n" << endl;
    //释放读者借阅信息链表指针
    DeleteMemory(head);
}



/********************************************************************
*函数名：    FindBorrow()
*函数功能：  查询借阅图书的相关信息
*
*函数参数：  无
*
*函数返回值：void
*********************************************************************/
void Circulate::FindBorrow()
{
    cout << "\n\n\t\t\t查询读者借阅记录\n\n" << endl;
    //读者证件号
    string code;
    //定义结构体指针*head, *p, *q;
    BorrowLink *head, *p;
    //使用指针前，对指针初始化为空
    head = NULL;
    p = NULL;
    //定义flag标志变量
    int flag = 0;
    cout << "请输入要查询的读者证件号：";
    cin >> code;


    //创建一个链表
    head = CreatBorrowLink();

    cout << "============================================================================================" << endl;
    cout << "读者证件号" << "\t" << "图书ISBN编号" << "\t" << "借书日期" << "\t" << "应当归还日期" << "\t" << "还书日期" << '\t' << "借阅状态" << endl;
    cout << "============================================================================================\n" << endl;
    for (p = head->next; p != NULL; p = p -> next)
    {
        if (code.compare(p->Code) == 0)
        {
            flag = 1;
            cout << p->Code << "\t" << p->ISBN << "\t";
            cout << p->BorrowDate.Year << "-" << p->BorrowDate.Month << "-" << p->BorrowDate.Day << "\t";
            cout << p->LastDate.Year   << "-" << p->LastDate.Month   << "-" << p->LastDate.Day   << "\t";
            cout << p->ReturnDate.Year << "-" << p->ReturnDate.Month << "-" << p->ReturnDate.Day << "\t\t";
            cout << p->Tag << endl;
        }
    }
    if (!flag)
    {
        cout << "\n该读者不存在或者没有借阅书籍！" << endl;
    }
    cout << "\n============================================================================================\n\n" << endl;

    //释放链表指针
    DeleteMemory(head);
}

/********************************************************************
*函数名：    DeleteMemory()
*函数功能：  释放图书借阅信息的链表指针
*
*函数参数：  以头指针的形式的链表：BorrowLink *head
*
*函数返回值：void
*********************************************************************/
void Circulate::DeleteMemory(BorrowLink *head)
{
    //定义结构体指针*p, *q;
    BorrowLink *p, *q;
    //使用指针前，对指针初始化为空
    q = NULL;
    p = NULL;

    //把头指针head的地址复制给指针p
    p = head;
    //遍历链表
    while (p -> next != NULL)
    {
        //把当前指针的地址赋值给指针q
        q = p;
        //把下一个指针p的指针域复制给当前指针指针p
        p = p -> next;
        //删除指针q
        delete q;
    }
}
