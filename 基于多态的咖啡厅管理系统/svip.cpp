#include "svip.h"

Svip::Svip(int id, string name, int cId)
{
	this->c_Id = id;
	this->c_name = name;
	this->c_MenId = cId;
}

void Svip::showInfo()
{
	cout << "�˿ͱ�ţ�" << this->c_Id
		<< "\t�˿�������" << this->c_name
		<< "\t�ȼ���" << this->getMenGrade()
		<< "\t�����Ż�" << endl;
}

string Svip::getMenGrade()
{
	return string("����VIP");
}
