//
// Created by 13442 on 2023/4/22.
//

#include "employee.h"

Employee::Employee(int id, std::string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DepId = dId;
}

void Employee::showInfo()
{
    cout<<"职工编号:"<<this->m_Id;
    cout<<"\t职工姓名:"<<this->m_Name;
    cout<<"\t岗位:"<<this->getDepName();
    cout<<"\t岗位职责:听经理的话!!!"<<endl;
}

string Employee::getDepName()
{
    return string("员工");
}