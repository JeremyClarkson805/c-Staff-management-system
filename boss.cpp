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
    cout<<"ְ�����:"<<this->m_Id;
    cout<<"\tְ������:"<<this->m_Name;
    cout<<"\t��λ:"<<this->GetDeptName();
    cout<<"\t��λְ��:���ڹ�˾�����!!!!!"<<endl;
}

string Boss::GetDeptName()
{
    return string("�����Boss������");
}