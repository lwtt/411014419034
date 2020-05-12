#pragma once
#include <iostream>
using namespace std;
#include "customer.h"

//ÖÁ×ğVIPÀà
class Hvip :public Customer
{
public:
	Hvip(int id, string name, int cId);
	virtual void showInfo();
	virtual string getMenGrade();

private:

};
