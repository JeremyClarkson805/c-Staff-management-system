//
// Created by 13442 on 2023/4/22.
//

#include"workerManger.h"

//WorkerManager::WorkerManager()
//{
//
//}

void WorkerManager::Show_Menu()
{
    cout<<"---------------------------"<<endl;
    cout<<"-->��ӭʹ��ְ������ϵͳ<---"<<endl;
    cout<<"      0.�˳�����ϵͳ"<<endl;
    cout<<"      1.����ְ����Ϣ"<<endl;
    cout<<"      2.��ʾְ����Ϣ"<<endl;
    cout<<"      3.ɾ����ְԱ��"<<endl;
    cout<<"      4.�޸�ְ����Ϣ"<<endl;
    cout<<"      5.����ְ����Ϣ"<<endl;
    cout<<"      6.���ձ������"<<endl;
    cout<<"      7.��������ĵ�"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<endl;
}

void WorkerManager::ExitSystem()
{
    cout<<"��ӭ�´�ʹ��"<<endl;
    system("pause");
    exit(0);//������κ������ģ�ֻҪ�����˾ͻ��˳�
}

//WorkerManager::~WorkerManager()
//{
//
//}