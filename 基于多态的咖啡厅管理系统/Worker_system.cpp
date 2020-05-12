#include "Worker_system.h"


Worker_system::Worker_system()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	if (!ifs.is_open())
	{
		cout << "职工文件不存在" << endl;
		//初始化属性
		this->m_EmpNum = 0;		//初始化记录人数
		this->m_EmpArray = NULL;//初始化数组指针
		this->m_FileIsEmpty = true;//初始化文件为空
		ifs.close();
		return;
	}
	//2.文件存在 但文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "职工文件为空！" << endl;
		this->m_EmpNum = 0;		//初始化记录人数
		this->m_EmpArray = NULL;//初始化数组指针
		this->m_FileIsEmpty = true;//初始化文件为空
		ifs.close();
		return;
	}
	else//3.文件存在，且不为空
	{
		int num = this->get_EmpNum();
		cout << "职工人数为：" << num << endl;
		this->m_EmpNum = num;
		//开辟空间
		this->m_EmpArray = new Worker * [this->m_EmpNum];
		//将文件中的数据，存到数组中
		this->init_Emp();
	}
}

void Worker_system::Show_Menu()
{
	cout << "************************************" << endl;
	cout << "******* 欢迎使用职工管理系统 *******" << endl;
	cout << "********** 0.返回上个界面 **********" << endl;
	cout << "********** 1.增加职工信息 **********" << endl;
	cout << "********** 2.显示职工信息 **********" << endl;
	cout << "********** 3.删除离职职工 **********" << endl;
	cout << "********** 4.修改职工信息 **********" << endl;
	cout << "********** 5.按照编号排序 **********" << endl;
	cout << "************************************" << endl;
	cout << endl;
}

int Worker_system::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件  读
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;//统计变量人数
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
	ofs.open(FILENAME, ios::out);//写文件
	//将每个人数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	//关闭文件
	ofs.close();
}

void Worker_system::Add_Emp()
{
	cout << "请输入添加职工的数量：" << endl;
	int addNum = 0;//保存用户输入的数量
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;//新空间的人数=原来空间的人数+新增的人数
		Worker** newSpace = new Worker * [newSize];//开辟新空间
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;		//职工编号
			string name;//职工姓名
			int dSelsct;//部门选择
			cout << "请输入第" << i + 1 << "个新职工编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个新职工岗位" << endl;
			cout << "请选择该职工岗位：" << endl;
			cout << "1.服务员" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
			//将创建职工职责，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;
		//更新新空间的指向
		this->m_EmpArray = newSpace;
		//更新新的职工人数
		this->m_EmpNum = newSize;
		//保存数据到文件
		this->save();
		//提示添加成功
		cout << "成功添加" << addNum << "名员工" << endl;
		//更新文件不为空的标志
		this->m_FileIsEmpty = false;
	}
	else
	{
		cout << "输入有误" << endl;
	}
	//按任意键后，清屏回到上级目录
	system("pause");
	system("cls");
}

void Worker_system::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "职工文件不存在或为空文件" << endl;
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
		cout << "职工文件不存在或文件为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]->m_Id == id)
			{
				//找到职工
				index = i;
				break;
			}
		}
	}
	return index;
}

void Worker_system::Del_Emp()
{
	cout << "请输入想要删除职工的编号：" << endl;
	int id = 0;
	cin >> id;
	int index = IsExist(id);
	if (index != -1)//说明将删除员工存在，并且删除掉index位置的员工
	{
		for (int i = index; i < this->m_EmpNum - 1; i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		cout << "删除成功！" << endl;
		this->m_EmpNum--;//更新数组中职工个数
		this->save();	//更新后保存到文件
	}
	else
	{
		cout << "删除失败，未找到该职工！" << endl;
	}
	system("pause");
	system("cls");
}

void Worker_system::Mod_Emp()
{
	cout << "请输入想要修改职工的编号：" << endl;
	int id;
	cin >> id;
	int index = IsExist(id);
	if (index != -1)//说明将修改的员工存在
	{
		int newId = 0;
		string newName = "";
		int dSelect = 0;
		cout << "查到：" << id << "号职工，职工信息如下：" << endl;
		this->m_EmpArray[index]->showInfo();
		delete this->m_EmpArray[index];
		cout << "请输入新的职工号：" << endl;
		cin >> newId;
		cout << "请输入新的姓名：" << endl;
		cin >> newName;
		cout << "请输入新的岗位：" << endl;
		cout << "1.服务员" << endl;
		cout << "2.经理" << endl;
		cout << "3.老板" << endl;
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
		this->m_EmpArray[index] = worker;//更新数据到数组中
		this->save();					//保存到文件中
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "修改失败，查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

void Worker_system::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1.按职工编号升序" << endl;
		cout << "2.按职工编号降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else//降序
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
		cout << "排序成功！排序后结果为：" << endl;
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