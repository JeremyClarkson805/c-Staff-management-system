//
// Created by 13442 on 2023/4/22.
//

#pragma once
#include<iostream>
#include<string>
using namespace std;

//ְ���������
class Worker
{
public:
    //��ʾ������Ϣ
    virtual void ShowInfo() = 0;
    //��ȡ��λ��Ϣ
    virtual string GetDeptName() = 0;
    int m_Id;//ְ�����
    string m_Name;//ְ������
    int m_DepId;//ְ�����ڲ��ű��
};




