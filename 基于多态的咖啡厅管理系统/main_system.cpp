#include "main_system.h"

main_system::main_system()
{
}




void main_system::Show_Main_Menu()
{
	cout << "************************************" << endl;
	cout << "****** ��ӭʹ�ÿ���������ϵͳ ******" << endl;
	cout << "********** 0.�˳�������� **********" << endl;
	cout << "********** 1.����ְ��ϵͳ **********" << endl;
	cout << "********** 2.����˿�ϵͳ **********" << endl;
	cout << endl;
}

void main_system::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);		//�˳�����
}

void main_system::into_Worker_system()
{
	system("cls");				//����
	int choice = 0;
	while (true)
	{
		int flag = 0;
		Worker_system ws;
		ws.Show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;				//�����û���ѡ��
		switch (choice)
		{
		case 0:
			//system("pause");
			system("cls");			//���������±�־
			flag = 1;
			break;
		case 1:
			ws.Add_Emp();			//���ְ��
			break;
		case 2:
			ws.show_Emp();			//��ʾְ��
			break;
		case 3:
			ws.Del_Emp();			//ɾ��ְ��
			break;
		case 4:
			ws.Mod_Emp();			//�޸�ְ��
			break;
		case 5:
			ws.Sort_Emp();			//����
			break;
		default:
			system("cls");			//����
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
	system("cls");				//����
	int choice = 0;
	while (true)
	{
		int flag = 0;
		Customer_system cs;
		cs.Show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;				//�����û���ѡ��
		switch (choice)
		{
		case 0:
			system("cls");			//����
			flag = 1;
			break;
		case 1:
			cs.Add_Cus();			//��ӹ˿�
			break;
		case 2:
			cs.show_Cus();			//��ʾ�˿�
			break;
		case 3:
			cs.Del_Cus();			//ɾ���˿�
			break;
		case 4:
			cs.Mod_Cus();			//�޸Ĺ˿�
			break;
		case 5:
			cs.Find_Cus();			//���ҹ˿�
			break;
		case 6:
			cs.Sort_Cus();			//����
		default:
			system("cls");			//����
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