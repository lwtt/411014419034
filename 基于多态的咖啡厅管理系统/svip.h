#pragma once
#include <iostream>
using namespace std;
#include "customer.h"

//����VIP��
class Svip :public Customer
{
public:
	Svip(int id, string name, int cId);
	virtual void showInfo();
	virtual string getMenGrade();

private:

};

