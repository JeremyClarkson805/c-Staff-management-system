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

    //3.文件已存在,并且记录数据
    int num = this->get_EmpNum();
//    cout<<"职工人数为:"<<num<<endl;
    this->m_EmpNum = num;
    this->m_EmpArray = new Worker * [this->m_EmpNum];//开辟空间
    this->m_FileIsEmpty = false;
//    this->m_EmpNum = 0;
//    this->m_EmpArray = NULL;
    this->init_Emp();//将文件中的数据存到数组中
//    for(int i=0;i<this->m_EmpNum;i++)
//    {
//        cout<<"职工编号:"<<this->m_EmpArray[i]->m_Id;
//        cout<<"\t姓名:"<<this->m_EmpArray[i]->m_Name;
//        cout<<"\t部门编号"<<this->m_EmpArray[i]->m_DepId<<endl;
//    }
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
//    cout<<"      6.按照编号排序"<<endl;
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

int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);//打开文件
    int id;
    string name;
    int dId;
    int num = 0;
    while(ifs >> id && ifs>>name && ifs >>dId)
    {
        num ++;
    }
    return num;
}

void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int dId;
    int index = 0;
    while(ifs>>id && ifs >> name && ifs >> dId)
    {
        Worker * worker = NULL;
        if(dId == 1)//职工
        {
            worker = new Employee(id,name,dId);
        }
        else if (dId == 2)//经理
        {
            worker = new Manger(id,name,dId);
        }
        else //老板
        {
            worker = new Boss(id,name,dId);
        }
        this->m_EmpArray[index] = worker;//存放在数组中
        index++;
    }
    ifs.close();
}

void WorkerManager::Show_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"文件不存在或记录为空"<<endl;
    }
    else
    {
        for(int i=0;i<m_EmpNum;i++)
        {
            //利用多态调用接口
            this->m_EmpArray[i]->ShowInfo();
        }
    }
    system("pause");
    system("cls");
}

int WorkerManager::IsExist(int id)
{
    int index = -1;
    for(int i=0;i<this->m_EmpNum;i++)  // ==-1 ->职工存在，else不存在
    {
        if(this->m_EmpArray[i]->m_Id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

void WorkerManager::Del_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"文件不存在或记录为空"<<endl;
    }
    else
    {
        cout<<"请输入要删除的职工编号"<<endl;
        int id = 0;
        cin>>id;
        int index = this->IsExist(id);
        if(index != -1)
        {
            for(int i = index;i<this->m_EmpNum-1;i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i+1];//将数据前移
            }
            this->m_EmpNum --;//更新数组中记录人员的个数
            this->save();//数据同步更新到文件中
            cout<<"删除成功！！！"<<endl;
        }
        else
        {
            cout<<"删除失败，未找到该职工"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::Mod_Emp()
{
    if(this->m_FileIsEmpty)//先检测这个职工存在/不存在
    {
        cout<<"文件丢失"<<endl;
    }
    else
    {
        cout<<"请输入所修改职工的编号"<<endl;
        int id;
        cin>>id;
        int ret = this->IsExist(id);
        if(ret != -1)
        {
            delete this->m_EmpArray[ret];
            int newId = 0;
            string newName = "";
            int dSelect = 0;
            cout<<"查到:"<<id<<"号职工，请输入新职工号:"<<endl;
            cin>>newId;
            cout<<"请输入新姓名:"<<endl;
            cin>>newName;
            cout<<"请输入岗位:"<<endl;
            cout<<"1.普通职工"<<endl;
            cout<<"2.经理"<<endl;
            cout<<"3.Boss"<<endl;
            cin>>dSelect;
            Worker *worker = NULL;
            switch(dSelect)
            {
                case 1:
                    worker = new Employee(newId,newName,dSelect);
                    break;
                case 2:
                    worker = new Manger(newId,newName,dSelect);
                    break;
                case 3:
                    worker = new Boss(newId,newName,dSelect);
                    break;
            }
            this->m_EmpArray[ret] = worker;//将更改玩的数据储存到数组中
            cout<<"修改成功！！！"<<this->m_EmpArray[ret]->m_DepId<<endl;
            this->save();//将数组保存到文件中
        }
        else
        {
            cout<<"修改失败，查无此人"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::Find_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"文件不存在或记录为空"<<endl;
    }
    else
    {
        cout<<"请输入查找的方式:"<<endl;
        cout<<"1.按职工编号查找"<<endl;
        cout<<"2.按姓名查找"<<endl;
        int select;
        cin>>select;
        if(select == 1)//按职工号查找
        {
            int id;
            cout<<"请输入查找的职工编号:"<<endl;
            cin>>id;
            int ret = IsExist(id);
            if(ret != -1)
            {
                cout<<"查找成功！该职工信息如下:"<<endl;
                this->m_EmpArray[ret]->ShowInfo();
            }
            else
            {
                cout<<"查找失败，查无此人！"<<endl;
            }
        }
        else if(select == 2)//按姓名查找
        {
            string name;
            cout<<"请输入查找的姓名:"<<endl;
            cin>>name;
            bool flag = false;//查找到的标志
            for(int i=0;i<m_EmpNum;i++)
            {
                if(m_EmpArray[i]->m_Name == name)
                {
                    cout<<"查找失败，职工编号为:"<<m_EmpArray[i]->m_Id<<"号的信息如下:"<<endl;
                    flag = true;
                    this->m_EmpArray[i]->ShowInfo();
                }
            }
            if (flag == false)
            {
                cout<<"查找失败，查无此人"<<endl;
            }
        }
        else
        {
            cout<<"输入选项有误"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::Clean_File()
{
    cout<<"真的要清空吗?"<<endl;
    cout<<"1.确定"<<endl;
    cout<<"2.假的，逗你玩的"<<endl;
    int select = 0;
    cin>>select;
    if(select == 1)
    {
        ofstream ofs(FILENAME,ios::trunc);//ios::trunc 如果文件存在就删除文件并重新创建
        ofs.close();
        if(this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; ++i) //删除堆区的每个职工对象
            {
                if(this->m_EmpArray !=NULL)
                {
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum = 0;
            delete[] this-> m_EmpArray;//删除堆区数组指针
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;
        }
        cout<<"清空操作执行成功！！！"<<endl<<"you Lost everything！！！"<<endl;
    }
    system("pause");
    system("cls");
}

WorkerManager::~WorkerManager()
{
    if(this->m_EmpArray != NULL)
    {
        for (int i = 0; i < this->m_EmpNum; ++i)
        {
            if(this->m_EmpArray[i] != NULL)
            {
                delete this->m_EmpArray[i];
            }
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}