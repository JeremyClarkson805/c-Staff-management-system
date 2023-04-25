//
// Created by 13442 on 2023/4/22.
//

#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager
{
public:
    WorkerManager();

    void Show_Menu();

    void ExitSystem();

    int m_EmpNum;//��¼ְ������

    Worker ** m_EmpArray;//ְ������ָ��

    void Add_Emp();//���Ա��

    void save();//�����ļ�

    bool m_FileIsEmpty;//�ж��ļ��Ƿ�Ϊ�յı�־

    int get_EmpNum();//ͳ���ļ�������

    void init_Emp();

    void Show_Emp();//��ʾְ��

    int IsExist(int id);

    void Del_Emp();//ɾ��Ա��

    void Mod_Emp();//�޸�ְ������

    void Find_Emp();//����ְ��

    void Clean_File();//����ļ�

    ~WorkerManager();
};

