#include"menu.h"

int main() {
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� ����� 
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	string accounts = "�������.txt";
	string zdani = "���� �����.txt";
	string admin = "����.txt";

	work_tester w;
	map<string, films*>mf;
	map<string, books*>mb;
	//zavdany *z[2] = { new films };
	films *f=new films;
	work_admina wa;
	//wa.print_testeriv(accounts);
	//wa.work_acount_testera_add(accounts);
	 wa.add_test(mf, mb);


	//f->set_test();

	//m.insert({ "���",f });
	//f->set_test();

	//step_1(accounts,zdani,m);


	//f[0]->print_correct_test();
	//w.resault();

	//w.zdacha(z[0], "safas", "Asfsa");
	////auto el = v.begin();
	//w.set_test(z[0]);

	//m.insert({ "asf",f });
	//
	////auto el = m.begin();
	//auto el = m.begin();

	/*m.insert({"���",f});

	step_1(accounts,zdani,m);*/

	



	return 0;
}