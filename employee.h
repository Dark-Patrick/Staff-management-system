#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;
class employee :public worker{
public:
	employee(int a, string b, int d);

	virtual void showinfo() ;

	virtual string getdeptname() ;
};
