#include "ovip.h"

Ovip::Ovip(int id, string name, int cId)
{
	this->c_Id = id;
	this->c_name = name;
	this->c_MenId = cId;
}

void Ovip::showInfo()
{
	cout << "顾客编号：" << this->c_Id
		<< "\t顾客姓名：" << this->c_name
		<< "\t等级：" << this->getMenGrade()
		<< "\t九五折优惠" << endl;
}

string Ovip::getMenGrade()
{
	return string("普通VIP");
}

