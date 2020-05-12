#pragma once
#include <iostream>				//包含输入输出流文件
using namespace std;			//使用标准命名空间
#include "worker.h"
#include "waiter.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#define FILENAME "Worker_file.txt"
class Worker_system
{
public:
	Worker_system();
	void Show_Menu();			//显示菜单
	int get_EmpNum();			//统计文件中的人数
	void init_Emp();			//初始化员工
	int m_EmpNum;				//记录职工人数
	Worker** m_EmpArray;		//职工数组指针
	void save();				//保存文件
	bool m_FileIsEmpty;			//判断文件是否为空 标志
	void Add_Emp();				//添加职工
	void show_Emp();			//显示职工信息
	int IsExist(int id);		//职工是否存在
	void Del_Emp();				//删除职工
	void Mod_Emp();				//修改职工
	void Sort_Emp();			//排序 
	~Worker_system();

private:

};

