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
	//ְ������
	int w_num;
	//int w_ptr;
public:
	bool fileisempty;

	//˽�г�Ա�ӿ�
	int get_w_num()const { return w_num; }
	void set_w_num(int a) { w_num+= a; }
	//int get_w_ptr() { return w_ptr; }
	//void set_w_ptr(int a) { w_ptr += a; }vector�������У���û��Ҫ

	vector<worker*>w_arry;//=vector<worker*>(w_ptr);
	WorkerManager() ;

	//�ر�ϵͳ
	void SystemClose();

	//����ְ��
	void w_Addnum(int x);

	//��ʾ�˵�
	void Showmenu();

	//��������
	void save();

	//ͳ���ļ�������
	int get_empnum();

	//��ʼ��Ա��
	void init_emp();

	//����ְ��
	int  search_emp()const;

	//��ʾְ����Ϣ
	void  showinfo_all();

	//ɾ��ְ��
	void  cal_emp(int a);

	//���ְ��
	void clean_all();

	//�޸�ְ����Ϣ
	void change_emp();

	//ְ����Ϣ����
	void sort_emp();
	
	
	
};