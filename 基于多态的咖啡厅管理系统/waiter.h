#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Waiter :public Worker
{
public:
	Waiter(int id, string name, int dId);//构造函数
	virtual void showInfo();			 //显示个人信息
	virtual string getDeptName();		 //获取岗位名称
private:

};

