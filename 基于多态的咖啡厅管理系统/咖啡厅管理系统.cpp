#include <iostream>
using namespace std;
#include "main_system.h"
#include "Worker_system.h"
int main()
{
	main_system ms;
	int choice = 0;		//�����洢�û���ѡ��
	while (true)
	{
		ms.Show_Main_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;	//�����û���ѡ��
		switch (choice)
		{
		case 0:
			ms.ExitSystem();			//�˳�ϵͳ
			break;
		case 1:
			ms.into_Worker_system();	//����ְ��ϵͳ
			break;
		case 2:
			ms.into_Customer_system();	//����˿�ϵͳ
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}