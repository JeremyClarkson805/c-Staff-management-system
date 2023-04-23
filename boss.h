//
// Created by 13442 on 2023/4/23.
//

#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

class Boss : public Worker
{
public:
    Boss(int id,string name,int dId);
    virtual void ShowInfo();
    virtual string GetDeptName();
};