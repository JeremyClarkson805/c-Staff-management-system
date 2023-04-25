//
// Created by 13442 on 2023/4/22.
//

#include"workerManger.h"

WorkerManager::WorkerManager()
{

    //1.�ļ�������
    ifstream ifs;
    ifs.open(FILENAME,ios::in);//���ļ�
    if(!ifs.is_open())
    {
        cout<<"��ǰ�ļ�������"<<endl;
        //��ʼ������
        //��ʼ����¼����
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        //��ʼ���ļ��Ƿ�Ϊ��?
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    //2.�ļ����� ����Ϊ��
    char ch;
    ifs>>ch;
    if(ifs.eof())//eof()����������Ϊ�棬˵���ļ��Ѿ���ȫ��ȡ������
    {
        //�ļ�Ϊ��
        cout<<"��ǰ�ļ�Ϊ��"<<endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        //��ʼ���ļ��Ƿ�Ϊ��?
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    //3.�ļ��Ѵ���,���Ҽ�¼����
    int num = this->get_EmpNum();
//    cout<<"ְ������Ϊ:"<<num<<endl;
    this->m_EmpNum = num;
    this->m_EmpArray = new Worker * [this->m_EmpNum];//���ٿռ�
    this->m_FileIsEmpty = false;
//    this->m_EmpNum = 0;
//    this->m_EmpArray = NULL;
    this->init_Emp();//���ļ��е����ݴ浽������
//    for(int i=0;i<this->m_EmpNum;i++)
//    {
//        cout<<"ְ�����:"<<this->m_EmpArray[i]->m_Id;
//        cout<<"\t����:"<<this->m_EmpArray[i]->m_Name;
//        cout<<"\t���ű��"<<this->m_EmpArray[i]->m_DepId<<endl;
//    }
}

void WorkerManager::Show_Menu()
{
    cout<<"---------------------------"<<endl;
    cout<<"-->��ӭʹ��ְ������ϵͳ<---"<<endl;
    cout<<"      0.�˳�����ϵͳ"<<endl;
    cout<<"      1.����ְ����Ϣ"<<endl;
    cout<<"      2.��ʾְ����Ϣ"<<endl;
    cout<<"      3.ɾ����ְԱ��"<<endl;
    cout<<"      4.�޸�ְ����Ϣ"<<endl;
    cout<<"      5.����ְ����Ϣ"<<endl;
//    cout<<"      6.���ձ������"<<endl;
    cout<<"      7.��������ĵ�"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<endl;
}

void WorkerManager::ExitSystem()
{
    cout<<"��ӭ�´�ʹ��"<<endl;
    system("pause");
    exit(0);//������κ������ģ�ֻҪ�����˾ͻ��˳�
}

void WorkerManager::Add_Emp()//�����ְ��
{
    cout<<"��������Ҫ������ְ��������"<<endl;
    int addNum = 0;//�����û��������
    cin>>addNum;
    if (addNum>0)
    {
        int newSize = this->m_EmpNum + addNum;//�¿ռ� = ԭ����¼���� + ��������
        Worker ** newSpace = new Worker *[newSize];//�����¿ռ�
        if (this->m_EmpArray != NULL)
        {
            for(int i=0;i<this->m_EmpNum;i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        for(int i=0;i<addNum;i++)
        {
            int id;//���ű��
            string name;//ְ������
            int dSelect;//����ѡ��
            cout<<"�������"<<i+1<<"����ְ�����:"<<endl;
            cin>>id;
            cout<<"�������"<<i+1<<"����ְ������:"<<endl;
            cin>>name;
            cout<<"��ѡ���ְ���ĸ�λ:"<<endl;
            cout<<"1.��ְͨ��"<<endl;
            cout<<"2.����"<<endl;
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
            //������ְ��ְ��,���浽������
            newSpace[this->m_EmpNum + i] = worker;
        }
        delete[] this->m_EmpArray;//�ͷ�ԭ�пռ�
        this->m_EmpArray = newSpace;//�����¿ռ��ָ��
        this->m_EmpNum = newSize;//�����µ�ְ������
        this->save();//�������ݵ��ļ���
        this->m_FileIsEmpty = false;//����ְ����Ϊ�յı�־
        cout<<"�ɹ����"<<addNum<<"����Ա��"<<endl;
    }
    else
    {
        cout<<"������������"<<endl;
    }
    //��������� �����ص��ϼ�Ŀ¼
    system("pause");
    system("cls");
}

void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out);//������ķ�ʽ���ļ�
    for(int i=0;i<this->m_EmpNum;i++)//��ÿ���˵���Ϣ��д���ļ�
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
    ifs.open(FILENAME,ios::in);//���ļ�
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
        if(dId == 1)//ְ��
        {
            worker = new Employee(id,name,dId);
        }
        else if (dId == 2)//����
        {
            worker = new Manger(id,name,dId);
        }
        else //�ϰ�
        {
            worker = new Boss(id,name,dId);
        }
        this->m_EmpArray[index] = worker;//�����������
        index++;
    }
    ifs.close();
}

void WorkerManager::Show_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
    }
    else
    {
        for(int i=0;i<m_EmpNum;i++)
        {
            //���ö�̬���ýӿ�
            this->m_EmpArray[i]->ShowInfo();
        }
    }
    system("pause");
    system("cls");
}

int WorkerManager::IsExist(int id)
{
    int index = -1;
    for(int i=0;i<this->m_EmpNum;i++)  // ==-1 ->ְ�����ڣ�else������
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
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
    }
    else
    {
        cout<<"������Ҫɾ����ְ�����"<<endl;
        int id = 0;
        cin>>id;
        int index = this->IsExist(id);
        if(index != -1)
        {
            for(int i = index;i<this->m_EmpNum-1;i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i+1];//������ǰ��
            }
            this->m_EmpNum --;//���������м�¼��Ա�ĸ���
            this->save();//����ͬ�����µ��ļ���
            cout<<"ɾ���ɹ�������"<<endl;
        }
        else
        {
            cout<<"ɾ��ʧ�ܣ�δ�ҵ���ְ��"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::Mod_Emp()
{
    if(this->m_FileIsEmpty)//�ȼ�����ְ������/������
    {
        cout<<"�ļ���ʧ"<<endl;
    }
    else
    {
        cout<<"���������޸�ְ���ı��"<<endl;
        int id;
        cin>>id;
        int ret = this->IsExist(id);
        if(ret != -1)
        {
            delete this->m_EmpArray[ret];
            int newId = 0;
            string newName = "";
            int dSelect = 0;
            cout<<"�鵽:"<<id<<"��ְ������������ְ����:"<<endl;
            cin>>newId;
            cout<<"������������:"<<endl;
            cin>>newName;
            cout<<"�������λ:"<<endl;
            cout<<"1.��ְͨ��"<<endl;
            cout<<"2.����"<<endl;
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
            this->m_EmpArray[ret] = worker;//������������ݴ��浽������
            cout<<"�޸ĳɹ�������"<<this->m_EmpArray[ret]->m_DepId<<endl;
            this->save();//�����鱣�浽�ļ���
        }
        else
        {
            cout<<"�޸�ʧ�ܣ����޴���"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::Find_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
    }
    else
    {
        cout<<"��������ҵķ�ʽ:"<<endl;
        cout<<"1.��ְ����Ų���"<<endl;
        cout<<"2.����������"<<endl;
        int select;
        cin>>select;
        if(select == 1)//��ְ���Ų���
        {
            int id;
            cout<<"��������ҵ�ְ�����:"<<endl;
            cin>>id;
            int ret = IsExist(id);
            if(ret != -1)
            {
                cout<<"���ҳɹ�����ְ����Ϣ����:"<<endl;
                this->m_EmpArray[ret]->ShowInfo();
            }
            else
            {
                cout<<"����ʧ�ܣ����޴��ˣ�"<<endl;
            }
        }
        else if(select == 2)//����������
        {
            string name;
            cout<<"��������ҵ�����:"<<endl;
            cin>>name;
            bool flag = false;//���ҵ��ı�־
            for(int i=0;i<m_EmpNum;i++)
            {
                if(m_EmpArray[i]->m_Name == name)
                {
                    cout<<"����ʧ�ܣ�ְ�����Ϊ:"<<m_EmpArray[i]->m_Id<<"�ŵ���Ϣ����:"<<endl;
                    flag = true;
                    this->m_EmpArray[i]->ShowInfo();
                }
            }
            if (flag == false)
            {
                cout<<"����ʧ�ܣ����޴���"<<endl;
            }
        }
        else
        {
            cout<<"����ѡ������"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::Clean_File()
{
    cout<<"���Ҫ�����?"<<endl;
    cout<<"1.ȷ��"<<endl;
    cout<<"2.�ٵģ��������"<<endl;
    int select = 0;
    cin>>select;
    if(select == 1)
    {
        ofstream ofs(FILENAME,ios::trunc);//ios::trunc ����ļ����ھ�ɾ���ļ������´���
        ofs.close();
        if(this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; ++i) //ɾ��������ÿ��ְ������
            {
                if(this->m_EmpArray !=NULL)
                {
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum = 0;
            delete[] this-> m_EmpArray;//ɾ����������ָ��
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;
        }
        cout<<"��ղ���ִ�гɹ�������"<<endl<<"you Lost everything������"<<endl;
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