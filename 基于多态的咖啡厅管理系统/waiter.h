#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Waiter :public Worker
{
public:
	Waiter(int id, string name, int dId);//���캯��
	virtual void showInfo();			 //��ʾ������Ϣ
	virtual string getDeptName();		 //��ȡ��λ����
private:

};

