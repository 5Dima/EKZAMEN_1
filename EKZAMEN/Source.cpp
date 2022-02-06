#include"admin.h"


int main() {
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода 
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	string accounts = "Акаунти.txt";
	string zdani = "Здані тести.txt";
	string admin = "Адмін.txt";
	work_tester w;
	map<string, films*>mf;
	map<string, books*>mb;
	films *f=new films;


    step_1(accounts,zdani,admin,mb,mf);



	return 0;
}