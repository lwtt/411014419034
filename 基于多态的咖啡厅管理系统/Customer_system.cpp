#include "Customer_system.h"

Customer_system::Customer_system()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(CFILENAME, ios::in);//读文件
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		this->c_CusNum = 0;		//初始化记录人数
		this->c_CusArray = NULL;//初始化数组指针
		this->c_FileIsEmpty = true;//初始化文件为空
		ifs.close();
		return;
	}
	//2.文件存在 但文件为空
	//char ch;
	//ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空！" << endl;
		this->c_CusNum = 0;		//初始化记录人数
		this->c_CusArray = NULL;//初始化数组指针
		this->c_FileIsEmpty = true;//初始化文件为空
		ifs.close();
		return;
	}
	else//3.文件存在，且不为空
	{
		int num = this->get_CusNum();
		cout << "顾客人数为：" << num << endl;
		this->c_CusNum = num;
		//开辟空间
		this->c_CusArray = new Customer * [this->c_CusNum];
		//将文件中的数据，存到数组中
		this->init_Cus();
	}
}

void Customer_system::Show_Menu()
{
	cout << "************************************" << endl;
	cout << "******* 欢迎使用顾客管理系统 *******" << endl;
	cout << "********** 0.返回上个界面 **********" << endl;
	cout << "********** 1.增加顾客信息 **********" << endl;
	cout << "********** 2.显示顾客信息 **********" << endl;
	cout << "********** 3.删除顾客信息 **********" << endl;
	cout << "********** 4.修改顾客信息 **********" << endl;
	cout << "********** 5.查找顾客信息 **********" << endl;
	cout << "********** 6.按照编号排序 **********" << endl;
	cout << "************************************" << endl;
	cout << endl;
}

void Customer_system::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);		//退出程序
}


int Customer_system::get_CusNum()
{
	ifstream ifs;
	ifs.open(CFILENAME, ios::in);//打开文件  读
	int id;
	string name;
	int cId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> cId)
	{
		num++;//统计变量人数
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
	cout << "请输入添加顾客的数量：" << endl;
	int addNum = 0;//保存用户输入的数量
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->c_CusNum + addNum;//新空间的人数=原来空间的人数+新增的人数
		Customer** newSpace = new Customer * [newSize];//开辟新空间
		if (this->c_CusArray != NULL)
		{
			for (int i = 0; i < this->c_CusNum; i++)
			{
				newSpace[i] = this->c_CusArray[i];
			}
		}
		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;		//顾客编号
			string name;//顾客姓名
			int dSelsct;//顾客等级编号
			cout << "请输入第" << i + 1 << "个新顾客编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新顾客姓名" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个新顾客等级" << endl;
			cout << "请选择该顾客等级：" << endl;
			cout << "1.至尊VIP" << endl;
			cout << "2.尊贵VIP" << endl;
			cout << "3.普通VIP" << endl;
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
			
			//将创建顾客优惠，保存到数组中
			newSpace[this->c_CusNum + i] = customer;
		}
		//释放原有空间
		delete[] this->c_CusArray;
		//更新新空间的指向
		this->c_CusArray = newSpace;
		//更新新的顾客人数
		this->c_CusNum = newSize;
		//保存数据到文件
		this->save();
		//提示添加成功
		cout << "成功添加" << addNum << "名顾客" << endl;
		//更新文件不为空的标志
		this->c_FileIsEmpty = false;
	}
	else
	{
		cout << "输入有误" << endl;
	}
	//按任意键后，清屏回到上级目录
	system("pause");
	system("cls");
}

void Customer_system::save()
{
	ofstream ofs;
	ofs.open(CFILENAME, ios::out);//写文件
	for (int i = 0; i < this->c_CusNum; i++)
	{
		ofs << this->c_CusArray[i]->c_Id << " "
			<< this->c_CusArray[i]->c_name << " "
			<< this->c_CusArray[i]->c_MenId << endl;
	}
}

void Customer_system::show_Cus()
{
	//判断文件是否为空
	if (this->c_FileIsEmpty)
	{
		cout << "文件不存在或为空文件" << endl;
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
		cout << "文件不存在或文件为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->c_CusNum; i++)
		{
			if (this->c_CusArray[i]->c_Id == id)
			{
				//找到顾客
				index = i;
				break;
			}
		}
	}
	return index;
}

void Customer_system::Del_Cus()
{
	cout << "请输入想要删除顾客的编号：" << endl;
	int id = 0;
	cin >> id;
	int index = IsExist(id);
	if (index != -1)//说明将删除顾客存在，并且删除掉index位置的顾客
	{
		for (int i = index; i < this->c_CusNum - 1; i++)
		{
			this->c_CusArray[i] = this->c_CusArray[i + 1];
		}
		cout << "删除成功！" << endl;
		this->c_CusNum--;//更新数组中职工个数
		this->save();	//更新后保存到文件
	}
	else
	{
		cout << "删除失败，未找到该顾客！" << endl;
	}
	system("pause");
	system("cls");
}

void Customer_system::Mod_Cus()
{
	cout << "请输入想要修改顾客的编号：" << endl;
	int id;
	cin >> id;
	int index = IsExist(id);
	if (index != -1)//说明将修改的顾客存在
	{
		int newId = 0;
		string newName = "";
		int dSelect = 0;
		cout << "查到：" << id << "号顾客，顾客信息如下：" << endl;
		this->c_CusArray[index]->showInfo();
		delete this->c_CusArray[index];
		cout << "请输入新的顾客编号：" << endl;
		cin >> newId;
		cout << "请输入新的姓名：" << endl;
		cin >> newName;
		cout << "请输入新的会员等级：" << endl;
		cout << "1.至尊会员" << endl;
		cout << "2.尊贵会员" << endl;
		cout << "3.普通会员" << endl;
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
		this->c_CusArray[index] = customer;//更新数据到数组中
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

void Customer_system::Find_Cus()
{
	if (this->c_FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式" << endl;
		cout << "1.按顾客编号查找" << endl;
		cout << "2.按顾客姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)//按编号查找
		{
			int id;
			cout << "请输入要查找的顾客编号" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功！该顾客信息如下：" << endl;
				this->c_CusArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else if (select == 2)//按姓名查找
		{
			string name;
			cout << "请输入要查找的顾客姓名" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->c_CusNum; i++)
			{
				if (this->c_CusArray[i]->c_name == name)
				{
					cout << "查找成功！该职工信息如下：" << endl;
					this->c_CusArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else//输入有误
		{
			cout << "输入有误" << endl;
		}

	}
	system("pause");
	system("cls");
}

void Customer_system::Sort_Cus()
{
	if (this->c_FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1.按顾客编号升序" << endl;
		cout << "2.按顾客编号降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->c_CusNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->c_CusNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->c_CusArray[minOrMax]->c_Id > this->c_CusArray[j]->c_Id)
					{
						minOrMax = j;
					}
				}
				else//降序
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
		cout << "排序成功！排序后结果为：" << endl;
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