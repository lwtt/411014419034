#include <iostream>
using namespace std;
#include "main_system.h"
#include "Worker_system.h"
int main()
{
	main_system ms;
	int choice = 0;		//用来存储用户的选项
	while (true)
	{
		ms.Show_Main_Menu();
		cout << "请输入你的选择" << endl;
		cin >> choice;	//接受用户的选择
		switch (choice)
		{
		case 0:
			ms.ExitSystem();			//退出系统
			break;
		case 1:
			ms.into_Worker_system();	//进入职工系统
			break;
		case 2:
			ms.into_Customer_system();	//进入顾客系统
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}