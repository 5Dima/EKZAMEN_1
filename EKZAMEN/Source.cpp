#include"admin.h"


int main() {
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� ����� 
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	string accounts = "�������.txt";
	string zdani = "���� �����.txt";
	string admin = "����.txt";
	work_tester w;
	map<string, films*>mf;
	map<string, books*>mb;
	films *f=new films;


    step_1(accounts,zdani,admin,mb,mf);



	return 0;
}