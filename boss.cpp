//
// Created by 13442 on 2023/4/23.
//

#include "boss.h"

Boss::Boss(int id, std::string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DepId = dId;
}

void Boss::ShowInfo()
{
    cout<<"职工编号:"<<this->m_Id;
    cout<<"\t职工姓名:"<<this->m_Name;
    cout<<"\t岗位:"<<this->GetDeptName();
    cout<<"\t岗位职责:我在公司当大哥!!!!!"<<endl;
}

string Boss::GetDeptName()
{
    return string("这个是Boss！！！");
}