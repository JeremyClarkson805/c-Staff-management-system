#include <iostream>
#include "WorkerManger.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;



int main() {
//    Worker *worker = NULL;
//    worker = new Employee(1,"����",01);
//    worker->ShowInfo();
//
//    Manger *manger = new Manger(2,"����",2);
//    manger->ShowInfo();
//
//    Boss *boss = new Boss(3,"star",3);
//    boss->ShowInfo();

    WorkerManager wm;
    int choice = 0;
    while(true)
    {
        wm.Show_Menu();
        cout<<"����������ѡ��:"<<endl;
        cin>>choice;
        switch (choice)
        {
            case 0://�˳�
                wm.ExitSystem();
                break;
            case 1://���ְ��
            wm.Add_Emp();
                break;
            case 2://��ʾְ��
                break;
            case 3://ɾ��ְ��
                break;
            case 4://�޸�ְ��
                break;
            case 5://����ְ��
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                system("cls");
                break;
        }
    }


    return 0;
}
