#include"BOSS.h"
#include<iomanip>
using namespace std;

BOSS::BOSS(int a, string b, int d) {
	id = a;
	name = b;
	bid = d;
}
void BOSS::showinfo() {
	cout << setiosflags(ios_base::left) << setw(10) << "ְ����Ϣ��" << resetiosflags(ios_base::left)
		<< setw(5) << "ID��" << setiosflags(ios_base::left) << setw(10) << id << resetiosflags(ios_base::left)
		<< setw(5) << "������" << setiosflags(ios_base::left) << setw(10) << name << resetiosflags(ios_base::left)
		<< setw(5) << "��λ��" << setiosflags(ios_base::left) << setw(10) << this->getdeptname() << endl;

}
string BOSS::getdeptname() {
	return (string)"ִ�ж���";
}