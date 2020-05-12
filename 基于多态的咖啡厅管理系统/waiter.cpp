#include "waiter.h"

Waiter::Waiter(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptId = dId;
}

void Waiter::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：服务顾客" << endl;
}

string Waiter::getDeptName()
{
	return string("服务员");
}
