//
// Created by 13442 on 2023/4/23.
//

#include "manager.h"

Manger::Manger(int id, std::string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DepId = dId;
}

void Manger::ShowInfo()
{
    cout<<"职工编号:"<<this->m_Id;
    cout<<"\t职工姓名:"<<this->m_Name;
    cout<<"\t岗位:"<<this->GetDeptName();
    cout<<"\t岗位职责:听老板的话!!!管理员工"<<endl;
}

string Manger::GetDeptName()
{
    return string("这个是经理！！！");
}