#include"WorkerManager.h"
#include<iomanip>
#include <cstdlib>
using namespace std;

WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in|ios_base::binary);//���ļ�
	//�ļ�δ��������case
	if (!ifs.is_open()) {
		cout << "�ļ�δ������!�����´���" << endl;
		w_num = 0;
		this->fileisempty = true;
		ifs.close();
		return ;
	}
	//�ļ����� ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {//eof:the end of file
		cout << "�ļ�Ϊ�գ�" << endl;
		w_num = 0;
		this->fileisempty = true;
		ifs.close();
		return;
	}

	//�ļ����� �������ݼ�¼
	cout << "����ְ������Ϊ��" << this->get_empnum() << endl;
	this->set_w_num(this->get_empnum());
	init_emp();

	 
};
void WorkerManager::Showmenu() {
	cout << "**********************************************************" << '\n'
		<< "******************��ӭʹ��ְ������ϵͳ��******************" << '\n'
		<< "********************0.�˳��������************************" << '\n'
		<< "********************1.����ְ����Ϣ************************" << '\n'
		<< "********************2.��ʾְ����Ϣ************************" << '\n'
		<< "********************3.ɾ����ְְ��************************" << '\n'
		<< "********************4.�޸�ְ����Ϣ************************" << '\n'
		<< "********************5.����ְ����Ϣ************************" << '\n'
		<< "********************6.���ձ������************************" << '\n'
		<< "********************7.��������ĵ�************************" << '\n'
		<< "**********************************************************" << '\n'
		<< endl;
	cout <<'\n'<< "����������ѡ��" << endl;
}
void WorkerManager:: SystemClose() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager:: w_Addnum(int x) {
	if (x > 0) {
		this->set_w_num(x);
		//this->set_w_ptr(x);
		this->fileisempty = false;

		for (int i = 0; i < x; i++) {
			int a;//int32���ڴ�������⣬���ø���=_=����string�����
			string n;
			cout << "����������ְ���ı�ź�����" << endl;
			cin >> a >> n;
			cout << "��ѡ��ְ���ĸ�λ��" << '\n'
				<< "��ְͨ��-1" << '\n'
				<< "���ž���-2" << '\n'
				<< "ִ�ж���-3" << endl;
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
				cout << "�������" << endl;
				break;
			}

			cout << "��ӳɹ���" << endl;
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
	while (ifs >> id && ifs >> name && ifs >> bid) {//�ո�ķָ�������
		//��¼����
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
			cout << "����δ֪����" << endl;
		}
		w_arry.push_back(worker);

	}
	ifs.close();
}
int  WorkerManager::search_emp()const{
	int i = 0;
	if (fileisempty == true)
		cout << "����ְ����¼��" << endl;
	else {
		
		int a,b=0;
		cout << "�������ְ����id" << endl;
		cin >> a;
		for (i = 0; i < w_num; i++) {
			if (w_arry[i]->id == a) {
				w_arry[i]->showinfo();
				b = 1;
				break;
			}
		}
		if (b == 0) {
			cout << "���޴���" << endl;
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
		cout << "����ְ����¼��" << endl;
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
		cout << "�޴�Ա����Ϣ" << endl;
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
		cout << "��ɾ��ְ��" << endl;
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
	cout << "������ȫ��ְ��" << endl;
	system("pause");
	system("cls");
}
void WorkerManager::change_emp() {
	int i = 0;
	if (fileisempty == true)
		cout << "����ְ����¼��" << endl;
	else {

		int a, b = 0;
		cout << "�������޸ĵ�ְ��id" << endl;
		cin >> a;
		for (i = 0; i < w_num; i++) {
			if (w_arry[i]->id == a) {
				b = 1;
				break;
			}
		}
		if (b == 0) {
			cout << "���޴���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	int id, bid;
	string name;
	cout << "�����������޸ĺ��ְ����ź�����" << endl;
	cin >> id >> name;
	
	cout << "��ѡ��ְ���ĸ�λ��" << '\n'
		<< "��ְͨ��-1" << '\n'
		<< "���ž���-2" << '\n'
		<< "ִ�ж���-3" << endl;
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
		cout << "�������ְ����Ϣ" << endl;
		break;
	}
	save();
	system("pause");
	system("cls");
}
void WorkerManager::sort_emp() {
	if (fileisempty == true) {
		cout << "����ְ����¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��ѡ������ʽ��" << '\n'
		<< "1.��ְ�������������" << '\n'
		<< "2.��ְ����Ž�������" << endl;
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
	cout << "����ɹ���" << endl;
	system("pause");
	system("cls");
	return;
}