//
// Created by 13442 on 2023/4/22.
//

#ifndef BASE_EMPLOYEE_H
#define BASE_EMPLOYEE_H

#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

//员工类
class Employee : public Worker
{
public:
    Employee(int id,string name,int dId);
    //显示个人信息
    virtual void showInfo();
    //获取职工岗位名称
    virtual string getDepName();
};



#endif //BASE_EMPLOYEE_H
