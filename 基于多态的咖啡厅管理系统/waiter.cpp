#include "waiter.h"

Waiter::Waiter(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptId = dId;
}

void Waiter::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ�𣺷���˿�" << endl;
}

string Waiter::getDeptName()
{
	return string("����Ա");
}
