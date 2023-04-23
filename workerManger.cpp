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

    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;
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
    cout<<"      6.���ձ������"<<endl;
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


//WorkerManager::~WorkerManager()
//{
//
//}