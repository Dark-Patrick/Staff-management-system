#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;
class manager :public worker {
public:
	manager(int a, string b, int d);

	virtual void showinfo();

	virtual string getdeptname();
};