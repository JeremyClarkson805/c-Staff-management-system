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

void Employee::ShowInfo()
{
    cout<<"ְ�����:"<<this->m_Id;
    cout<<"\tְ������:"<<this->m_Name;
    cout<<"\t��λ:"<<this->GetDeptName();
    cout<<"\t��λְ��:������Ļ�!!!"<<endl;
}

string Employee::GetDeptName()
{
    return string("Ա��");
}