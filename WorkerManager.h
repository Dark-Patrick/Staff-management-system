#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"worker.h"
#include"employee.h"
#include"BOSS.h"
#include"manager.h"
#define FILENAME "database.txt"
using namespace std;
class WorkerManager {
	//职工人数
	int w_num;
	//int w_ptr;
public:
	bool fileisempty;

	//私有成员接口
	int get_w_num()const { return w_num; }
	void set_w_num(int a) { w_num+= a; }
	//int get_w_ptr() { return w_ptr; }
	//void set_w_ptr(int a) { w_ptr += a; }vector：可以有，但没必要

	vector<worker*>w_arry;//=vector<worker*>(w_ptr);
	WorkerManager() ;

	//关闭系统
	void SystemClose();

	//增加职工
	void w_Addnum(int x);

	//显示菜单
	void Showmenu();

	//保存数据
	void save();

	//统计文件中人数
	int get_empnum();

	//初始化员工
	void init_emp();

	//查找职工
	int  search_emp()const;

	//显示职工信息
	void  showinfo_all();

	//删除职工
	void  cal_emp(int a);

	//清空职工
	void clean_all();

	//修改职工信息
	void change_emp();

	//职工信息排序
	void sort_emp();
	
	
	
};