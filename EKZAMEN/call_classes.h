#include"testu.h"






class work_tester {
	work_file f;
public:

	void set_test(zavdany *z) {
		z->set_test();
	}
	/// ////////////////////

	void zdacha(zavdany* z,string email,string path,string str) {
		z->reply_test();
		z->set_zdani_testu(email, path,str);
	}
	void verification_passed_tests(zavdany *z) {
		z->print_correct_test();
	}
	void checking_overwhelmed_tests(zavdany* z) {
		z->print_wrong_test();
	}

	//�������� ����� ��� ��������� ��� �������� �����
	void resault(zavdany *z) {
		z->set_bal_vidsotok();
		z->resault();
		system("pause");
		system("cls");
	}

	void print_zdani_testu(string email,string path) {
		system("cls");
		f.cout_correct_wrong_fille(email, path);
	system("pause");
	system("cls");
	}
};


void cout_fils(map<string,string> &m,string accounts) {
	fstream fin;
	string str, tim;
	m.clear();
	fin.open(accounts, fstream::in);
	while (!fin.eof()) {
		fin >> str;
		fin >> tim;
		m.insert({ str,tim });
	}

	fin.close();

}

void set_fil_test_films(string path,map<string,films*>m) {
	fstream fin;
	fin.open(path, fstream::app);
	for (auto el = m.begin(); el != m.end(); el++) {
			fin << el->first << "\n";
		for (int i = 0; i < SIZE; i++) {
			fin << el->second->get_test(i) << "\n";
			for (int j = 1; j < 5; j++)
			{
				if (j % 2 == 0)fin << el->second->get_variant(i, j) << "\n";
				else fin << el->second->get_variant(i, j) << "\t";
			}
			fin  << el->second->get_v(i) << "\n";
		}
	}
	fin.close();
}

void set_fil_test_books(string path,map<string,books*>m) {
	fstream fin;
	fin.open(path, fstream::app);

	for (auto el = m.begin(); el != m.end(); el++) {
			fin  << el->first << "\n";
		for (int i = 0; i < SIZE; i++) {
			fin  << el->second->get_test(i) << "\n";
			for (int j = 1; j < 5; j++)
			{
				if (j % 2 == 0)fin <<el->second->get_variant(i, j) << "\n";
				else fin << el->second->get_variant(i, j) << "\t";
			}
			fin  << el->second->get_v(i)<<"\n";
		}
	}
	fin.close();
}


int menu_vubir() {
	cout << string(30, '^') << "\n";
	cout << "|| (1) - �����!\n";
	cout << "|| (2) - Գ����!\n";
	cout << "|| (0) - �����!\n";
	cout << string(30, '^') << "\n";
	cout << "����� �����: ";
	int choic;
	(cin >> choic).get();
	system("pause");
	system("cls");
	return choic;
}

int menu_vubir_2() {
	cout << string(30, '^') << "\n";
	cout << "|| (1) - ������� ����� � �����!\n";
	cout << "|| (0) - ��������� ������!\n";
	cout << string(30, '^') << "\n";
	cout << "����� �����: ";
	int choic;
	(cin >> choic).get();
	system("pause");
	system("cls");
	return choic;
}
	

int menu_last() {
	cout << string(40, '=') << "\n";
	cout << "|| (1) - ����������� �� ���� �����!\n";
	cout << "|| (2) - ����������� �� ���� �����(�� email)!\n";
	cout << "|| (3) - ����������� �� ���� �����(�� ���)!\n";
	cout << "|| (0) - �����!\n";
	cout << string(40, '=') << "\n";
	int choic;
	
	cout << "����� �����: ";
	(cin >> choic).get();
	system("pause");
	system("cls");
	return choic;
}

int menu_2_admin() {
	int choic = 0;
	system("pause");
	system("cls");
	cout << string(40, '=') << "\n";
	cout << "|| (1) - ������ ������!\n";
	cout << "|| (2) - �������� 䳿!\n";
	cout << "|| (3) - ���������� �����!\n";
	cout << "|| (4) - ��������� �����������!\n";
	cout << "|| (5) - ���� �����������!\n";
	cout << "|| (0) - �����\n";
	cout << "�������� �� ������: ";
	switch (_getch()) {
	case '1': choic = 1; break;
	case '2': choic = 2; break;
	case '3': choic = 3; break;
	case '4': choic = 4; break;
	case '5': choic = 5; break;
	case '0': choic = 0; break;
	}
	cout << "\n";
	system("pause");
	system("cls");
	return choic;
}




class work_admina {
	work_file wf;
	map<string, string> m;
	fstream fin;
	films* f[5] = { new films ,new films ,new films ,new films ,new films };
	books* b[5] = { new books ,new books ,new books ,new books ,new books };
	int i=0, j=0;
public:


	void zmina_email_end_parol(string admin) {
		string email, parol;
		pere_2(email);
		pere_1(parol);
		fin.open(admin, fstream::out);
		fin << email << " " << parol;
		fin.close();
	}

	void print_testeriv(string accounts) {
		string str,tim;
		fin.open(accounts,fstream::in);
		while (!fin.eof()) {
        	fin >> str;
			getline(fin, tim);
			cout << "Email: " << str<<"\n";
		}
		fin.close();
	}
	void work_acount_testera_add(string accounts) {
		tester t;
		t.register_account(accounts);

	}


	void work_acount_testera_remove(string accounts) {
		cout_fils(m, accounts);
		print_testeriv(accounts);
		cout << "\n����� email ����������� ���� ������ ��������: ";
		string ema;
		getline(cin, ema);
		auto res = m.find(ema);
		if (res != m.end()){
			m.erase(res);
     	}
			else {
				cout << "������ email �� ����!\n";
			}
	
		fin.open(accounts, fstream::out);
			auto el = m.begin();
				fin << el->first << " " << el->second ;
				el++;
				for (el ; el != m.end(); el++) {
				fin <<"\n" << el->first << " " << el->second;
			   }
			fin.close();
		}

		void work_acount_testera_zamina(string accounts) {
			string email, parol;
			string email_tim, parol_tim;
			int choic;
			bool pere=true;
			cout_fils(m, accounts);
			print_testeriv(accounts);
			cout << "\n����� email ����������� ���� ������ �������: ";
			string ema;
			getline(cin, ema);
			auto res = m.find(ema);
			if (res != m.end()) {
				email_tim = res->first;
				parol_tim = res->second;
				m.erase(res);
				do {
					cout << "������� email(1)\n������� ������(2)\n";
					cout << "����� �����: ";
					try {
						(cin >> choic).get();
						if (choic <= 0 || choic >= 3)throw string("���� �� ��� ���!\n");
						pere = false;
					}
					catch (string ex) { cout << ex; }
					if (choic == 1) {
						pere_2(email);
						parol = parol_tim;
					}
					else {
						email = email_tim;
						pere_1(parol);
					}
				} while (pere);
			m.insert({ email,parol });
			}
			else {
				cout << "������ email �� ����!\n";
			}
			fin.open(accounts, fstream::out);
			auto el = m.begin();
			fin << el->first << " " << el->second;
			el++;
			for (el; el != m.end(); el++) {
				fin << "\n" << el->first << " " << el->second;
			}
			fin.close();
		
		}

		void add_test(map<string, films*>&mf, map<string, books*>&mb) {
			int choic,c;
			string str;
			do {
				choic = menu_vubir();
				if (!choic)break;
				switch (choic) {
				case 1:
					c = menu_vubir_2();
					if (!c) {
						if (j < 5) {
							cout << "����� ����� ����� �� ��� ������: ";
							getline(cin, str);
							b[j]->set_test();
							mb.insert({ str,b[j] });
						}
						else {
							cout << "������� ����������� ������� ��� ��� �����!\n";
						}
					}
					else {


					}
					
					break;
				case 2:
					c = menu_vubir_2();
					if (!c) {
						if (i < 5) {
							cout << "����� ����� ����� �� ��� ������: ";
							getline(cin, str);
							f[i]->set_test();
							mf.insert({ str,f[i] });
							i++;
						}
						else {
							cout << "������� ����������� ������� ��� ��� �����!\n";
						}
					}
					else {

					}

					break;
				}
			} while (true);
			set_fil_test_films("������� �� �������.txt", mf);
			set_fil_test_books("������� �� ������.txt", mb);

		}



		void pereglyt(string zdani,string accounts ) {
			int choic;
			string email;
			do {
				choic = menu_last();
				if (!choic)break;

				switch (choic) {
				case 1:
					
					wf.cout_correct_wrong_fille(zdani);

					break;
				case 2:
					print_testeriv(accounts);
					cout << "\n����� email: ";
					getline(cin, email);
					wf.cout_correct_wrong_fille(email, zdani);
						break;
				case 3:
					cout << "\n����� ����: ";
					getline(cin, email);
					wf.cout_correct_wrong_fille(email, zdani);
					break;
				}
				system("pause");
				system("cls");
			} while (true);

        }
};






