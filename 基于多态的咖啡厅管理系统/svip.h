#pragma once
#include <iostream>
using namespace std;
#include "customer.h"

//ÖÁ×ğVIPÀà
class Svip :public Customer
{
public:
	Svip(int id, string name, int cId);
	virtual void showInfo();
	virtual string getMenGrade();

private:

};

