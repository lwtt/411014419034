#include "svip.h"

Svip::Svip(int id, string name, int cId)
{
	this->c_Id = id;
	this->c_name = name;
	this->c_MenId = cId;
}

void Svip::showInfo()
{
	cout << "顾客编号：" << this->c_Id
		<< "\t顾客姓名：" << this->c_name
		<< "\t等级：" << this->getMenGrade()
		<< "\t八折优惠" << endl;
}

string Svip::getMenGrade()
{
	return string("至尊VIP");
}
