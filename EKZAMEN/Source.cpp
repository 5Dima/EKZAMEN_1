#include"menu.h"

int main() {
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода 
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	string accounts = "Акаунти.txt";
	string zdani = "Здані тести.txt";
	string admin = "Адмін.txt";
	work_tester w;
	map<string, films*>mf;
	map<string, books*>mb;
	map<string, zavdany*>m;
	films *f=new films;
	//work_admina wa;

	step_1(accounts,zdani,admin,mb,mf);



	// wa.add_test(mf, mb);
	//f->set_test();

	//m.insert({ "Гарі",f });
	//f->set_test();



	//f[0]->print_correct_test();
	//w.resault();

	//w.zdacha(z[0], "safas", "Asfsa");
	////auto el = v.begin();
	//w.set_test(z[0]);

	//m.insert({ "asf",f });
	//
	////auto el = m.begin();
	//auto el = m.begin();

	/*m.insert({"Гарі",f});

	step_1(accounts,zdani,m);*/

	



	return 0;
}