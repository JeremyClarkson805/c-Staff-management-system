//
// Created by 13442 on 2023/4/23.
//

#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

//经理类
class Manger : public Worker
{
public:
    Manger(int id,string name,int dId);
    //显示个人信息
    virtual void ShowInfo();
    //获取职工岗位名称
    virtual string GetDeptName();
};