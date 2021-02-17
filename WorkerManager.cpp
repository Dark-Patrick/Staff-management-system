#include"WorkerManager.h"
#include<iomanip>
#include <cstdlib>
using namespace std;

WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in|ios_base::binary);//读文件
	//文件未被创立的case
	if (!ifs.is_open()) {
		cout << "文件未被创建!已重新创建" << endl;
		w_num = 0;
		this->fileisempty = true;
		ifs.close();
		return ;
	}
	//文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {//eof:the end of file
		cout << "文件为空！" << endl;
		w_num = 0;
		this->fileisempty = true;
		ifs.close();
		return;
	}

	//文件存在 含有数据记录
	cout << "已有职工人数为：" << this->get_empnum() << endl;
	this->set_w_num(this->get_empnum());
	init_emp();

	 
};
void WorkerManager::Showmenu() {
	cout << "**********************************************************" << '\n'
		<< "******************欢迎使用职工管理系统！******************" << '\n'
		<< "********************0.退出管理程序************************" << '\n'
		<< "********************1.增加职工信息************************" << '\n'
		<< "********************2.显示职工信息************************" << '\n'
		<< "********************3.删除离职职工************************" << '\n'
		<< "********************4.修改职工信息************************" << '\n'
		<< "********************5.查找职工信息************************" << '\n'
		<< "********************6.按照编号排序************************" << '\n'
		<< "********************7.清空所有文档************************" << '\n'
		<< "**********************************************************" << '\n'
		<< endl;
	cout <<'\n'<< "请输入您的选择：" << endl;
}
void WorkerManager:: SystemClose() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager:: w_Addnum(int x) {
	if (x > 0) {
		this->set_w_num(x);
		//this->set_w_ptr(x);
		this->fileisempty = false;

		for (int i = 0; i < x; i++) {
			int a;//int32的内存溢出问题，懒得改了=_=（用string解决）
			string n;
			cout << "请依次输入职工的编号和姓名" << endl;
			cin >> a >> n;
			cout << "请选择职工的岗位：" << '\n'
				<< "普通职工-1" << '\n'
				<< "部门经理-2" << '\n'
				<< "执行董事-3" << endl;
			int c;
			cin >> c;
			worker* worker = NULL;
			switch (c)
			{
			case 1:
				 worker = new employee (a, n, 1);
				w_arry.push_back(worker);
				break;
			case 2:
		        worker = new  manager(a, n, 2);
				w_arry.push_back(worker);
				break;
			case 3:
				worker = new  BOSS(a, n, 3);
				w_arry.push_back(worker);
				break;
			default:
				cout << "输入错误！" << endl;
				break;
			}

			cout << "添加成功！" << endl;
			system("pause");
			
		}
		save();
		//this->set_w_num (x);
		//this->set_w_ptr(x);
        system("cls");
	}
	else {
		cout << "Out of range!" << endl;
		system("pause");
		system("cls");

	}
}
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out|ios_base::binary);
	for (int i = 0; i < w_num; i++) {
		
			ofs << w_arry[i]->id << " "
				<< w_arry[i]->name << " "
				<< w_arry[i]->bid << endl;
		
	}
	ofs.close();

}
int WorkerManager::get_empnum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int bid;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> bid) {//空格的分隔符作用
		//记录人数
		num++;
	}
	ifs.close();
	return num;
}
void WorkerManager::init_emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in|ios_base::binary);

	int id;
	string name;
	int bid;

	while (ifs >> id && ifs >> name && ifs >> bid) {
		worker* worker = NULL;
		switch (bid) {
		case 1:
			worker = new employee(id, name, bid);
			break;
		case 2:
			worker = new manager(id, name, bid);
			break;
		case 3:
			worker = new BOSS(id, name, bid);
			break;
		default:
			cout << "出现未知错误" << endl;
		}
		w_arry.push_back(worker);

	}
	ifs.close();
}
int  WorkerManager::search_emp()const{
	int i = 0;
	if (fileisempty == true)
		cout << "暂无职工记录！" << endl;
	else {
		
		int a,b=0;
		cout << "输入查找职工的id" << endl;
		cin >> a;
		for (i = 0; i < w_num; i++) {
			if (w_arry[i]->id == a) {
				w_arry[i]->showinfo();
				b = 1;
				break;
			}
		}
		if (b == 0) {
			cout << "查无此人" << endl;
			system("pause");
			system("cls");
			return -1;
		}
	}
	system("pause");
	system("cls");
	return i;
}
void  WorkerManager::showinfo_all() {
	
	if (fileisempty == true)
		cout << "暂无职工记录！" << endl;
	else
		for (int i = 0; i < w_num; i++) {
			w_arry[i]->showinfo();
			cout << endl;
		}

	system("pause");
	system("cls");

}
void WorkerManager::cal_emp(int a) {
	if (a == -1) {
		cout << "无此员工信息" << endl;
		system("pause");
		system("cls");
	}
	else {
		//cout << w_arry.size();
		vector<worker*>::iterator ite;
		for (ite = w_arry.begin(); ite != w_arry.end(); ++ite) {
			if (*ite == w_arry[a]) {
				ite = w_arry.erase(ite);
				break;
			}
		}
		w_num--;
		cout << "已删除职工" << endl;
		save();
		//cout << w_arry.size();

		system("pause");
		system("cls");
	}

}
void WorkerManager::clean_all() {
	w_arry.clear();
	w_num = 0;
	fileisempty = true;
	cout << "已清理全部职工" << endl;
	system("pause");
	system("cls");
}
void WorkerManager::change_emp() {
	int i = 0;
	if (fileisempty == true)
		cout << "暂无职工记录！" << endl;
	else {

		int a, b = 0;
		cout << "输入需修改的职工id" << endl;
		cin >> a;
		for (i = 0; i < w_num; i++) {
			if (w_arry[i]->id == a) {
				b = 1;
				break;
			}
		}
		if (b == 0) {
			cout << "查无此人" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	int id, bid;
	string name;
	cout << "请依次输入修改后的职工编号和姓名" << endl;
	cin >> id >> name;
	
	cout << "请选择职工的岗位：" << '\n'
		<< "普通职工-1" << '\n'
		<< "部门经理-2" << '\n'
		<< "执行董事-3" << endl;
	cin >> bid;
	switch (bid)
	{
	case 1:
		w_arry[i]=new employee(id, name, bid);
		break;
	case 2:
		w_arry[i] = new manager(id, name, bid);
		break;
	case 3:
		w_arry[i] = new BOSS(id, name, bid);
		break;
	default:
		cout << "输入错误职工信息" << endl;
		break;
	}
	save();
	system("pause");
	system("cls");
}
void WorkerManager::sort_emp() {
	if (fileisempty == true) {
		cout << "暂无职工记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请选择排序方式：" << '\n'
		<< "1.按职工编号升序排列" << '\n'
		<< "2.按职工编号降序排列" << endl;
	int select;
	cin >> select;
	for (int i = 0; i < w_num; i++) {
		int max = i;
		for (int j = i + 1; j < w_num; j++) {
			if (select == 1) {
				if (w_arry[max]->id > w_arry[j]->id)
					max = j;
			}
			else {
				if (w_arry[max]->id < w_arry[j]->id)
					max = j;
			}
		}
		if (max != i) {
			worker* temp = w_arry[i];
			w_arry[i] = w_arry[max];
			w_arry[max] = temp;
		}
	}
	cout << "排序成功！" << endl;
	system("pause");
	system("cls");
	return;
}