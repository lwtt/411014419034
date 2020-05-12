#include "hvip.h"


Hvip::Hvip(int id, string name, int cId)
{
	this->c_Id = id;
	this->c_name = name;
	this->c_MenId = cId;
}

void Hvip::showInfo()
{
	cout << "¹Ë¿Í±àºÅ£º" << this->c_Id
		<< "\t¹Ë¿ÍÐÕÃû£º" << this->c_name
		<< "\tµÈ¼¶£º" << this->getMenGrade()
		<< "\t¾ÅÕÛÓÅ»Ý" << endl;
}

string Hvip::getMenGrade()
{
	return string("×ð¹óVIP");
}
