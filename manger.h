//
// Created by 13442 on 2023/4/23.
//

#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

//������
class Manger : public Worker
{
public:
    Manger(int id,string name,int dId);
    //��ʾ������Ϣ
    virtual void ShowInfo();
    //��ȡְ����λ����
    virtual string GetDeptName();
};