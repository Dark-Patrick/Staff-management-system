#pragma once
#include<iostream>
#include<string>
using namespace std;
class worker {
public:
	int id;
	string name;
	int bid;
	//显示职工信息
	virtual void showinfo() = 0;
	//显示部门信息
	virtual string getdeptname() = 0;
};

