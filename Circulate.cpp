/********************************************************************************
*
*Copyright(c)2015,�ϲ���ѧ���ѧԺʵ��С��(�Ż�������Ȼ�����¾�)
*All rights reserved.
*
*�ļ����ƣ� Circulate.cpp
*�ļ���ʶ�� �����ù���ƻ���
*
*ժ    Ҫ�� ���ļ���Ҫ������ͼ����ͨ���ܺ�����ʵ�֡���ʵ�ֵķ�ʽ�õ��ǲ�������
*            ��ʽ��ʹ�����������ݽ��в��롢ɾ����Ч�ʸ��ߡ�
*
*
*��ǰ�汾��1.0
*���ߣ����¾�
*������ڣ�2015/6/10
*��һ���޸ģ�2015/6/14
*�ڶ����޸ģ�2015/6/20
*
**********************************************************************************/


#include "Circulate.h"     //���÷Ǳ�׼�⺯��




/******************************************************************
*��������    ReaderBorrow()
*�������ܣ�  ���߽���ͼ�鹦��
*
*����������  Reader������Ϊ����������vector<Reader> &Reader_vec
*��������ֵ��void
*******************************************************************/
void Circulate::ReaderBorrow(vector<Reader> &Reader_vec)
{
    cout << "\n\n\t\t���߽���\n\n" << endl;
    //����֤����
    string code;

    cout << "��������Ķ��ߵ�֤���ţ�";
    cin >> code;
    //�����־����flag
    int flag = 0;
    //�����־����flag1
    int flag1 = 0;
    //����һ�����߶���
    Reader reader;
    //����һ��ͼ�����
    Book book;


    //��������� R���������������Һ͹�ʧ������Ϣ
    vector<Reader>::iterator R = Reader_vec.begin();
    while (R != Reader_vec.end())
    {
        if( R -> GetCode() == code )
        {
            //flag = 1��ʾ������Ϣ��ʧ�ɹ�
            flag = 1;

            cout << "=================================================================================" << endl;
            cout << "����\t�Ա�\t֤����\t\t������λ\t\t��ʧ״̬\t���鱾��" << endl;
            cout << "=================================================================================\n" << endl;
            //����Print()���������������Ϣ
            (*R).Print();
            cout << "\n=================================================================================\n\n" << endl;
            if (R->GetTag() == 1)
            {
                cout << "\n\t\t\t�ö����ѹ�ʧ���޷�����ͼ�飡\n" << endl;
                break;
            }

            else if (R->GetNumber() >= MAX_BOOK)
            {
                cout << "\n\t\t\t�ö��߽���ͼ���ѳ���6�����޷����ģ�\n" << endl;
                break;
            }
            else
            {
                //flag=1���ҵ�����
                flag1 = 1;
                //����һ��ͼ������Book_vec
                vector<Book> Book_vec;
                //��book.txt�ļ��ж�ȡ���ݵ�Book_vec������
                book.ReadFileToBookVector(Book_vec);

                //ͼ��ISBN���
                string isbn;
                cout << "������ͼ��ISBN��ţ�" << endl;
                cin >> isbn;
                //����һ��������B,��������������ͼ����Ϣ
                vector<Book>::iterator B = Book_vec.begin();
                while (B != Book_vec.end())
                {
                    if( B -> GetISBN() == isbn )
                    {
                        if (B->GetNumber() == 0)
                        {
                            cout << "\n\t\t\t��ͼ����Ϊ0�� ��ʱ�޷����ģ�\n" << endl;
                            break;
                        }
                        else
                        {
                            //flag1=1��ʾ�ҵ�ͼ����Ϣ
                            flag1 = 1;

                            cout << "==========================================================================================================\n" << endl;
                            cout << "ISBN\t\t����\t\t����\t\t������\t\t��������\t�۸�\t������\t����\n" << endl;
                            cout << "==========================================================================================================\n" << endl;

                            //����Print()���������ͼ����Ϣ
                            (*B).Print();
                            cout << "\n==========================================================================================================\n" << endl;

                            //��ȡͼ������
                            int BookNumber = B->GetNumber();
                            //����SetNumber()����������ɹ���ͼ�������Զ���һ
                            B->SetNumber( BookNumber-1 );
                            //����SaveBook()�����������ʧ��Ķ�����Ϣ��reader.txt�ļ���
                            book.SaveBook(Book_vec);

                            //��ȡ���߽�������
                            int ReaderNumber = R->GetNumber();
                            //����SetNumber()����������ɹ��󣬶��߽��������Զ���һ
                            R->SetNumber(ReaderNumber+1);
                            //����SaveReader()������������ĺ�Ķ�����Ϣ��reader.txt�ļ���
                            reader.SaveReader(Reader_vec);

                            //����һ�����߽�����Ϣ����borrow
                            Circulate borrow;
                            //������߽�����Ϣ
                            borrow.SaveBorrowB(code, isbn);
                            cout << "\n\t\t\t���ĳɹ���\n" << endl;
                            break;
                        }
                    }
                    B++;
                }
                if (!flag1)
                {
                    cout << "\n\t\t\t��ͼ����Ϣ�����ڣ�\n" << endl;
                }
            }

        }R++;
    }
    if(!flag)
    {
        cout << "\n\t\t\t������Ϣ�����ڣ�����ʧ�ܣ�\n" << endl;
    }
}



/******************************************************************
*��������    SaveBorrowB()
*�������ܣ�  ������߽�����Ϣ
*
*����������  ����֤���ţ�Code
*             ͼ��ISBN��ţ�isbn
*��������ֵ��void
*******************************************************************/
void Circulate::SaveBorrowB(string Code, string ISBN)
{
    //���Ķ���֤����
    L.Code.assign(Code);
    //����ͼ���ISBN���
    L.ISBN.assign(ISBN);

    //����һ��ʱ�����
    time_t t;
    //��ȡϵͳ��ǰʱ��
    t = time(NULL);
    //��������ʱ��ṹ��
    tm borrowDate, lastDate;
    //��ϵͳʱ��ת��Ϊ����ʱ��
    borrowDate = *localtime(&t);
    int year, month, day;
    day = borrowDate.tm_mday;
    month = borrowDate.tm_mon + 1;
    year = borrowDate.tm_year + 1900;

    //���߽���ͼ��ʱ��
    L.BorrowDate.Year = year;
    L.BorrowDate.Month = month;
    L.BorrowDate.Day = day;

    //����ͼ��Ӧ������
    t = t + MAX_DAY * 86400; //24*60*60

    //��ϵͳʱ��ת��Ϊ����ʱ��
    lastDate = *localtime(&t);
    int year1, month1, day1;
    day1 = lastDate.tm_mday;
    month1 = lastDate.tm_mon + 1;
    year1 = lastDate.tm_year + 1900;

    //����Ӧ������
    L.LastDate.Year = year1;
    L.LastDate.Month = month1;
    L.LastDate.Day = day1;

    //��ʼ������ʵ�ʻ�������
    L.ReturnDate.Year  = 0;
    L.ReturnDate.Month = 0;
    L.ReturnDate.Day   = 0;

    //��ʼ�����߽���
    L.Tag = "���";
    //����һ���ļ�����out��������߽�����Ϣ���ļ�borrow.txt��
    ofstream out ("borrow.txt", ios::out | ios::app);
    if (!out)
    {
        cout << "\n\t\t\t�����ļ�ʧ�ܣ�\n" << endl;
        exit(0);
    }
    out << L.Code << "\t" << L.ISBN << "\t";
    out << L.BorrowDate.Year << " " << L.BorrowDate.Month << " " << L.BorrowDate.Day << "\t";
    out << L.LastDate.Year   << " " << L.LastDate.Month   << " " << L.LastDate.Day   << "\t";
    out << L.ReturnDate.Year << " " << L.ReturnDate.Month << " " << L.ReturnDate.Day << "\t\t";
    out << L.Tag << endl;

    //�ļ��ر�
    out.close();
}



/********************************************************************
*��������    CreatBorrowLink()
*�������ܣ�  ��ȡborrow.txt�ļ���������һ��ͼ����ͨ������
*
*����������  ��
*
*��������ֵ����ͷָ�����ʽ������head
*********************************************************************/
BorrowLink* Circulate::CreatBorrowLink()
{
    //����ṹ��ָ��*head, *p, *q;
    BorrowLink *head, *p, *q;
    //ʹ��ָ��ǰ����ָ���ʼ��Ϊ��
    head = NULL;
    q = NULL;
    p = NULL;

    //�����ļ����� in, �����ļ�
    ifstream in ("borrow.txt", ios::in);
    if(!in)
    {
        cout << "\n\t\t\t���ļ�ʧ�ܣ�\n";
        exit(0);
    }

    //�������ͷָ��head����һ��BookCatalongLink��С�Ķ�̬�ռ�
    head = new BorrowLink;
    //��ͷָ��head�ĵ�ַ��ֵ��p
    p = head;
    while (!in.eof())
    {
        //�������ָ��q����һ��BookCatalongLink��С�Ķ�̬�ռ�
        q = new BorrowLink;
        in >> q->Code >> q->ISBN;
        in >> q->BorrowDate.Year >> q->BorrowDate.Month  >> q->BorrowDate.Day;
        in >> q->LastDate.Year   >> q->LastDate.Month    >> q->LastDate.Day;
        in >> q->ReturnDate.Year >> q->ReturnDate.Month  >> q->ReturnDate.Day;
        in >> q->Tag;

        //ǰһ��ָ��p��ָ����ָ��ǰָ��q
        p -> next = q;
        //�ѵ�ǰָ��q�ĵ�ַ��ֵ��ǰһ��ָ��p
        p = q;
    }
   //���������һ��ָ���ָ�����ÿ�
    p -> next = NULL;

    //�ر��ļ�
    in.close();
    //���������ͷָ��
    return head;
}



/******************************************************************
*��������    ReaderReturn()
*�������ܣ�  ���߻��鹦��
*
*����������  Reader������Ϊ����������vector<Reader> &Reader_vec
*��������ֵ��void
*******************************************************************/
void Circulate::ReaderReturn(vector<Reader> &Reader_vec)
{
    cout << "\n\n\t\t\t���߻���\n\n" << endl;
    //���Ķ��ߵ�֤����
    string code;
    //����ͼ���ISBN���
    string isbn;
    //ͼ��Ľ���״̬
    string tag = "���";
    //����һ����־����
    int flag = 0;

    //����һ�����߶��� Reader
    Reader reader;
    //����һ��ͼ�����
    Book book;

    //����ṹ��ָ��*head, *p, *q;
    BorrowLink *head, *p;
    //ʹ��ָ��ǰ����ָ���ʼ��Ϊ��
    head = NULL;
    p = NULL;


    //����һ��ʱ�����
    time_t t;
    //��ȡϵͳ��ǰʱ��
    t = time(NULL);
    //��������ʱ��ṹ��
    tm returnDate;
    //��ϵͳʱ��ת��Ϊ����ʱ��
    returnDate = *localtime(&t);
    int year, month, day;
    day = returnDate.tm_mday;
    month = returnDate.tm_mon + 1;
    year = returnDate.tm_year + 1900;

    //����һ������
    head = CreatBorrowLink();

    cout << "������Ҫ����Ķ���֤���ţ�";
    cin >> code;
    cout << "���������Ҫ�������ISBN��ţ�";
    cin >> isbn;
    cout << "============================================================================================" << endl;
    cout << "����֤����" << "\t" << "ͼ��ISBN���" << "\t" << "��������" << "\t" << "Ӧ���黹����" << "\t" << "��������" << '\t' << "����״̬" << endl;
    cout << "============================================================================================\n" << endl;

    //��ͷָ��head��ָ�����ַ��ֵ��ָ��p
    p = head ->next;
    while (p != NULL)
    {
        //�жϽ��Ķ�����Ϣ�����Ƿ���ڣ����ж϶����Ƿ�û�й�ʧ
        if (code.compare(p->Code) == 0 && isbn.compare(p->ISBN) == 0 && tag.compare(p->Tag) == 0)
        {
            //flag = 1;��ʾ�ҵ��ý�����Ϣ
            flag = 1;

            //��������� R���������������Һ͹�ʧ������Ϣ
            vector<Reader>::iterator R = Reader_vec.begin();
            while (R != Reader_vec.end())
            {
                if (code.compare(R->GetCode()) == 0)
                {
                    //����һ��ͼ������Book_vec
                     vector<Book> Book_vec;
                     //��ȡͼ����Ϣ������Book_vec��
                     book.ReadFileToBookVector(Book_vec);
                     //����һ��������B,�������ҡ��޸�ͼ����Ϣ
                     vector<Book>::iterator B = Book_vec.begin();
                     while (B != Book_vec.end())
                     {
                         if (isbn.compare(B->GetISBN()) == 0)
                         {
                             //��ȡͼ������
                             int BookNumber = B->GetNumber();
                             //����SetNumber()����������ɹ�ʱ��ͼ�������Զ���һ
                             B->SetNumber( BookNumber+1 );
                             //����SaveBook()�����������ʧ��Ķ�����Ϣ��reader.txt�ļ���
                             book.SaveBook(Book_vec);

                             //��ȡ���߽���ͼ������
                             int ReaderNumber = R->GetNumber();
                             //����SetNumber()����������ɹ�ʱ�����߽���ͼ�������Զ���һ
                             R->SetNumber(ReaderNumber-1);
                             //����SaveReader()���������滹���Ķ�����Ϣ��reader.txt�ļ���
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


            //���Ķ���֤����
            L.Code.assign(code);
            //����ͼ���ISBN���
            L.ISBN.assign(isbn);

            //����ʵ�ʻ���ʱ��
            p->ReturnDate.Year = year;
            p->ReturnDate.Month = month;
            p->ReturnDate.Day = day;

            //�޸Ķ��߽���״̬
            p->Tag = "�ѻ�";
            cout << "\n\t\t\t���߻���ɹ���\n" << endl;
        }
        //����ָ�������һλ
        p = p->next;
    }

    //�����ļ����󣬱��滹������Ϣ��borrow.txt�ļ���
    ofstream out ("borrow.txt", ios::out );
    if (!out)
    {
        cout << "\n\t\t\t�ļ���ʧ�ܣ�\n" << endl;
        exit(0);
    }

    //�������߽�����Ϣ�������ѻ�������Ϣд�뵽borrow.txt�ļ���
    for (p = head->next; p->next != NULL; p = p -> next)
    {
        out << p->Code << "\t" << p->ISBN << "\t";
        out << p->BorrowDate.Year << " " << p->BorrowDate.Month << " " << p->BorrowDate.Day << "\t";
        out << p->LastDate.Year   << " " << p->LastDate.Month   << " " << p->LastDate.Day   << "\t";
        out << p->ReturnDate.Year << " " << p->ReturnDate.Month << " " << p->ReturnDate.Day << "\t\t";
        out << p->Tag << endl;
    }

    //�ر��ļ�
    out.close();

    if (!flag)
    {
        cout << "\n\t\t\t������Ϣ�����ڣ�����û�н��ģ�\n" << endl;
    }

    cout << "\n============================================================================================\n\n" << endl;
    //�ͷŶ��߽�����Ϣ����ָ��
    DeleteMemory(head);
}



/********************************************************************
*��������    FindBorrow()
*�������ܣ�  ��ѯ����ͼ��������Ϣ
*
*����������  ��
*
*��������ֵ��void
*********************************************************************/
void Circulate::FindBorrow()
{
    cout << "\n\n\t\t\t��ѯ���߽��ļ�¼\n\n" << endl;
    //����֤����
    string code;
    //����ṹ��ָ��*head, *p, *q;
    BorrowLink *head, *p;
    //ʹ��ָ��ǰ����ָ���ʼ��Ϊ��
    head = NULL;
    p = NULL;
    //����flag��־����
    int flag = 0;
    cout << "������Ҫ��ѯ�Ķ���֤���ţ�";
    cin >> code;


    //����һ������
    head = CreatBorrowLink();

    cout << "============================================================================================" << endl;
    cout << "����֤����" << "\t" << "ͼ��ISBN���" << "\t" << "��������" << "\t" << "Ӧ���黹����" << "\t" << "��������" << '\t' << "����״̬" << endl;
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
        cout << "\n�ö��߲����ڻ���û�н����鼮��" << endl;
    }
    cout << "\n============================================================================================\n\n" << endl;

    //�ͷ�����ָ��
    DeleteMemory(head);
}

/********************************************************************
*��������    DeleteMemory()
*�������ܣ�  �ͷ�ͼ�������Ϣ������ָ��
*
*����������  ��ͷָ�����ʽ������BorrowLink *head
*
*��������ֵ��void
*********************************************************************/
void Circulate::DeleteMemory(BorrowLink *head)
{
    //����ṹ��ָ��*p, *q;
    BorrowLink *p, *q;
    //ʹ��ָ��ǰ����ָ���ʼ��Ϊ��
    q = NULL;
    p = NULL;

    //��ͷָ��head�ĵ�ַ���Ƹ�ָ��p
    p = head;
    //��������
    while (p -> next != NULL)
    {
        //�ѵ�ǰָ��ĵ�ַ��ֵ��ָ��q
        q = p;
        //����һ��ָ��p��ָ�����Ƹ���ǰָ��ָ��p
        p = p -> next;
        //ɾ��ָ��q
        delete q;
    }
}
