#include"employee.h"
#include<iomanip>
using namespace std;
employee::employee(int a, string b, int d) {
	id = a;
	name = b;
	bid = d;
}
void employee::showinfo() {
	cout << setiosflags(ios_base::left) << setw(10) << "职工信息：" << resetiosflags(ios_base::left)
		<< setw(5) << "ID：" << setiosflags(ios_base::left) << setw(10) << id << resetiosflags(ios_base::left)
		<< setw(5) << "姓名：" << setiosflags(ios_base::left) << setw(10) << name << resetiosflags(ios_base::left)
		<< setw(5) << "岗位：" << setiosflags(ios_base::left) << setw(10) << this->getdeptname() << endl;
}
string employee::getdeptname() {
	return (string)"普通员工";
}