/******************************************************************
*
*Copyright(c)2015,南昌大学软件学院实验小组(张欢，王沛然，闫致敬)
*All rights reserved.
*
*文件名称： Catalog.h
*文件标识： 见配置管理计划书
*摘    要：  本文件在主要包括图书分类的功能函数的声明，以及对
*            图书分类BookCatalogLink结构体，图书分类树CatalogTree
*            的结构体的声明。建立图书分类Catalog类，并对Catalog类
*            做出声明。
*
*
*当前版本：1.0
*作者：闫致敬
*完成日期：2015/6/8
*第一次修改：2015/6/14
*第二次修改：2015/6/20
*
********************************************************************/


#ifndef    CATALOG_H               //防止Catalog.h被重复引用
#define    CATALOG_H


#include   "Main.h"                //引用非标准库函数
#define    MAX_NODE   100          //定义图书种类的个数不超过100


/****************************************************************
*结构体名：BookCatalogLink
*
*结构体成员属性：public
*数据成员：
*             string Key;                   //分类图书自己编号
*             string Caption;               //分类图书的类名
*             string Parent;                //分类图书父亲的编号
*             struct BookCatalogLink *next; //定义一个结构体指针
******************************************************************/
typedef struct BookCatalogLink
{
public:
	//分类图书自己编号
	string Key;
	//分类图书的类名
	string Caption;
	//分类图书父亲的编号
	string Parent;

    //定义一个结构体指针
	struct BookCatalogLink *next;
}BookCatalogLink;



/*********************************************************************
*结构体名：CatalogTree
*
*结构体成员属性：public
*数据成员：
*          BookCatalogLink Node[MAX_NODE]; //分类树中图书的种类个数
*          int root;                       //分类树的根节点
*          int num;                        //分类树中节点的个数
**********************************************************************/
typedef struct CatalogTree
{
public:
	//分类树中图书的种类个数多少
	BookCatalogLink Node[MAX_NODE];
	//分类树的根节点
	int root;
	//分类树中节点的个数
	int num;
}CatalogTree;



/*******************************************************************
*类名：      Catalog
*
*类成员属性：protected
*数据成员：
*             struct BookCatalogLink C; //分类图书结构体
*             struct CatalogTree Ctree; //分类图书树结构体
*
*
*类成员属性：private
*成员函数：
*             //无参构造函数
*             Catalog();
*             //增加图书分类
*             void AddCatalog();
*             //输出图书分类
*             void PrintCatalog();
*             //创建BookCatalog链表
*             BookCatalogLink *CreatLink();
*             //释放指针链表
*             void DeleteMemory(BookCatalogLink *head);
*             //删除图书分类
*             void DeleteCatalog();
*             //保存删除后的信息
*             void SaveBookCatalog(BookCatalogLink *head);
*             //修改图书分类
*             void ModifyCatalog();
*             //查询图书分类
*             void QueryCatalog();
*             //输出图书分类树
*             void PrintCatalogTree(CatalogTree *tree);
*             //创建图书分类树
*             void CreatCatalogTree();
*             //遍历图书分类树
*             void Traverse(CatalogTree *tree, int k, int level);
*             //析构函数
*             ~Catalog();
***********************************************************************/
class Catalog
{
private:
    //分类图书结构体
    struct BookCatalogLink C;
    //分类图书树结构体
    struct CatalogTree Ctree;
public:
    //无参构造函数
    Catalog();
    //增加图书分类
    void AddCatalog();
    //输出图书分类
    void PrintCatalog();
    //创建BookCatalog链表
    BookCatalogLink *CreatLink();
    //释放指针链表
    void DeleteMemory(BookCatalogLink *head);
    //删除图书分类
    void DeleteCatalog();
    //保存分类图书的信息
    void SaveBookCatalog(BookCatalogLink *head);
    //修改图书分类
    void ModifyCatalog();
    //查询图书分类
    void QueryCatalog();
    //输出图书分类树
    void PrintCatalogTree(CatalogTree *tree);
    //创建图书分类树
    void CreatCatalogTree();
    //遍历图书分类树
    void Traverse(CatalogTree *tree, int k, int level);
    //析构函数
    ~Catalog();
};



#endif // CATALOG_H
