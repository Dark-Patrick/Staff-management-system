#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;
class BOSS :public worker {
public:
	BOSS(int a, string b, int d);

	virtual void showinfo();

	virtual string getdeptname();
};