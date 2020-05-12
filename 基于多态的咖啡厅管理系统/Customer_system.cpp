#include "Customer_system.h"

Customer_system::Customer_system()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(CFILENAME, ios::in);//���ļ�
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		this->c_CusNum = 0;		//��ʼ����¼����
		this->c_CusArray = NULL;//��ʼ������ָ��
		this->c_FileIsEmpty = true;//��ʼ���ļ�Ϊ��
		ifs.close();
		return;
	}
	//2.�ļ����� ���ļ�Ϊ��
	//char ch;
	//ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		this->c_CusNum = 0;		//��ʼ����¼����
		this->c_CusArray = NULL;//��ʼ������ָ��
		this->c_FileIsEmpty = true;//��ʼ���ļ�Ϊ��
		ifs.close();
		return;
	}
	else//3.�ļ����ڣ��Ҳ�Ϊ��
	{
		int num = this->get_CusNum();
		cout << "�˿�����Ϊ��" << num << endl;
		this->c_CusNum = num;
		//���ٿռ�
		this->c_CusArray = new Customer * [this->c_CusNum];
		//���ļ��е����ݣ��浽������
		this->init_Cus();
	}
}

void Customer_system::Show_Menu()
{
	cout << "************************************" << endl;
	cout << "******* ��ӭʹ�ù˿͹���ϵͳ *******" << endl;
	cout << "********** 0.�����ϸ����� **********" << endl;
	cout << "********** 1.���ӹ˿���Ϣ **********" << endl;
	cout << "********** 2.��ʾ�˿���Ϣ **********" << endl;
	cout << "********** 3.ɾ���˿���Ϣ **********" << endl;
	cout << "********** 4.�޸Ĺ˿���Ϣ **********" << endl;
	cout << "********** 5.���ҹ˿���Ϣ **********" << endl;
	cout << "********** 6.���ձ������ **********" << endl;
	cout << "************************************" << endl;
	cout << endl;
}

void Customer_system::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);		//�˳�����
}


int Customer_system::get_CusNum()
{
	ifstream ifs;
	ifs.open(CFILENAME, ios::in);//���ļ�  ��
	int id;
	string name;
	int cId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> cId)
	{
		num++;//ͳ�Ʊ�������
	}
	return num;
}

void Customer_system::init_Cus()
{
	ifstream ifs;
	ifs.open(CFILENAME, ios::in);
	int id;
	string name;
	int cId;
	int indx = 0;
	while (ifs >> id && ifs >> name && ifs >> cId)
	{
		Customer* customer = NULL;
		if (cId == 1)
		{
			customer = new Svip(id, name, cId);
		}
		else if (cId == 2)
		{
			customer = new Hvip(id, name, cId);
		}
		else
		{
			customer = new Ovip(id, name, cId);
		}
		this->c_CusArray[indx] = customer;
		indx++;
	}
	ifs.close();
}

void Customer_system::Add_Cus()
{
	cout << "��������ӹ˿͵�������" << endl;
	int addNum = 0;//�����û����������
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->c_CusNum + addNum;//�¿ռ������=ԭ���ռ������+����������
		Customer** newSpace = new Customer * [newSize];//�����¿ռ�
		if (this->c_CusArray != NULL)
		{
			for (int i = 0; i < this->c_CusNum; i++)
			{
				newSpace[i] = this->c_CusArray[i];
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;		//�˿ͱ��
			string name;//�˿�����
			int dSelsct;//�˿͵ȼ����
			cout << "�������" << i + 1 << "���¹˿ͱ��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "���¹˿�����" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "���¹˿͵ȼ�" << endl;
			cout << "��ѡ��ù˿͵ȼ���" << endl;
			cout << "1.����VIP" << endl;
			cout << "2.���VIP" << endl;
			cout << "3.��ͨVIP" << endl;
			cin >> dSelsct;
			Customer* customer = NULL;
			switch (dSelsct)
			{
			case 1:
				customer = new Svip(id, name, 1);
				break;
			case 2:
				customer = new Hvip(id, name, 2);
				break;
			case 3:
				customer = new Ovip(id, name, 3);
				break;
			default:
				break;
			}
			
			//�������˿��Żݣ����浽������
			newSpace[this->c_CusNum + i] = customer;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->c_CusArray;
		//�����¿ռ��ָ��
		this->c_CusArray = newSpace;
		//�����µĹ˿�����
		this->c_CusNum = newSize;
		//�������ݵ��ļ�
		this->save();
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "���˿�" << endl;
		//�����ļ���Ϊ�յı�־
		this->c_FileIsEmpty = false;
	}
	else
	{
		cout << "��������" << endl;
	}
	//��������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

void Customer_system::save()
{
	ofstream ofs;
	ofs.open(CFILENAME, ios::out);//д�ļ�
	for (int i = 0; i < this->c_CusNum; i++)
	{
		ofs << this->c_CusArray[i]->c_Id << " "
			<< this->c_CusArray[i]->c_name << " "
			<< this->c_CusArray[i]->c_MenId << endl;
	}
}

void Customer_system::show_Cus()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->c_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ���ļ�" << endl;
	}
	else
	{
		for (int i = 0; i < c_CusNum; i++)
		{
			this->c_CusArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

int Customer_system::IsExist(int id)
{
	int index = -1;
	if (this->c_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->c_CusNum; i++)
		{
			if (this->c_CusArray[i]->c_Id == id)
			{
				//�ҵ��˿�
				index = i;
				break;
			}
		}
	}
	return index;
}

void Customer_system::Del_Cus()
{
	cout << "��������Ҫɾ���˿͵ı�ţ�" << endl;
	int id = 0;
	cin >> id;
	int index = IsExist(id);
	if (index != -1)//˵����ɾ���˿ʹ��ڣ�����ɾ����indexλ�õĹ˿�
	{
		for (int i = index; i < this->c_CusNum - 1; i++)
		{
			this->c_CusArray[i] = this->c_CusArray[i + 1];
		}
		cout << "ɾ���ɹ���" << endl;
		this->c_CusNum--;//����������ְ������
		this->save();	//���º󱣴浽�ļ�
	}
	else
	{
		cout << "ɾ��ʧ�ܣ�δ�ҵ��ù˿ͣ�" << endl;
	}
	system("pause");
	system("cls");
}

void Customer_system::Mod_Cus()
{
	cout << "��������Ҫ�޸Ĺ˿͵ı�ţ�" << endl;
	int id;
	cin >> id;
	int index = IsExist(id);
	if (index != -1)//˵�����޸ĵĹ˿ʹ���
	{
		int newId = 0;
		string newName = "";
		int dSelect = 0;
		cout << "�鵽��" << id << "�Ź˿ͣ��˿���Ϣ���£�" << endl;
		this->c_CusArray[index]->showInfo();
		delete this->c_CusArray[index];
		cout << "�������µĹ˿ͱ�ţ�" << endl;
		cin >> newId;
		cout << "�������µ�������" << endl;
		cin >> newName;
		cout << "�������µĻ�Ա�ȼ���" << endl;
		cout << "1.�����Ա" << endl;
		cout << "2.����Ա" << endl;
		cout << "3.��ͨ��Ա" << endl;
		cin >> dSelect;
		Customer* customer = NULL;
		switch (dSelect)
		{
		case 1:
			customer = new Svip(newId, newName, dSelect);
			break;
		case 2:
			customer = new Hvip(newId, newName, dSelect);
			break;
		case 3:
			customer = new Ovip(newId, newName, dSelect);
			break;
		default:
			break;
		}
		this->c_CusArray[index] = customer;//�������ݵ�������
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

void Customer_system::Find_Cus()
{
	if (this->c_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ" << endl;
		cout << "1.���˿ͱ�Ų���" << endl;
		cout << "2.���˿���������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)//����Ų���
		{
			int id;
			cout << "������Ҫ���ҵĹ˿ͱ��" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ����ù˿���Ϣ���£�" << endl;
				this->c_CusArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else if (select == 2)//����������
		{
			string name;
			cout << "������Ҫ���ҵĹ˿�����" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->c_CusNum; i++)
			{
				if (this->c_CusArray[i]->c_name == name)
				{
					cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
					this->c_CusArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else//��������
		{
			cout << "��������" << endl;
		}

	}
	system("pause");
	system("cls");
}

void Customer_system::Sort_Cus()
{
	if (this->c_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1.���˿ͱ������" << endl;
		cout << "2.���˿ͱ�Ž���" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->c_CusNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->c_CusNum; j++)
			{
				if (select == 1)//����
				{
					if (this->c_CusArray[minOrMax]->c_Id > this->c_CusArray[j]->c_Id)
					{
						minOrMax = j;
					}
				}
				else//����
				{
					if (this->c_CusArray[minOrMax]->c_Id < this->c_CusArray[j]->c_Id)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Customer* temp = this->c_CusArray[i];
				this->c_CusArray[i] = this->c_CusArray[minOrMax];
				this->c_CusArray[minOrMax] = temp;
			}
		}
		cout << "����ɹ����������Ϊ��" << endl;
		this->save();
		this->show_Cus();
	}
}

Customer_system::~Customer_system()
{
	if (this->c_CusArray != NULL)
	{
		delete[] this->c_CusArray;
		this->c_CusArray = NULL;
	}
}