#pragma once
#include <iostream>				//��������������ļ�
using namespace std;			//ʹ�ñ�׼�����ռ�
#include"customer.h"
#include"svip.h"
#include"hvip.h"
#include"ovip.h"
#include <fstream>
#define CFILENAME "Customer_File.txt"
class Customer_system
{
public:
	Customer_system();
	void Show_Menu();			//��ʾ�˵�
	void ExitSystem();			//�˳�ϵͳ
	int c_CusNum;				//��¼�˿�����
	bool c_FileIsEmpty;			//��¼�ļ��Ƿ�Ϊ�� ��־
	Customer** c_CusArray;		//�˿�����ָ��
	int get_CusNum();			//ͳ���ļ��е�����
	void init_Cus();			//��ʼ���˿�
	void Add_Cus();				//��ӹ˿�
	void save();				//�����ļ�
	void show_Cus();			//��ʾ�˿�
	int IsExist(int id);		//�˿��Ƿ����
	void Del_Cus();				//ɾ���˿�
	void Mod_Cus();				//�޸Ĺ˿�
	void Find_Cus();			//���ҹ˿�
	void Sort_Cus();			//����
	~Customer_system();

private:

};

