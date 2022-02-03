#include<iostream>
//STL
#include<vector>
#include<string>
#include<map>

// ���������
#include<windows.h>
#include<iomanip>
#include<fstream>
#include<algorithm>


using namespace std;

bool che�k_email(string path, string email) {
	string str;
	fstream fin;
	bool p=false;
	fin.open(path, fstream::in);
	while (!fin.eof()) {
		fin >> str;
		if (str == email) {
			p = true;
			break;
		}
		fin >> str;
	}
		fin.close();
		return p;
}

bool che�k_parols(string path, string parol) {
	string str;
	fstream fin;
	bool p=false;
	fin.open(path, fstream::in);
	while (!fin.eof()) {
		fin >> str;
		fin >> str;
		if (str == parol) {
			p = true;
			break;
		}
	}
		fin.close();
		return p;
}
bool putany() {
	int choic;
	cout << "|| 1 - ���������� �� ���!\n";
	cout << "|| 2 - �����!\n";
	cout << "Enter you choic: ";
	(cin >> choic).get();
	system("cls");
	if (choic == 1)return true;
	return false;
}


void pere_2(string &email) {
	bool login;
	do {
		login = false;
		try {
		cout << "����� email: ";
	getline(cin, email);
		if (email.size() < 4)throw string("̳���� 6 �������!\n");
		}
		catch (string ex) {
			cout << ex;
			login = true;
		}
		catch (...) {}
	} while (login);

}

void pere_1(string &parol) {
	bool login;
	do {
		login = false;
		try {
			cout << "����� ������: ";
			getline(cin, parol);
			if (parol.size() < 4)throw string("̳���� 4 �������!\n");
		}
		catch (string ex) {
			cout << ex;
			login = true;
		}
		catch (...) {}
	} while (login);

}

class tester {
	string email, parol;
	fstream fin;
	bool pere, login;
public:
	void register_account(string path) {
		pere = true;
		while (pere) {
			cout << string(40, '+') << "\n";
			cout << "���������� �������!\n";
			pere_2(email);
			if (che�k_email(path, email)) {
				cout << "����� email ��� ����!\n";
				if (putany()==false)pere = false;
			}
			else {
				pere_1(parol);
				fin.open(path, fstream::app);
				fin << email<<" " << parol << "\n";
				pere = false;
				fin.close();
			}
		}
	}

	bool login_account(string path) {
		login = false;
		pere = true;
		const int sprob = 5;
		while (pere) {
			cout << string(40, '=') << "\n";
			cout << "���� � ������!\n";
			cout << "����� email: ";
			getline(cin, email);
			if (che�k_email(path, email)) {
			
				cout << "����� ������: ";
				for (int i = 1; i < sprob; i++)
				{
				getline(cin, parol);
				
				if (che�k_parols(path, parol)) {
					login = true;
					break;
				}
				else {
					if (sprob - i != 1) { cout << "���������� " << sprob - i-1 << " ������!\n"; }
					else { cout << "�� ������ �����������"; }
				}
					pere = false;
				}
			}
			else {
				cout << "����� email �� ����!\n";
				if (putany() == false)pere = false;
			}
		}
		return login;
	}

	string get_email()const { return email; }




};

