#include"WorkerManager.h"
using namespace std;
int main() {
	int choice;
    WorkerManager wm;
    
	while (1) {
		wm.Showmenu();
		cin >> choice;
		switch (choice) {
		case 0:
			wm.SystemClose();
			break;
		case 1:
			int a;
			cout << "����������ӵ�Ա������" << endl;
			cin >> a;
			wm.w_Addnum(a);
			//cout << wm.get_w_num() << endl;
			//wm.w_arry[1]->showinfo();//��Ա�������ԣ��ɹ����
			break;
		case 2:
			wm.showinfo_all();
			//cout << wm.get_w_num() << endl;
			//wm.w_arry[3]->showinfo();//�������ԣ��޸���
			break;

		case 3:
			wm.cal_emp(wm.search_emp());
			
			break;
		case 4:
			wm.change_emp();
			break;
		case 5:
			wm.search_emp();
			break;
		case 6:
			wm.sort_emp();
			break;
		case 7:
			wm.clean_all();
			break;
		default:
			cout << "�������" << endl;
			system("pause");
			system("cls");

		}
	}
}