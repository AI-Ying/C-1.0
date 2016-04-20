/********************************************************************************
*
*Copyright(c)2015,�ϲ���ѧ���ѧԺʵ��С��(�Ż�������Ȼ�����¾�)
*All rights reserved.
*
*�ļ����ƣ� Book.cpp
*�ļ���ʶ�� �����ù���ƻ���
*
*ժ    Ҫ�� ���ļ���Ҫ�Ƕ�ͼ���Ŀ�����ܺ�����ʵ�֡��ڶ�ͼ�������
*            ���в���ʱ��ʹ������������vector�������������ڸ�������
*            ֮��ĵ��ã�Ҳ��������⡣
*
*
*��ǰ�汾��1.0
*���ߣ��Ż�
*������ڣ�2015/6/5
*��һ���޸ģ�2015/6/8
*�ڶ����޸ģ�2015/6/16
*
**********************************************************************************/

#include  "Book.h"            //���÷Ǳ�׼�⺯��





/***************************************************
*��������    Book()
*�������ܣ�  ��������û�г�ʼ���������޲ι��캯��
*
*����������  ��
***************************************************/
Book::Book()
{}



/**************************************************
*��������    Book()
*�������ܣ�  ���캯�����Զ�����г�ʼ����
*
*
*��������:
*            string isbn         //ͼ��ISBN���
*            string title        //ͼ������
*            string author       //ͼ������
*            string publisher    //������
*            string date         //��������
*            float  price        //ͼ��۸�
*            string catalognum   //ͼ�������
*            int    number       //ͼ������
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
*��������   GetISBN()
*�������ܣ� ��ȡͼ��ISBN���
*
*����������  void
*��������ֵ��ISBN
**********************************************************/
string Book::GetISBN()
{
    return ISBN;
}
/*********************************************************
*��������    SetISBN()
*�������ܣ�  �Զ������������޸�
*
*����������  string isbn    //ͼ��ISBN���
*��������ֵ: ISBN
*********************************************************/
string Book::SetISBN(string isbn)
{
    this->ISBN = isbn;
    return ISBN;
}



/*********************************************************
*��������   GetTitle()
*�������ܣ� ��ȡͼ������
*
*����������  void
*��������ֵ��Title
**********************************************************/
string Book::GetTitle()
{
    return Title;
}
/*********************************************************
*��������    SetTitle()
*�������ܣ�  ��ͼ�����ƽ����޸�
*
*����������  string title     //ͼ������
*��������ֵ: Title
*********************************************************/
string Book::SetTitle(string title)
{
    this->Title = title;
    return Title;
}



/*********************************************************
*��������   GetAuthor()
*�������ܣ� ��ȡͼ������
*
*����������  void
*��������ֵ��Author
**********************************************************/
string Book::GetAuthor()
{
    return Author;
}
/*********************************************************
*��������    SetAuthor()
*�������ܣ�  ��ͼ�����߽����޸�
*
*����������  string author     //ͼ������
*��������ֵ: Author
*********************************************************/
string Book::SetAuthor(string author)
{
    this->Author = author;
    return Author;
}



/*********************************************************
*��������   GetPublisher()
*�������ܣ� ��ȡͼ�������
*
*����������  void
*��������ֵ��Publisher
**********************************************************/
string Book::GetPublisher()
{
    return Publisher;
}
/*********************************************************
*��������    SetPublisher()
*�������ܣ�  ��ͼ������̽����޸�
*
*����������  string publisher     //ͼ�������
*��������ֵ: Publisher
*********************************************************/
string Book::SetPublisher(string publisher)
{
    this->Publisher = publisher;
    return Publisher;
}



/*********************************************************
*��������   GetDate()
*�������ܣ� ��ȡͼ���������
*
*����������  void
*��������ֵ��Date
**********************************************************/
string Book::GetDate()
{
    return Date;
}
/*********************************************************
*��������    SetDate()
*�������ܣ�  ��ͼ�����ڽ����޸�
*
*����������  string date     //ͼ������
*��������ֵ: Date
*********************************************************/
string Book::SetDate(string date)
{
    this->Date = date;
    return Date;
}



/*********************************************************
*��������   GetPrice()
*�������ܣ� ��ȡͼ��۸�
*
*����������  void
*��������ֵ��Price
**********************************************************/
float Book::GetPrice()
{
    return Price;
}
/*********************************************************
*��������    SetPrice()
*�������ܣ�  ��ͼ��۸�����޸�
*
*����������  float  price      //ͼ��۸�
*��������ֵ: Price
*********************************************************/
float Book::SetPrice(float price)
{
    this->Price = price;
    return Price;
}



/*********************************************************
*��������   GetCatalogNum()
*�������ܣ� ��ȡͼ�������
*
*����������  void
*��������ֵ��CatalogNum
**********************************************************/
string Book::GetCatalogNum()
{
    return CatalogNum;
}
/*********************************************************
*��������    SetCatalogNum()
*�������ܣ�  ��ͼ������Ž����޸�
*
*����������  string  catalognum    //ͼ�������
*��������ֵ: CatalogNum
*********************************************************/
string Book::SetCatalogNum(string catalognum)
{
    this->CatalogNum = catalognum;
    return CatalogNum;
}



/*********************************************************
*��������   GetNumber()
*�������ܣ� ��ȡͼ������
*
*����������  void
*��������ֵ��Number
**********************************************************/
int Book::GetNumber()
{
    return Number;
}
/*********************************************************
*��������    SetNumber()
*�������ܣ�  ��ͼ�����������޸�
*
*����������  int  number       //ͼ������
*��������ֵ: Number
*********************************************************/
int Book::SetNumber(int number)
{
    this->Number = number;
    return Number;
}



/*********************************************************
*��������    Print()
*�������ܣ�  ���뵥��ͼ���ȫ����Ϣ
*
*����������  void
*��������ֵ��void
*********************************************************/
void Book::Print()
{
    cout <<  GetISBN()  << '\t'  << GetTitle() << '\t';
    cout << GetAuthor() << '\t'  << GetPublisher() << '\t';
    cout << GetDate() << '\t' << GetPrice();
    cout << setw(10) << GetCatalogNum() << setw(11) << GetNumber() << endl;
}



/****************************************************************
*��������    AddBook()
*�������ܣ�  ��Ӷ�����Ϣ
*
*����������  Book������Ϊ����������vector<Book> &Book_vec
*
*��������ֵ��void
*****************************************************************/
void Book::AddBook(vector<Book> &Book_vec)
{
    cout << "\n\n\t\t\t\t���ͼ����Ϣ\n\n" << endl;
    //ͼ��ISBN���
    string isbn;
    //ͼ������
    string title;
    //ͼ������
    string author;
    //ͼ�������
    string publisher;
    //ͼ���������
    string date;
    //ͼ��۸�
    float  price;
    //ͼ�������
    string catalognum;
    //ͼ������
    int number;

    //�û�����ѡ��
    char reply;
    do{
        cout << "\n������ͼ���ISBN��ţ�";
        cin  >> isbn;
        cout << "������ͼ������ƣ�";
        cin  >> title;
        cout << "������ͼ������ߣ�";
        cin  >> author;
        cout << "������ͼ��ĳ����̣�";
        cin  >> publisher;
        cout << "������ͼ��ĳ������ڣ�";
        cin  >> date;
        cout << "������ͼ��ļ۸�";
        //����Enter��
        cin.get();
        cin  >> price;
        cout << "������ͼ��ķ����ţ�";
        cin  >> catalognum;
        cout << "������ͼ���������";
        cin  >> number;

        //��������object,�����ù��캯��
        Book object(isbn, title, author, publisher, date, price, catalognum, number);
        //��������ͼ����Ϣ����Book������
        Book_vec.push_back(object);

        cout << "������������𣿣�(Y/h)/(N/n)����";
        cin.get();
        cin.get(reply);
        }while(reply == 'Y' || reply == 'y');

    cout << "\n�Ƿ񱣴��������Ϣ����(Y/y) / (N/n)����";
    char choose;
    //����Enter��
    cin.get();
    cin.get(choose);
    if (choose == 'Y' || choose == 'y')
    {
        //����SaveBookApp()����������ͼ����Ϣ��book.txt�ļ���
        SaveBookApp(Book_vec);
    }
    else
    {
        cout << "\n\t\t\t�ļ�û�б��棡" << endl;
    }
}



/******************************************************************
*��������    BrowseBook()
*�������ܣ�  ���������Ϣ
*
*����������  Book������Ϊ����������vector<Book> &Book_vec
*��������ֵ��void
*******************************************************************/
void Book::BrowseBook(vector<Book> &Book_vec)
{
    cout << "\n\n\t\t\t\t\t\t���ͼ����Ϣ\n\n" << endl;
    cout << "==========================================================================================================\n" << endl;
    cout << "ISBN\t\t����\t\t����\t\t������\t\t��������\t�۸�\t������\t����\n" << endl;
    cout << "==========================================================================================================\n" << endl;

    //��������� B���������������ͼ����Ϣ
    vector<Book>::iterator B = Book_vec.begin();
    while (B != Book_vec.end())
    {
        //����Print()���������ͼ����Ϣ
        (*B).Print();
        B++;
    }
    cout << "\n==========================================================================================================\n" << endl;
}



/******************************************************************
*��������    ModifyBook()
*�������ܣ�  �޸�ͼ����Ϣ
*
*����������  Book������Ϊ����������vector<Book> &Book_vec
*��������ֵ��void
******************************************************************/
void Book::ModifyBook(vector<Book> &Book_vec)
{
    cout << "\n\n\t\t\t\t\t\t�޸�ͼ����Ϣ\n\n" << endl;
    //�����־����
    int flag = 0;
    //ͼ��ISBN���
    string isbn;
    //ͼ������
    string title;
    //ͼ������
    string author;
    //ͼ�������
    string publisher;
    //ͼ���������
    string date;
    //ͼ��۸�
    float price;
    //ͼ�������
    string catalognum;
    //ͼ������
    int  number;

    cout << "������Ҫ�޸ĵ�ͼ��ISBN��ţ�";
    //����Enter��
    cin.get();
    cin >> isbn;

    //��������� B���������������Һ��޸�ͼ����Ϣ
    vector<Book>::iterator B = Book_vec.begin();
    while (B != Book_vec.end())
    {
        if( B -> GetISBN() == isbn )
        {
            //flag = 1��ʾ�޸�ͼ����Ϣ�ɹ�
            flag = 1;
            cout << "��Ҫ�޸ĵ�ͼ����Ϣ��" << endl;
            cout << "==========================================================================================================\n" << endl;
            cout << "ISBN\t\t����\t\t����\t\t������\t\t��������\t�۸�\t������\t����\n" << endl;
            cout << "==========================================================================================================\n" << endl;

            //����Print()���������ͼ����Ϣ
            (*B).Print();

            cout << "������ͼ���ISBN��ţ�";
            cin  >> isbn;
            cout << "������ͼ������ƣ�";
            cin  >> title;
            cout << "������ͼ������ߣ�";
            cin  >> author;
            cout << "������ͼ��ĳ����̣�";
            cin  >> publisher;
            cout << "������ͼ��ĳ������ڣ�";
            cin  >> date;
            cout << "������ͼ��ļ۸�";
            //����Enter��
            cin.get();
            cin  >> price;
            cout << "������ͼ��ķ����ţ�";
            cin  >> catalognum;
            cout << "������ͼ���������";
            cin  >> number;

            B->SetISBN(isbn);
            B->SetTitle(title);
            B->SetAuthor(author);
            B->SetPublisher(publisher);
            B->SetDate(date);
            B->SetPrice(price);
            B->SetCatalogNum(catalognum);
            B->SetNumber(number);

            cout << "\n\t\t\t�޸ĳɹ���" << endl;
            cout << "\n==========================================================================================================\n" << endl;
            break;
        }
        B++;
    }
    if(!flag)
    {
        cout << "\n\t\t\t�޸�ʧ�ܣ�\n" << endl;
    }

    //����SaveBook()�����������޸ĺ����Ϣ��book.txt�ļ��С�
    SaveBook(Book_vec);
}



/******************************************************************
*��������    DeleteBook()
*�������ܣ�  ɾ��������Ϣ
*
*����������  Book������Ϊ����������vector<Book> &Book_vec
*��������ֵ��void
*******************************************************************/
void Book::DeleteBook(vector<Book> &Book_vec)
{
    cout << "\n\n\t\t\t\t\t\tɾ��ͼ����Ϣ\n\n" << endl;
    //�����־����
    int flag = 0;
    //Ҫɾ��ͼ����Ϣ��ISBN���
    string isbn;

    cout << "������Ҫɾ����ͼ��ISBN��ţ�";
    //����Enter��
    cin.get();
    cin >> isbn;

    //��������� B���������������Һ�ɾ��ͼ����Ϣ
    vector<Book>::iterator B = Book_vec.begin();
    while (B != Book_vec.end())
    {
        if( B -> GetISBN() == isbn )
        {
            flag=1;       //flag = 1��ʾͼ����Ϣɾ���ɹ�
            cout << "��Ҫɾ����ͼ����Ϣ��" << endl;
            cout << "==========================================================================================================\n" << endl;
            cout << "ISBN\t\t����\t\t����\t\t������\t\t��������\t�۸�\t������\t����\n" << endl;
            cout << "==========================================================================================================\n" << endl;

            //����Print()���������ͼ����Ϣ
            (*B).Print();

            //�ͷ�ָ���ͼ����Ϣ�ĵ�������Ҳ��ɾ����ͼ�����Ϣ
            Book_vec.erase(B++);
            cout << "\n\t\t\tɾ���ɹ���" << endl;
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
        cout << "\n\t\t\tɾ��ʧ�ܣ�\n" << endl;
    }

    //����SaveBook()����������ɾ��ͼ������Ϣ��book.txt�ļ���
    SaveBook(Book_vec);
}



/******************************************************************
*��������    FindBookByISBN()
*�������ܣ�  ����ͼ���ISBN���������ͼ����Ϣ
*
*����������  Book������Ϊ����������vector<Book> &Book-vec
*��������ֵ��void
******************************************************************/
void Book::FindBookByISBN(vector<Book> &Book_vec)
{
    cout << "\n\n\t\t\t\t\t\t����ͼ��ISBN���ͼ����Ϣ\n\n" << endl;
    //�����־����
    int flag = 0;
    //Ҫ��ѯͼ���ISBN���
    string isbn;

    cout << "��������Ҫ��ѯͼ��ISBN��ţ�";
    //����Enter��
    cin.get();
    cin >> isbn;

    //��������� B����������������ͼ����Ϣ
    vector<Book>::iterator B = Book_vec.begin();
    while (B != Book_vec.end())
    {
        if( B -> GetISBN() == isbn )
        {
            //flag = 1��ʾ�ҵ�������Ϣ
            flag = 1;
            cout << "==========================================================================================================\n" << endl;
            cout << "ISBN\t\t����\t\t����\t\t������\t\t��������\t�۸�\t������\t����\n" << endl;
            cout << "==========================================================================================================\n" << endl;

            //����Print()���������ͼ����Ϣ
            (*B).Print();
            cout << "\n==========================================================================================================\n" << endl;
            break;
        }
        B++;
    }

    if (!flag)
    {
        cout << "\n\t\t\tû�д�ͼ�����Ϣ��\n" << endl;
    }
}



/******************************************************************
*��������    FindBookByTitle()
*�������ܣ�  ����ͼ������������ͼ����Ϣ
*
*����������  Book������Ϊ����������vector<Book> &Book-vec
*��������ֵ��void
******************************************************************/
void Book::FindBookByTitle(vector<Book> &Book_vec)
{
    cout << "\n\n\t\t\t\t\t\t����ͼ������ͼ����Ϣ\n\n" << endl;
    //�����־����
    int flag = 0;
    //Ҫ��ѯͼ�������
    string title;

    cout << "��������Ҫ��ѯͼ�����ƣ�";
    //����Enter��
    cin.get();
    cin  >> title;

    //��������� B����������������ͼ����Ϣ
    vector<Book>::iterator B = Book_vec.begin();
    while (B != Book_vec.end())
    {
        if( B -> GetTitle() == title )
        {
            //flag = 1��ʾ�ҵ�������Ϣ
            flag = 1;
            cout << "==========================================================================================================\n" << endl;
            cout << "ISBN\t\t����\t\t����\t\t������\t\t��������\t�۸�\t������\t����\n" << endl;
            cout << "==========================================================================================================\n" << endl;

            //����Print()���������ͼ����Ϣ
            (*B).Print();
            cout << "\n==========================================================================================================\n" << endl;
            break;
        }
        B++;
    }

    if (!flag)
    {
        cout << "\n\t\t\tû�д�ͼ�����Ϣ��\n" << endl;
    }
}



/******************************************************************
*��������    FindBookByPublisher()
*�������ܣ�  ����ͼ�������������ͼ����Ϣ
*
*����������  Book������Ϊ����������vector<Book> &Book-vec
*��������ֵ��void
******************************************************************/
void Book::FindBookByPublisher(vector<Book> &Book_vec)
{
    cout << "\n\n\t\t\t\t\t\t����ͼ������̲���ͼ����Ϣ\n\n" << endl;
    //�����־����
    int flag = 0;
    //Ҫ��ѯͼ�������
    string author;

    cout << "��������Ҫ��ѯͼ�����ߣ�";
    //����Enter��
    cin.get();
    cin >> author;

    //��������� B����������������ͼ����Ϣ
    vector<Book>::iterator B = Book_vec.begin();
    while (B != Book_vec.end())
    {
        if( B -> GetAuthor() == author )
        {
            //flag = 1��ʾ�ҵ�������Ϣ
            flag = 1;
            cout << "==========================================================================================================\n" << endl;
            cout << "ISBN\t\t����\t\t����\t\t������\t\t��������\t�۸�\t������\t����\n" << endl;
            cout << "==========================================================================================================\n" << endl;

            //����Print()���������ͼ����Ϣ
            (*B).Print();
            cout << "\n==========================================================================================================\n" << endl;
            break;
        }
        B++;
    }

    if (!flag)
    {
        cout << "\n\t\t\tû�д�ͼ�����Ϣ��\n" << endl;
    }
}



/******************************************************************
*��������    FindBookByAuthor()
*�������ܣ�  ����ͼ������������ͼ����Ϣ
*
*����������  Book������Ϊ����������vector<Book> &Book-vec
*��������ֵ��void
******************************************************************/
void Book::FindBookByAuthor(vector<Book> &Book_vec)
{
    cout << "\n\n\t\t\t\t\t\t����ͼ�����߲���ͼ����Ϣ\n\n" << endl;
    //�����־����
    int flag = 0;
    //Ҫ��ѯͼ�������
    string publisher;

    cout << "��������Ҫ��ѯͼ��ĳ����̣�";
    //����Enter��
    cin.get();
    cin >> publisher;

    //��������� B����������������ͼ����Ϣ
    vector<Book>::iterator B = Book_vec.begin();
    while (B != Book_vec.end())
    {
        if( B -> GetPublisher() == publisher )
        {
            //flag = 1��ʾ�ҵ�������Ϣ
            flag = 1;
            cout << "==========================================================================================================\n" << endl;
            cout << "ISBN\t\t����\t\t����\t\t������\t\t��������\t�۸�\t������\t����\n" << endl;
            cout << "==========================================================================================================\n" << endl;

            //����Print()���������ͼ����Ϣ
            (*B).Print();
            cout << "\n==========================================================================================================\n" << endl;
            break;
        }
        B++;
    }

    if (!flag)
    {
        cout << "\n\t\t\tû�д�ͼ�����Ϣ��\n" << endl;
    }
}



/******************************************************************
*��������    SaveBook()
*�������ܣ�  ����д�ķ�ʽ�����������Ϣ��book.txt�ļ��С�
*
*����������  Book������Ϊ����������vector<Book> &Book_vec
*��������ֵ��void
******************************************************************/
void Book::SaveBook(vector<Book> &Book_vec)
{
    //����book.txt�ļ���
    ofstream out ("book.txt", ios::out);

    //�ж��ļ��Ƿ񴴽��ɹ�
    if (!out)
    {
        cout << "\n\t\t\t�ļ�����ʧ�ܣ�";
        exit(0);
    }

    //��������� B���������������������Ϣ
    vector<Book>::iterator B;
    for (B = Book_vec.begin(); B != Book_vec.end(); B++)
    {
        out << B->GetISBN() << '\t' << B->GetTitle() << '\t';
        out << B->GetAuthor() << '\t' << B->GetPublisher() << '\t';
        out << B->GetDate() << '\t' << B->GetPrice() << '\t';
        out << B->GetCatalogNum() << '\t' << B->GetNumber() << endl;
    }

    //�ر��ļ�
    out.close();
}



/******************************************************************
*��������    SaveBookApp()
*�������ܣ�  ����ӵ��ļ�β��ʽ�����������Ϣ��book.txt�ļ��С�
*
*����������  Book������Ϊ����������vector<Book> &Book_vec
*��������ֵ��void
******************************************************************/
void Book::SaveBookApp(vector<Book> &Book_vec)
{
    //����book.txt�ļ���
    ofstream out ("book.txt", ios::out | ios::app);

    //�ж��ļ��Ƿ񴴽��ɹ�
    if (!out)
    {
        cout << "\n\t\t\t�ļ�����ʧ�ܣ�";
        exit(0);
    }

    //��������� B���������������������Ϣ
    vector<Book>::iterator B;
    for (B = Book_vec.begin(); B != Book_vec.end(); B++)
    {
        out << B->GetISBN()   << '\t' << B->GetTitle()      << '\t';
        out << B->GetAuthor() << '\t' << B->GetPublisher()  << '\t';
        out << B->GetDate()   << '\t' << B->GetPrice()      << '\t';
        out << B->GetCatalogNum() << '\t' << B->GetNumber() << endl;
    }

    //�ر��ļ�
    out.close();
}



/******************************************************************
*��������    ReadFileToBookVector()
*�������ܣ�  ��ȡ�ļ���Ϣ��Book������,���������������������ݡ�
*
*����������  Book������Ϊ����������vector<Book> &Book_vec
*��������ֵ��void
******************************************************************/
void Book::ReadFileToBookVector(vector<Book> &Book_vec)
{
    //ͼ��ISBN���
    string isbn;
    //ͼ������
    string title;
    //ͼ������
    string author;
    //ͼ�������
    string publisher;
    //ͼ���������
    string date;
    //ͼ��۸�
    float price;
    //ͼ�������
    string catalognum;
    //ͼ������
    int number;

    //��ȡ�ļ���Ϣ
    ifstream in("book.txt", ios::in);
    //�ж��ļ����Ƿ�ɹ�
    if (!in)
    {
        cout << "\n\t\t\t�ļ���ʧ��";
        exit(0);
    }

    //�Ƚ��ж�����Ϣ�Ķ�ȡ��Ž�Book��������ֹ���һ����Ϣ��©
    in >> isbn >>  title >>  author >> publisher >> date >> price >> catalognum >> number;
    while (!in.eof())
    {
        //�������߶���object,������Book()���캯����
        Book object(isbn, title, author, publisher, date, price, catalognum, number);

        //��ȡ��Ķ�����Ϣ����Book������
        Book_vec.push_back(object);
        in >> isbn >>  title >>  author >> publisher >> date >> price >> catalognum >> number;
    }

    //�ر��ļ�
    in.close();
}



/**************************************************
*��������    ~Book()
*�������ܣ�  ���������ڽ���ʱ��ϵͳ������������
*
*
*����������  ��
**************************************************/
Book::~Book()
{}
