//
// Created by 13442 on 2023/4/22.
//

#include"workerManger.h"

WorkerManager::WorkerManager()
{

    //1.文件不存在
    ifstream ifs;
    ifs.open(FILENAME,ios::in);//读文件
    if(!ifs.is_open())
    {
        cout<<"当前文件不存在"<<endl;
        //初始化属性
        //初始化记录人数
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        //初始化文件是否为空?
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    //2.文件存在 数据为空
    char ch;
    ifs>>ch;
    if(ifs.eof())//eof()如果这个函数为真，说明文件已经完全读取进来了
    {
        //文件为空
        cout<<"当前文件为空"<<endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        //初始化文件是否为空?
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;
}

void WorkerManager::Show_Menu()
{
    cout<<"---------------------------"<<endl;
    cout<<"-->欢迎使用职工管理系统<---"<<endl;
    cout<<"      0.退出管理系统"<<endl;
    cout<<"      1.增加职工信息"<<endl;
    cout<<"      2.显示职工消息"<<endl;
    cout<<"      3.删除离职员工"<<endl;
    cout<<"      4.修改职工信息"<<endl;
    cout<<"      5.查找职工信息"<<endl;
    cout<<"      6.按照编号排序"<<endl;
    cout<<"      7.清空所有文档"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<endl;
}

void WorkerManager::ExitSystem()
{
    cout<<"欢迎下次使用"<<endl;
    system("pause");
    exit(0);//不管这段函数在哪，只要碰到了就会退出
}

void WorkerManager::Add_Emp()//添加新职工
{
    cout<<"请输入需要新增的职工的数量"<<endl;
    int addNum = 0;//保存用户输入的数
    cin>>addNum;
    if (addNum>0)
    {
        int newSize = this->m_EmpNum + addNum;//新空间 = 原来记录人数 + 新增人数
        Worker ** newSpace = new Worker *[newSize];//开辟新空间
        if (this->m_EmpArray != NULL)
        {
            for(int i=0;i<this->m_EmpNum;i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        for(int i=0;i<addNum;i++)
        {
            int id;//部门编号
            string name;//职工姓名
            int dSelect;//部门选择
            cout<<"请输入第"<<i+1<<"个新职工编号:"<<endl;
            cin>>id;
            cout<<"请输入第"<<i+1<<"个新职工姓名:"<<endl;
            cin>>name;
            cout<<"请选择该职工的岗位:"<<endl;
            cout<<"1.普通职工"<<endl;
            cout<<"2.经理"<<endl;
            cout<<"3.BOSS"<<endl;
            cin>>dSelect;
            Worker *worker = NULL;
            switch (dSelect)
            {
                case 1:
                    worker = new Employee(id,name,1);
                    break;
                case 2:
                    worker = new Manger(id,name,2);
                    break;
                case 3:
                    worker = new Boss(id,name,3);
                    break;
                default:
                    break;
            }
            //将创建职工职责,保存到数组中
            newSpace[this->m_EmpNum + i] = worker;
        }
        delete[] this->m_EmpArray;//释放原有空间
        this->m_EmpArray = newSpace;//更新新空间的指向
        this->m_EmpNum = newSize;//更新新的职工人数
        this->save();//保存数据到文件中
        this->m_FileIsEmpty = false;//更新职工不为空的标志
        cout<<"成功添加"<<addNum<<"名新员工"<<endl;
    }
    else
    {
        cout<<"数据输入有误"<<endl;
    }
    //按任意键后 清屏回到上级目录
    system("pause");
    system("cls");
}

void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out);//用输出的方式打开文件
    for(int i=0;i<this->m_EmpNum;i++)//将每个人的信息都写入文件
    {
        ofs<<this->m_EmpArray[i]->m_Id<<" ";
        ofs<<this->m_EmpArray[i]->m_Name<<" ";
        ofs<<this->m_EmpArray[i]->m_DepId<<endl;
    }
    ofs.close();
}


//WorkerManager::~WorkerManager()
//{
//
//}