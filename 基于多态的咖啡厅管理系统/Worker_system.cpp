#include "Worker_system.h"


Worker_system::Worker_system()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	if (!ifs.is_open())
	{
		cout << "ְ���ļ�������" << endl;
		//��ʼ������
		this->m_EmpNum = 0;		//��ʼ����¼����
		this->m_EmpArray = NULL;//��ʼ������ָ��
		this->m_FileIsEmpty = true;//��ʼ���ļ�Ϊ��
		ifs.close();
		return;
	}
	//2.�ļ����� ���ļ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "ְ���ļ�Ϊ�գ�" << endl;
		this->m_EmpNum = 0;		//��ʼ����¼����
		this->m_EmpArray = NULL;//��ʼ������ָ��
		this->m_FileIsEmpty = true;//��ʼ���ļ�Ϊ��
		ifs.close();
		return;
	}
	else//3.�ļ����ڣ��Ҳ�Ϊ��
	{
		int num = this->get_EmpNum();
		cout << "ְ������Ϊ��" << num << endl;
		this->m_EmpNum = num;
		//���ٿռ�
		this->m_EmpArray = new Worker * [this->m_EmpNum];
		//���ļ��е����ݣ��浽������
		this->init_Emp();
	}
}

void Worker_system::Show_Menu()
{
	cout << "************************************" << endl;
	cout << "******* ��ӭʹ��ְ������ϵͳ *******" << endl;
	cout << "********** 0.�����ϸ����� **********" << endl;
	cout << "********** 1.����ְ����Ϣ **********" << endl;
	cout << "********** 2.��ʾְ����Ϣ **********" << endl;
	cout << "********** 3.ɾ����ְְ�� **********" << endl;
	cout << "********** 4.�޸�ְ����Ϣ **********" << endl;
	cout << "********** 5.���ձ������ **********" << endl;
	cout << "************************************" << endl;
	cout << endl;
}

int Worker_system::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�  ��
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;//ͳ�Ʊ�������
	}
	return num;
}

void Worker_system::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int indx = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Waiter(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[indx] = worker;
		indx++;
	}
	ifs.close();
}

void Worker_system::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//д�ļ�
	//��ÿ��������д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	//�ر��ļ�
	ofs.close();
}

void Worker_system::Add_Emp()
{
	cout << "���������ְ����������" << endl;
	int addNum = 0;//�����û����������
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;//�¿ռ������=ԭ���ռ������+����������
		Worker** newSpace = new Worker * [newSize];//�����¿ռ�
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;		//ְ�����
			string name;//ְ������
			int dSelsct;//����ѡ��
			cout << "�������" << i + 1 << "����ְ�����" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "����ְ����λ" << endl;
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1.����Ա" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelsct;
			Worker* worker = NULL;
			switch (dSelsct)
			{
			case 1:
				worker = new Waiter(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//������ְ��ְ�𣬱��浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		//�����µ�ְ������
		this->m_EmpNum = newSize;
		//�������ݵ��ļ�
		this->save();
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "��Ա��" << endl;
		//�����ļ���Ϊ�յı�־
		this->m_FileIsEmpty = false;
	}
	else
	{
		cout << "��������" << endl;
	}
	//��������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

void Worker_system::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "ְ���ļ������ڻ�Ϊ���ļ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

int Worker_system::IsExist(int id)
{
	int index = -1;
	if (this->m_FileIsEmpty)
	{
		cout << "ְ���ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]->m_Id == id)
			{
				//�ҵ�ְ��
				index = i;
				break;
			}
		}
	}
	return index;
}

void Worker_system::Del_Emp()
{
	cout << "��������Ҫɾ��ְ���ı�ţ�" << endl;
	int id = 0;
	cin >> id;
	int index = IsExist(id);
	if (index != -1)//˵����ɾ��Ա�����ڣ�����ɾ����indexλ�õ�Ա��
	{
		for (int i = index; i < this->m_EmpNum - 1; i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		cout << "ɾ���ɹ���" << endl;
		this->m_EmpNum--;//����������ְ������
		this->save();	//���º󱣴浽�ļ�
	}
	else
	{
		cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << endl;
	}
	system("pause");
	system("cls");
}

void Worker_system::Mod_Emp()
{
	cout << "��������Ҫ�޸�ְ���ı�ţ�" << endl;
	int id;
	cin >> id;
	int index = IsExist(id);
	if (index != -1)//˵�����޸ĵ�Ա������
	{
		int newId = 0;
		string newName = "";
		int dSelect = 0;
		cout << "�鵽��" << id << "��ְ����ְ����Ϣ���£�" << endl;
		this->m_EmpArray[index]->showInfo();
		delete this->m_EmpArray[index];
		cout << "�������µ�ְ���ţ�" << endl;
		cin >> newId;
		cout << "�������µ�������" << endl;
		cin >> newName;
		cout << "�������µĸ�λ��" << endl;
		cout << "1.����Ա" << endl;
		cout << "2.����" << endl;
		cout << "3.�ϰ�" << endl;
		cin >> dSelect;
		Worker* worker = NULL;
		switch (dSelect)
		{
		case 1:
			worker = new Boss(newId, newName, dSelect);
			break;
		case 2:
			worker = new Manager(newId, newName, dSelect);
			break;
		case 3:
			worker = new Boss(newId, newName, dSelect);
			break;
		default:
			break;
		}
		this->m_EmpArray[index] = worker;//�������ݵ�������
		this->save();					//���浽�ļ���
		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

void Worker_system::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1.��ְ���������" << endl;
		cout << "2.��ְ����Ž���" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else//����
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "����ɹ����������Ϊ��" << endl;
		this->save();
		this->show_Emp();
	}
}



Worker_system::~Worker_system()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}