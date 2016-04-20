/******************************************************************
*
*Copyright(c)2015,�ϲ���ѧ���ѧԺʵ��С��(�Ż�������Ȼ�����¾�)
*All rights reserved.
*
*�ļ����ƣ� Menu.h
*�ļ���ʶ�� �����ù���ƻ���
*ժ    Ҫ��  ���ļ���Ҫ�Ƕ���˵���Menu,���Ը����������ҶԸ����ڵ�
*            ���ݳ�Ա�ͳ�Ա��������������
*
*
*��ǰ�汾��1.0
*���ߣ�����Ȼ
*������ڣ�2015/5/27
*��һ���޸ģ�2015/6/1
*�ڶ����޸ģ�2015/6/3
*
********************************************************************/

#ifndef  MENU_H                            //��ֹMain.h���ظ�����
#define  MENU_H


/****************************************************************************
*������      Menu
*
*���Ա���ԣ�private
*���Ա��    int choose;                    //�����û�ѡ�񣬼����˶�ζ���
*
*���Ա���ԣ�Public
*���Ա������
*      1.void MainOfMenu();                 //ͼ�����ϵͳ���˵�
*      2.void MainOfMenu_Choose();          //ͼ�����ϵͳ���˵�ѡ��
*      3.void ReaderOfMenu();               //���߹����Ӳ˵�
*      4.void ReaderOfMenu_Choose();        //���߹����Ӳ˵�ѡ��
*      5.void BookOfMenu();                 //��Ŀ�����Ӳ˵�
*      6.void BookOfMenu_Choose();          //��Ŀ�����Ӳ˵�ѡ��
*      7.void CatalogOfMenu();              //����Ŀ¼�����Ӳ˵�
*      8.void CatalogOfMenu_Choose();       //����Ŀ¼�����Ӳ˵�ѡ��
*      9.void CirculationOfMenu();          //ͼ����ͨ�����Ӳ˵�
*     10.void CirculationOfMenu_Choose();   //ͼ����ͨ�����Ӳ˵�ѡ��
*     11.void AccountOfMenu();              //�˻������Ӳ˵�
*     12.void AccountOfMenu_Choose();       //�˻������Ӳ˵�ѡ��
*     13.void InterfaceOfMenu();            //ͼ�����ϵͳ��ڲ˵�
*************************************************************************/
class Menu
{
private:
    //�˵�ѡ��ѡ��
    int choose;
public :
    //ͼ�����ϵͳ���˵�
    void MainOfMenu();
    //ͼ�����ϵͳ���˵�ѡ��
    void MainOfMenu_Choose();
    //���߹����Ӳ˵�
    void ReaderOfMenu();
    //���߹����Ӳ˵�ѡ��
    void ReaderOfMenu_Choose();
    //��Ŀ�����Ӳ˵�
    void BookOfMenu();
    //��Ŀ�����Ӳ˵�ѡ��
    void BookOfMenu_Choose();
    //����Ŀ¼�����Ӳ˵�
    void CatalogOfMenu();
    //����Ŀ¼�����Ӳ˵�ѡ��
    void CatalogOfMenu_Choose();
    //ͼ����ͨ�����Ӳ˵�
    void CirculationOfMenu();
    //ͼ����ͨ�����Ӳ˵�ѡ��
    void CirculationOfMenu_Choose();
    //�˻������Ӳ˵�
    void AccountOfMenu();
    //�˻������Ӳ˵�ѡ��
    void AccountOfMenu_Choose();
    //������˵�
    void InterfaceOfMenu();
};


#endif // MENU_H



