#pragma once
#include <iostream>				//包含输入输出流文件
using namespace std;			//使用标准命名空间
#include "Worker_system.h"
#include "Customer_system.h"
class main_system
{
public:
	main_system();
	void Show_Main_Menu();		//显示主菜单
	void ExitSystem();			//退出系统 
	void into_Worker_system();	//进入职工系统
	void into_Customer_system();//进入顾客系统
	~main_system();

private:

};

