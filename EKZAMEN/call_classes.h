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

	//доробити метод для перегляду усіх можливих тестів
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

//
//void cout_fil_test_books(string path,map<string,books*>&m) {
//	fstream fin;
//	string p,str,test, v1, v2, v3, v4;
//	int v;
//	books* b=new books;
//	fin.open(path, fstream::in);
//	//while (!fin.eof()) {
//		getline(fin, str);
//		for (int i = 0; i < SIZE; i++)
//		{
//		getline(fin, test);
//		fin >> v1;
//		fin >> v2;
//		fin >> v3;
//		fin >> v4;
//		getline(fin, p);
//		fin >> v;
//		b->set_test(test, i);
//		b->set_variant(v1, i, 1);
//		b->set_variant(v2, i, 2);
//		b->set_variant(v3, i, 3);
//		b->set_variant(v4, i, 4);
//		b->set_p(i);
//		}
//	m.insert({str,b});
////	}
//	fin.close();
//}

int menu_vubir() {
	cout << string(30, '^') << "\n";
	cout << "|| (1) - Книги!\n";
	cout << "|| (2) - Фільми!\n";
	cout << "|| (0) - Вихід!\n";
	cout << string(30, '^') << "\n";
	cout << "Ведіть число: ";
	int choic;
	(cin >> choic).get();
	system("pause");
	system("cls");
	return choic;
}

int menu_vubir_2() {
	cout << string(30, '^') << "\n";
	cout << "|| (1) - Считати тести з файлу!\n";
	cout << "|| (0) - Вихід!\n";
	cout << string(30, '^') << "\n";
	cout << "Ведіть число: ";
	int choic;
	(cin >> choic).get();
	system("pause");
	system("cls");
	return choic;
}
	

int menu_last() {
	cout << string(40, '=') << "\n";
	cout << "|| (1) - Переглянути усі здані тести!\n";
	cout << "|| (2) - Переглянути усі здані тести(по email)!\n";
	cout << "|| (3) - Переглянути усі здані тести(по темі)!\n";
	cout << "|| (0) - Вихід!\n";
	cout << string(40, '=') << "\n";
	int choic;
	
	cout << "Ведіть число: ";
	(cin >> choic).get();
	return choic;
}

int menu_2_admin() {
	int choic = 0;
	system("pause");
	system("cls");
	cout << string(40, '=') << "\n";
	cout << "|| (1) - Змінини пароль!\n";
	cout << "|| (2) - Подальші дії!\n";
	cout << "|| (0) - Вихід\n";
	cout << "Натисніть на клавішу: ";
	switch (_getch()) {
	case '1': choic = 1; break;
	case '2': choic = 2; break;
	case '0': choic = 0; break;
	}

	return choic;
}




class work_admina {
	work_file wf;
	map<string, string> m;
	fstream fin;
	films* f = new films;
	books* b = new books;
public:

	void set_test(zavdany *z) {
		z->set_test();
	}
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
		cout << "\nВедіть email користувача який бажаєте видалити: ";
		string ema;
		getline(cin, ema);
		auto res = m.find(ema);
		if (res != m.end()){
			m.erase(res);
     	}
			else {
				cout << "Такого email не існує!\n";
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
			cout << "\nВедіть email користувача який бажаєте замінити: ";
			string ema;
			getline(cin, ema);
			auto res = m.find(ema);
			if (res != m.end()) {
				email_tim = res->first;
				parol_tim = res->second;
				m.erase(res);
				do {
					cout << "Замінити email(1)\nЗамінити пароль(2)\n";
					cout << "Ведіть число: ";
					try {
						(cin >> choic).get();
						if (choic <= 0 || choic >= 3)throw string("Вели не вірні дані!\n");
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
				cout << "Такого email не існує!\n";
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

		void add_test(map<string, films*>mf, map<string, books*>mb) {
			int choic,c;
			string str;
			do {
				choic = menu_vubir();
				if (!choic)break;
				switch (choic) {
				case 1:
					c = menu_vubir_2();
					if (!c) {
						cout << "Ведіть назву теста по темі книжки: ";
						getline(cin, str);
						b->set_test();
						mb.insert({ str,b });
					}
					else {
					
					}
					break;
				case 2:
					c = menu_vubir_2();
					if (!c) {
						cout << "Ведіть назву теста по темі фільми: ";
						getline(cin, str);
						f->set_test();
						mf.insert({ str,f });
					}
					else {

					}

					break;
				}
			} while (true);
			set_fil_test_films("Питання по фільмах.txt", mf);
			set_fil_test_books("Питання по книгах.txt", mb);

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
					cout << "\nВедіть email: ";
					getline(cin, email);
					wf.cout_correct_wrong_fille(email, zdani);
						break;
				case 3:
					cout << "\nВедіть тему: ";
					getline(cin, email);
					wf.cout_correct_wrong_fille(email, zdani);
					break;
				}

			} while (true);

        }
};






