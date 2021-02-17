#include"manager.h"
#include<iomanip>
using namespace std;
manager::manager(int a, string b, int d) {
	id = a;
	name = b;
	bid = d;
}
void manager::showinfo() {
	cout << setiosflags(ios_base::left) << setw(10) << "职工信息："<<resetiosflags(ios_base::left)
		<<setw(5)<< "ID：" << setiosflags(ios_base::left) << setw(10)<< id<< resetiosflags(ios_base::left)
		<< setw(5) << "姓名：" << setiosflags(ios_base::left) << setw(10) << name << resetiosflags(ios_base::left)
		<< setw(5) << "岗位：" << setiosflags(ios_base::left) << setw(10)<< this->getdeptname() << endl;


}
string manager::getdeptname() {
	return (string)"部门经理";
}