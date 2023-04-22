//
// Created by 13442 on 2023/4/22.
//

#pragma once//防止头文件重复包含
#include<iostream>
using namespace std;

class WorkerManager
{
public:
    WorkerManager()
    {}
    void Show_Menu();
    void ExitSystem();
    ~WorkerManager()
    {}
};

//#include "WorkerManger.cpp"