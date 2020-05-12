#pragma once
#include <iostream>
using namespace std;
#include <string>


class Worker
{
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;
	//职工编号
	int m_Id;
	//职工姓名
	string m_name;
	//部门编号
	int m_DeptId;
	//Worker();
	//~Worker();

private:

};