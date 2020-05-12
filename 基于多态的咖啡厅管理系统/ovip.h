#pragma once
#include <iostream>
using namespace std;
#include "customer.h"

//ÖÁ×ğVIPÀà
class Ovip :public Customer
{
public:
	Ovip(int id, string name, int cId);
	virtual void showInfo();
	virtual string getMenGrade();

private:

};