#pragma once
#include <iostream>
using namespace std;
#include <string>

class Customer
{
public:
	virtual void showInfo() = 0;		//��ʾ������Ϣ
	virtual string getMenGrade() = 0;		//��ȡ��Ա�ȼ�
	int c_Id;							//�˿ͱ��
	string c_name;						//�˿�����
	int c_MenId;						//��Ա�ȼ����
private:

};

