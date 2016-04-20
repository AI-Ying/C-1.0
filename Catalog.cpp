/********************************************************************************
*
*Copyright(c)2015,南昌大学软件学院实验小组(张欢，王沛然，闫致敬)
*All rights reserved.
*
*文件名称： Catalog.cpp
*文件标识： 见配置管理计划书
*
*摘    要： 本文件主要是对图书分类功能函数的实现。在实现的方式用的是采用链表
*            形式，使用链表，在数据进行插入、删除上效率更高。
*
*
*当前版本：1.0
*作者：闫致敬
*完成日期：2015/6/8
*第一次修改：2015/6/14
*第二次修改：2015/6/20
*
**********************************************************************************/

#include  "Catalog.h"             //引用非标准库函数



/***************************************************
*函数名：    Catalog()
*函数功能：  创建对象没有初始化，调用无参构造函数
*
*函数参数：  无
***************************************************/
Catalog::Catalog()
{}


/********************************************************************
*函数名：    AddCatalog()
*函数功能：  增加分类图书，并存入信息到catalog.txt文件中。
*
*函数参数：  无
*
*函数返回值：void
*********************************************************************/
void Catalog::AddCatalog()
{
    cout << "\n\n\t\t\t添加分类图书\n\n" << endl;
	//reply、choose均为用户的选择
	char reply;
	char choose;

	ofstream out("catalog.txt", ios::out | ios::app);
	if(!out)
    {
        cout << "\n\t\t\t文件创建失败!" << endl;
        exit(0);
    }

	do
    {
		cout << "\n输入分类图书的编号：";
        cin  >> C.Key;
		cout << "输入分类图书名称：";

        cin  >> C.Caption;
		cout << "输入分类图书的父类编号：";
		cin  >> C.Parent;

        cout << "是否保存输入的信息？（是：Y/y）/（否：N/n）:";
        cin  >> choose;
        if (choose == 'Y' || choose == 'y')
        {
            out  << C.Key << '\t' << C.Caption << '\t' << C.Parent << endl;
            cout << "\n\t\t\t添加成功！\n" << endl;
        }
        else
        {
            cin.clear();
            cout << "\n\t\t\t添加失败！\n" << endl;
        }
		cout << "是否需要继续输入？（是：y/Y）/（否：n/N）:";
		cin  >> reply;
	}while(reply == 'Y' || reply == 'y');

    //关闭文件
	out.close();
}



/********************************************************************
*函数名：    PrintCatalog()
*函数功能：  读取catalog.txt文件，并输出文件内容
*
*函数参数：  无
*
*函数返回值：void
*********************************************************************/
void Catalog::PrintCatalog()
{
    cout << "\n\n\t\t\t浏览分类图书\n\n" << endl;
    //定义文件对象 in, 并打开文件
	ifstream in ("catalog.txt", ios::in | ios::app);
	if(!in)
    {
        cout << "\n\t\t\t文件打开失败！\n" << endl;
        exit(0);
    }
    cout << "=================================================" << endl;
    cout << "分类图书编号" << '\t' << "图书类名" << '\t' << "分类图书父类编号" << endl;
    cout << "=================================================\n" << endl;

    //预先读取文件信息，防止文件信息漏读最后一条
    in >> C.Key >> C.Caption >> C.Parent;
	while (!in.eof())
    {
        cout << C.Key << "\t\t" << C.Caption << "\t\t" << C.Parent << endl;
        in >> C.Key >> C.Caption >> C.Parent;
    }
    cout << "\n=================================================\n" << endl;
    //关闭文件
	in.close();
}



/********************************************************************
*函数名：    CreatLink()
*函数功能：  读取catalog.txt文件，并创建一个分类图书的链表
*
*函数参数：  无
*
*函数返回值：以头指针的形式的链表：head
*********************************************************************/
BookCatalogLink* Catalog::CreatLink()
{
    //定义结构体指针*head, *p, *q;
    BookCatalogLink *head, *p, *q;
    //使用指针前，对指针初始化为空
    head = NULL;
    q = NULL;
    p = NULL;

    //定义文件对象 in, 并打开文件
    ifstream in ("catalog.txt", ios::in);
    if(!in)
    {
        cout << "\n\t\t\t打开文件失败！";
        exit(0);
    }

    //对链表的头指针head申请一个BookCatalongLink大小的动态空间
    head = new BookCatalogLink;
    //把头指针head的地址赋值给p
    p = head;


    while (!in.eof())
    {
        //对链表的指针q申请一个BookCatalongLink大小的动态空间
        q = new BookCatalogLink;
        in >> q->Key >> q->Caption >> q->Parent;

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



/********************************************************************
*函数名：    DeleteCatalog()
*函数功能：  删除分类图书的相关信息
*
*函数参数：  无
*
*函数返回值：void
*********************************************************************/
void Catalog::DeleteCatalog()
{
    cout << "\n\n\t\t\t删除分类图书\n\n" << endl;
    //分类图书的编号
    string key;
    //定义一个标致变量
    int flag=0;

    //定义结构体指针*head, *p, *q;
    BookCatalogLink *head, *p, *q;
    //使用指针前，对指针初始化为空
    head = NULL;
    q = NULL;
    p = NULL;

    //创建一个链表
    head = CreatLink();

    cout << "请输入您要删除的分类图书编号：";
    cin  >> key;

    //把头指针head的指针域复制给指针p
    p = head -> next;
    //判断要删除的图书分类信息是否位于头指针head内
    if(key.compare(p->Key) == 0)
    {
        cout << "=================================================" << endl;
        cout << "分类图书编号" << '\t' << "图书类名" << '\t' << "分类图书父类编号" << endl;
        cout << "=================================================\n" << endl;
        cout << p->Key << "\t\t" << p->Caption << "\t\t" << p->Parent << endl;
        head -> next = p -> next;
        //释放指针p
        delete p;

        //保存删除后的信息
        SaveBookCatalog(head);

        cout << "\n\t\t\t删除成功！\n" << endl;
        //flag = 1;表示分类图书删除成功
        flag=1;
        cout << "\n=================================================\n" << endl;
    }

    //如果要删除的信息不是位于头指针head内，则执行下面语句
    else
    {
        for (p = head -> next; p != NULL; p = p -> next)
        {
            //把当前指针p的地址赋值给前一指针q
            q = p;
            if (key.compare(p->Key) == 0)
            {
                cout << "=================================================" << endl;
                cout << "分类图书编号" << '\t' << "图书类名" << '\t' << "分类图书父类编号" << endl;
                cout << "=================================================\n" << endl;
                cout << p->Key << "\t\t" << p->Caption << "\t\t" << p->Parent << endl;
                q -> next = p -> next;
                //释放指针p
                delete p;

                //保存删除后的信息
                SaveBookCatalog(head);
                //释放链表指针
                DeleteMemory(head);
                cout << "\n\t\t\t删除成功！\n" << endl;
                //flag = 1;表示分类图书删除成功
                flag=1;
                cout << "\n=================================================\n" << endl;
                break;
            }
        }
    }

    if(!flag)
    {
        cout << "\n\t\t\t没有此分类图书信息，删除失败！\n" << endl;
    }
    //释放链表指针
    DeleteMemory(head);
}



/********************************************************************
*函数名：    SaveBookCatalog()
*函数功能：  保存分类图书的相关信息
*
*函数参数：  以头指针的形式的链表：BookCatalogLink *head
*
*函数返回值：void
*********************************************************************/
void Catalog::SaveBookCatalog(BookCatalogLink *head)
{
    //定义结构体指针p
    BookCatalogLink *p;
    //对指针p初始化为空
    p = NULL;

    //创建文件对象，把图书分类信息写入到catalog.txt文件中
    ofstream out ("catalog.txt", ios::out);
    if (!out)
    {
        cout << "\n\t\t\t文件打开失败！\n" << endl;
        exit(0);
    }

    //遍历链表，把链表信息写入到文件中
    for (p = head->next; p != NULL; p = p->next)
    {
        out << p->Key << '\t' << p->Caption << '\t' << p->Parent << endl;
    }

    //关闭文件
    out.close();
}



/********************************************************************
*函数名：    DeleteMemory()
*函数功能：  释放分类图书的链表指针
*
*函数参数：  以头指针的形式的链表：BookCatalogLink *head
*
*函数返回值：void
*********************************************************************/
void Catalog::DeleteMemory(BookCatalogLink *head)
{
    //定义结构体指针*p, *q;
    BookCatalogLink *p, *q;
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



/********************************************************************
*函数名：    ModifyCatalog()
*函数功能：  修改分类图书的相关信息
*
*函数参数：  无
*
*函数返回值：void
*********************************************************************/
void Catalog::ModifyCatalog()
{
    cout << "\n\n\t\t\t修改分类图书\n\n" << endl;
    //图书分类的编号
    string key;
    //定义一个标致变量
    int flag=0;

    //定义结构体指针*head, *p;
    BookCatalogLink *head, *p;
    //使用指针前，对指针初始化为空
    head = NULL;
    p = NULL;

    //创建一个链表
    head = CreatLink();

    cout << "请输入您要修改的分类图书编号：";
    cin >> key;
    for (p = head -> next; p != NULL; p = p -> next)
    {
        if (key.compare(p->Key) == 0)
        {
            cout << "=================================================" << endl;
            cout << "分类图书编号" << '\t' << "图书类名" << '\t' << "分类图书父类编号" << endl;
            cout << "=================================================\n" << endl;
            cout << p->Key << "\t\t" << p->Caption << "\t\t" << p->Parent << endl;

            cout << "\n\n请输入修改后的信息：\n\n";
            cout << "输入分类图书的编号：";
            cin  >> p->Key;
            cout << "输入分类图书名称：";
            cin  >> p->Caption;
            cout << "输入分类图书的父类编号：";
            cin  >> p->Parent;

            //保存图书修改后的信息
            SaveBookCatalog(head);
            cout << "\n\t\t\t修改成功！\n" << endl;
            //flag=1；表示图书分类信息修改成功。
            flag=1;
            cout << "\n=================================================\n" << endl;
            break;
        }
    }
    if(!flag)
    {
        cout << "\n\t\t\t此分类图书信息不存在，修改失败！\n" << endl;
    }

    //释放链表指针
    DeleteMemory(head);
}



/********************************************************************
*函数名：    QueryCatalog()
*函数功能：  查询分类图书的相关信息
*
*函数参数：  无
*
*函数返回值：void
*********************************************************************/
void Catalog::QueryCatalog()
{
    cout << "\n\n\t\t\t查询分类图书\n\n" << endl;
    //分类图书编号
    string key;
    //定义一个标志变量
    int flag=0;

    //定义结构体指针*head, *p;
    BookCatalogLink *head, *p;
    //使用指针前，对指针初始化为空
    head = NULL;
    p = NULL;

    //创建一个链表
    head = CreatLink();

    cout << "请输入您要查询的分类图书编号：";
    cin >> key;
    //遍历链表
    for (p = head -> next; p != NULL; p = p -> next)
    {
        if (key.compare(p->Key) == 0)
        {
            cout << "=================================================" << endl;
            cout << "分类图书编号" << '\t' << "图书类名" << '\t' << "分类图书父类编号" << endl;
            cout << "=================================================\n" << endl;
            cout << p->Key << "\t\t" << p->Caption << "\t\t" << p->Parent << endl;
            //flag=1;表示查询到分类图书
            flag=1;
            cout << "\n=================================================\n" << endl;
            break;
        }
    }
    if(!flag)
    {
        cout << "\n\t\t\t没有查询到该分类图书信息！\n" << endl;
    }

    //释放链表指针
    DeleteMemory(head);
}



/********************************************************************
*函数名：    CreatCatalogTree()
*函数功能：  创建一个分类图书树，以链表的形式访问catalog.txt内容，
*             并把访问到的内容放到已建立的一个图书分类树连表中。
*
*函数参数：  无
*
*函数返回值：void
*********************************************************************/
void Catalog::CreatCatalogTree()
{
    cout << "\n\n\t\t\t图书分类树\n" << endl;
    cout << "=========================================================\n" << endl;
    //定义文件对象 in, 并打开文件
    ifstream in ("catalog.txt", ios::in);
    if (!in)
    {
        cout << "打开文件失败！" << endl;
        exit(0);
    }

    //变量i
    int i;
    //读取分类图书信息到链表中
	for (i = 0; !in.eof(); i++)
    {
        in >> Ctree.Node[i].Key >> Ctree.Node[i].Caption >> Ctree.Node[i].Parent;

    }

    //遍历得到分类树的节点个数
    Ctree.num = i;
    //把分类树的根置为0
    Ctree.root = 0;

    //关闭文件
    in.close();

    //输出分类树
    PrintCatalogTree(&Ctree);
    cout << "\n\n=========================================================\n" << endl;
}



/********************************************************************
*函数名：    PrintCatalogTree()
*函数功能：  使用递归的方法，输出分类树。
*
*函数参数：  分类树链表：CatalogTree  *Ctree
*
*函数返回值：void
*********************************************************************/
void Catalog::PrintCatalogTree(CatalogTree *Ctree)
{
    //初始化树的深度为1
    int depth = 1;

    //使用递归的方法遍历链表
    Traverse(Ctree, 0, depth);
}



/********************************************************************
*函数名：    Traverse()
*函数功能：  使用递归的方法，遍历分类树。
*
*函数参数：  分类树链表：CatalogTree  *Ctree
*             树的深度：int depth
*
*
*函数返回值：void
*********************************************************************/
void Catalog::Traverse(CatalogTree *Ctree, int k, int depth)
{
    //定义变量i,j,t;
    int i, j, t;

    //定义开始遍历分类树的位置，即从分类树的根开始遍历
    t = 0;

    for (i = 0; i < depth; i++)
    {
        cout << "     ";
    }
    cout << "|--" << Ctree->Node[k].Caption << "--" << Ctree->Node[k].Key << endl;;

    //遍历分类树
    for (j=k+1; j<Ctree->num; j++)
	{
	    //判断是否遍历到最后一个节点
		if ( Ctree->Node[j].Parent.compare(Ctree->Node[k].Key) == 0 )
		{
			if (0 == t)
			{
			    //使用递归的方法，继续调用遍历函数
				Traverse(Ctree, j, ++depth);
				t++;
			}
            else
            {
                //使用递归的方法，继续调用遍历函数
                Traverse(Ctree, j, depth);
            }
		}
	}
}



/**************************************************
*函数名：    ~Catalog()
*函数功能：  对象生存期结束时，系统调用析构函数
*
*
*函数参数：  无
**************************************************/
Catalog::~Catalog()
{}
