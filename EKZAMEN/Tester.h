#include<iostream>
//STL
#include<vector>
#include<string>
#include<map>

// додадктові
#include<windows.h>
#include<iomanip>
#include<fstream>
#include<algorithm>


using namespace std;

bool cheсk_email(string path, string email) {
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

bool cheсk_parols(string path, string parol) {
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
	cout << "|| 1 - Спробувати ще раз!\n";
	cout << "|| 2 - Вихід!\n";
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
		cout << "Ведіть email: ";
	getline(cin, email);
		if (email.size() < 4)throw string("Мінімум 6 символа!\n");
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
			cout << "Ведіть пароль: ";
			getline(cin, parol);
			if (parol.size() < 4)throw string("Мінімум 4 символа!\n");
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
			cout << "Регістрація акаунта!\n";
			pere_2(email);
			if (cheсk_email(path, email)) {
				cout << "Такий email вже існує!\n";
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
			cout << "Вхід в акаунт!\n";
			cout << "Ведіть email: ";
			getline(cin, email);
			if (cheсk_email(path, email)) {
			
				cout << "Ведіть пароль: ";
				for (int i = 1; i < sprob; i++)
				{
				getline(cin, parol);
				
				if (cheсk_parols(path, parol)) {
					login = true;
					break;
				}
				else {
					if (sprob - i != 1) { cout << "Залишилось " << sprob - i-1 << " спроби!\n"; }
					else { cout << "Всі спроби завершились"; }
				}
					pere = false;
				}
			}
			else {
				cout << "Такий email не існує!\n";
				if (putany() == false)pere = false;
			}
		}
		return login;
	}

	string get_email()const { return email; }




};

