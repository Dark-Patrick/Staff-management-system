#pragma once
#include<iostream>
#include<string>
using namespace std;
class worker {
public:
	int id;
	string name;
	int bid;
	//��ʾְ����Ϣ
	virtual void showinfo() = 0;
	//��ʾ������Ϣ
	virtual string getdeptname() = 0;
};

