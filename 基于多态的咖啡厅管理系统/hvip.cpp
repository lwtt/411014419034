#include "hvip.h"


Hvip::Hvip(int id, string name, int cId)
{
	this->c_Id = id;
	this->c_name = name;
	this->c_MenId = cId;
}

void Hvip::showInfo()
{
	cout << "�˿ͱ�ţ�" << this->c_Id
		<< "\t�˿�������" << this->c_name
		<< "\t�ȼ���" << this->getMenGrade()
		<< "\t�����Ż�" << endl;
}

string Hvip::getMenGrade()
{
	return string("���VIP");
}
