#pragma once
#include <iostream>				//��������������ļ�
using namespace std;			//ʹ�ñ�׼�����ռ�
#include "Worker_system.h"
#include "Customer_system.h"
class main_system
{
public:
	main_system();
	void Show_Main_Menu();		//��ʾ���˵�
	void ExitSystem();			//�˳�ϵͳ 
	void into_Worker_system();	//����ְ��ϵͳ
	void into_Customer_system();//����˿�ϵͳ
	~main_system();

private:

};

