#pragma once
#include <iostream>				//��������������ļ�
using namespace std;			//ʹ�ñ�׼�����ռ�
#include "worker.h"
#include "waiter.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#define FILENAME "Worker_file.txt"
class Worker_system
{
public:
	Worker_system();
	void Show_Menu();			//��ʾ�˵�
	int get_EmpNum();			//ͳ���ļ��е�����
	void init_Emp();			//��ʼ��Ա��
	int m_EmpNum;				//��¼ְ������
	Worker** m_EmpArray;		//ְ������ָ��
	void save();				//�����ļ�
	bool m_FileIsEmpty;			//�ж��ļ��Ƿ�Ϊ�� ��־
	void Add_Emp();				//���ְ��
	void show_Emp();			//��ʾְ����Ϣ
	int IsExist(int id);		//ְ���Ƿ����
	void Del_Emp();				//ɾ��ְ��
	void Mod_Emp();				//�޸�ְ��
	void Sort_Emp();			//���� 
	~Worker_system();

private:

};

