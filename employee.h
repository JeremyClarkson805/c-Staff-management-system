//
// Created by 13442 on 2023/4/22.
//


#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

//Ա����
class Employee : public Worker
{
public:
    Employee(int id,string name,int dId);
    //��ʾ������Ϣ
    virtual void ShowInfo();
    //��ȡְ����λ����
    virtual string GetDeptName();
};




