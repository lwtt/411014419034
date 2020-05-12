#pragma once
#include <iostream>				//包含输入输出流文件
using namespace std;			//使用标准命名空间
#include"customer.h"
#include"svip.h"
#include"hvip.h"
#include"ovip.h"
#include <fstream>
#define CFILENAME "Customer_File.txt"
class Customer_system
{
public:
	Customer_system();
	void Show_Menu();			//显示菜单
	void ExitSystem();			//退出系统
	int c_CusNum;				//记录顾客人数
	bool c_FileIsEmpty;			//记录文件是否为空 标志
	Customer** c_CusArray;		//顾客数组指针
	int get_CusNum();			//统计文件中的人数
	void init_Cus();			//初始化顾客
	void Add_Cus();				//添加顾客
	void save();				//保存文件
	void show_Cus();			//显示顾客
	int IsExist(int id);		//顾客是否存在
	void Del_Cus();				//删除顾客
	void Mod_Cus();				//修改顾客
	void Find_Cus();			//查找顾客
	void Sort_Cus();			//排序
	~Customer_system();

private:

};

