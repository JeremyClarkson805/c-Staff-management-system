#include <iostream>
#include "WorkerManger.h"
using namespace std;



int main() {
    WorkerManager wm;
    int choice = 0;
    while(true)
    {
        wm.Show_Menu();
        cout<<"请输入您的选择:"<<endl;
        cin>>choice;
        switch (choice)
        {
            case 0://退出
                wm.ExitSystem();
                break;
            case 1://添加职工
                break;
            case 2://显示职工
                break;
            case 3://删除职工
                break;
            case 4://修改职工
                break;
            case 5://查找职工
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
