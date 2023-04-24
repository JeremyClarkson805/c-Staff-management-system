//
// Created by 13442 on 2023/4/22.
//

#pragma once//防止头文件重复包含
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

    int m_EmpNum;//记录职工人数

    Worker ** m_EmpArray;//职工数组指针

    void Add_Emp();//添加员工

    void save();//保存文件

    bool m_FileIsEmpty;//判断文件是否为空的标志

    int get_EmpNum();//统计文件中人数

    void init_Emp();

    void Show_Emp();//显示职工

    int IsExist(int id);

    void Del_Emp();//删除员工

    void Mod_Emp();//修改职工函数

    void Find_Emp();//查找职工

    void Clean_File();//清空文件

    ~WorkerManager();
};

