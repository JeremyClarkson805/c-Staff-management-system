//
// Created by 13442 on 2023/4/22.
//

#pragma once
#include<iostream>
#include<string>
using namespace std;

//职工抽象基类
class Worker
{
public:
    //显示个人信息
    virtual void ShowInfo() = 0;
    //获取岗位信息
    virtual string GetDeptName() = 0;
    int m_Id;//职工编号
    string m_Name;//职工姓名
    int m_DepId;//职工所在部门编号
};




