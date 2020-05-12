#include "main_system.h"

main_system::main_system()
{
}




void main_system::Show_Main_Menu()
{
	cout << "************************************" << endl;
	cout << "****** 欢迎使用咖啡厅管理系统 ******" << endl;
	cout << "********** 0.退出管理程序 **********" << endl;
	cout << "********** 1.进入职工系统 **********" << endl;
	cout << "********** 2.进入顾客系统 **********" << endl;
	cout << endl;
}

void main_system::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);		//退出程序
}

void main_system::into_Worker_system()
{
	system("cls");				//清屏
	int choice = 0;
	while (true)
	{
		int flag = 0;
		Worker_system ws;
		ws.Show_Menu();
		cout << "请输入你的选择" << endl;
		cin >> choice;				//接受用户的选择
		switch (choice)
		{
		case 0:
			//system("pause");
			system("cls");			//清屏，更新标志
			flag = 1;
			break;
		case 1:
			ws.Add_Emp();			//添加职工
			break;
		case 2:
			ws.show_Emp();			//显示职工
			break;
		case 3:
			ws.Del_Emp();			//删除职工
			break;
		case 4:
			ws.Mod_Emp();			//修改职工
			break;
		case 5:
			ws.Sort_Emp();			//排序
			break;
		default:
			system("cls");			//清屏
			break;
		}
		if (flag==1)
		{
			break;
		}
	}
	
}

void main_system::into_Customer_system()
{
	system("cls");				//清屏
	int choice = 0;
	while (true)
	{
		int flag = 0;
		Customer_system cs;
		cs.Show_Menu();
		cout << "请输入你的选择" << endl;
		cin >> choice;				//接受用户的选择
		switch (choice)
		{
		case 0:
			system("cls");			//清屏
			flag = 1;
			break;
		case 1:
			cs.Add_Cus();			//添加顾客
			break;
		case 2:
			cs.show_Cus();			//显示顾客
			break;
		case 3:
			cs.Del_Cus();			//删除顾客
			break;
		case 4:
			cs.Mod_Cus();			//修改顾客
			break;
		case 5:
			cs.Find_Cus();			//查找顾客
			break;
		case 6:
			cs.Sort_Cus();			//排序
		default:
			system("cls");			//清屏
			break;
		}
		if (flag == 1)
		{
			break;
		}
	}
}

main_system::~main_system()
{
}