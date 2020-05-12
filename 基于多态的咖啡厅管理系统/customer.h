#pragma once
#include <iostream>
using namespace std;
#include <string>

class Customer
{
public:
	virtual void showInfo() = 0;		//显示个人信息
	virtual string getMenGrade() = 0;		//获取会员等级
	int c_Id;							//顾客编号
	string c_name;						//顾客姓名
	int c_MenId;						//会员等级编号
private:

};

