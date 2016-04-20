/******************************************************************
*
*Copyright(c)2015,�ϲ���ѧ���ѧԺʵ��С��(�Ż�������Ȼ�����¾�)
*All rights reserved.
*
*�ļ����ƣ� Catalog.h
*�ļ���ʶ�� �����ù���ƻ���
*ժ    Ҫ��  ���ļ�����Ҫ����ͼ�����Ĺ��ܺ������������Լ���
*            ͼ�����BookCatalogLink�ṹ�壬ͼ�������CatalogTree
*            �Ľṹ�������������ͼ�����Catalog�࣬����Catalog��
*            ����������
*
*
*��ǰ�汾��1.0
*���ߣ����¾�
*������ڣ�2015/6/8
*��һ���޸ģ�2015/6/14
*�ڶ����޸ģ�2015/6/20
*
********************************************************************/


#ifndef    CATALOG_H               //��ֹCatalog.h���ظ�����
#define    CATALOG_H


#include   "Main.h"                //���÷Ǳ�׼�⺯��
#define    MAX_NODE   100          //����ͼ������ĸ���������100


/****************************************************************
*�ṹ������BookCatalogLink
*
*�ṹ���Ա���ԣ�public
*���ݳ�Ա��
*             string Key;                   //����ͼ���Լ����
*             string Caption;               //����ͼ�������
*             string Parent;                //����ͼ�鸸�׵ı��
*             struct BookCatalogLink *next; //����һ���ṹ��ָ��
******************************************************************/
typedef struct BookCatalogLink
{
public:
	//����ͼ���Լ����
	string Key;
	//����ͼ�������
	string Caption;
	//����ͼ�鸸�׵ı��
	string Parent;

    //����һ���ṹ��ָ��
	struct BookCatalogLink *next;
}BookCatalogLink;



/*********************************************************************
*�ṹ������CatalogTree
*
*�ṹ���Ա���ԣ�public
*���ݳ�Ա��
*          BookCatalogLink Node[MAX_NODE]; //��������ͼ����������
*          int root;                       //�������ĸ��ڵ�
*          int num;                        //�������нڵ�ĸ���
**********************************************************************/
typedef struct CatalogTree
{
public:
	//��������ͼ��������������
	BookCatalogLink Node[MAX_NODE];
	//�������ĸ��ڵ�
	int root;
	//�������нڵ�ĸ���
	int num;
}CatalogTree;



/*******************************************************************
*������      Catalog
*
*���Ա���ԣ�protected
*���ݳ�Ա��
*             struct BookCatalogLink C; //����ͼ��ṹ��
*             struct CatalogTree Ctree; //����ͼ�����ṹ��
*
*
*���Ա���ԣ�private
*��Ա������
*             //�޲ι��캯��
*             Catalog();
*             //����ͼ�����
*             void AddCatalog();
*             //���ͼ�����
*             void PrintCatalog();
*             //����BookCatalog����
*             BookCatalogLink *CreatLink();
*             //�ͷ�ָ������
*             void DeleteMemory(BookCatalogLink *head);
*             //ɾ��ͼ�����
*             void DeleteCatalog();
*             //����ɾ�������Ϣ
*             void SaveBookCatalog(BookCatalogLink *head);
*             //�޸�ͼ�����
*             void ModifyCatalog();
*             //��ѯͼ�����
*             void QueryCatalog();
*             //���ͼ�������
*             void PrintCatalogTree(CatalogTree *tree);
*             //����ͼ�������
*             void CreatCatalogTree();
*             //����ͼ�������
*             void Traverse(CatalogTree *tree, int k, int level);
*             //��������
*             ~Catalog();
***********************************************************************/
class Catalog
{
private:
    //����ͼ��ṹ��
    struct BookCatalogLink C;
    //����ͼ�����ṹ��
    struct CatalogTree Ctree;
public:
    //�޲ι��캯��
    Catalog();
    //����ͼ�����
    void AddCatalog();
    //���ͼ�����
    void PrintCatalog();
    //����BookCatalog����
    BookCatalogLink *CreatLink();
    //�ͷ�ָ������
    void DeleteMemory(BookCatalogLink *head);
    //ɾ��ͼ�����
    void DeleteCatalog();
    //�������ͼ�����Ϣ
    void SaveBookCatalog(BookCatalogLink *head);
    //�޸�ͼ�����
    void ModifyCatalog();
    //��ѯͼ�����
    void QueryCatalog();
    //���ͼ�������
    void PrintCatalogTree(CatalogTree *tree);
    //����ͼ�������
    void CreatCatalogTree();
    //����ͼ�������
    void Traverse(CatalogTree *tree, int k, int level);
    //��������
    ~Catalog();
};



#endif // CATALOG_H
