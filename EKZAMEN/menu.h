#include"call_classes.h"

int menu_1() {
	int choic;
	cout << string(40, '=') << "\n";
	cout << "|| (1) - Вхід акаунт адміна!\n";
	cout << "|| (2) - Вхід акаунт тестира!\n";
	cout << "|| (3) - Регістарція акаунта тестора !\n";
	cout << "|| (0) - Вихід\n";
	cout << "Натисніть на клавішу: ";
	switch (_getch()) {
	case '1': choic=1; break;
	case '2': choic = 2; break;
	case '3': choic =  3; break;
	case '0': choic =  0; break;
	}
	cout << "\n";
	system("pause");
	system("cls");
	return choic;
}




int menu_2() {
	int choic=0;
	system("pause");
	system("cls");
	cout << string(40, '=') << "\n";
	cout << "|| (1) - Фільми!\n";
	cout << "|| (2) - Книги!\n";
	cout << "|| (0) - Вихід\n";
	cout << "Натисніть на клавішу: ";
	switch (_getch()) {
	case '1': choic = 1; break;
	case '2': choic = 2; break;
	case '0': choic = 0; break;
	}

	return choic;
}




int menu_4() {
	int choic = 0;
	system("cls");
	cout << string(40, '=') << "\n";
	cout << "|| (1) - Переглянути резульат тесту!\n";
	cout << "|| (2) - Пройти тест!\n";
	cout << "|| (3) - Переглянути усі тести які здані!\n";
	cout << "|| (0) - Вихід\n";
	cout << "Натисніть на клавішу: ";
	switch (_getch()) {
	case '1': choic = 1; break;
	case '2': choic = 2; break;
	case '3': choic = 3; break;
	case '0': choic = 0; break;
	}
	return choic;
}

int menu_3_books(map<string, books*>&m) {
	int i=1;
	system("pause");
	system("cls");
	cout << string(40, '=') << "\n";
	for (auto el = m.begin(); el != m.end(); el++) {
		cout << "|| ("<<i<<") - " << el->first << "\n";
		i++;
	}
	cout << "|| (0) - Вихід\n";
	cout << "Натисніть на клавішу: ";
	int choic;
(	cin >> choic).get();
	return choic;
}

int menu_3_films(map<string, films*>& m) {
	int i=1;
	system("pause");
	system("cls");
	cout << string(40, '=') << "\n";
	for (auto el = m.begin(); el != m.end(); el++) {
		cout << "|| ("<<i<<") - " << el->first << "\n";
		i++;
	}
	cout << "|| (0) - Вихід\n";
	cout << "Натисніть на клавішу: ";
	int choic;
(	cin >> choic).get();
	return choic;
}




void step_4_films(string zdani,string email,int i, map<string, films*>&m) {
	int choic;
	auto el = m.begin();
	advance(el, i);
	work_tester w;
	do {
		choic = menu_4();
		if (!choic)break;
		switch (choic) {
		case 1:
			w.verification_passed_tests(el->second);
			w.checking_overwhelmed_tests(el->second);
			break;
		case 2:
			w.zdacha(el->second, email, zdani,el->first);
			break;
		case 3:
			w.print_zdani_testu(email, zdani);
			break;
		}
	} while (true);
}

void step_4_books(string zdani,string email,int i, map<string, books*>&m) {
	int choic;
	auto el = m.begin();
	system("pause");
	advance(el, i);
	work_tester w;
	do {

		choic = menu_4();
		if (!choic)break;
		switch (choic) {
		case 1:
			w.verification_passed_tests(el->second);
			w.checking_overwhelmed_tests(el->second);
			break;
		case 2:
			w.zdacha(el->second, email, zdani,el->first);
			break;
		case 3:
			w.print_zdani_testu(email, zdani);
			break;
	
		}

	} while (true);
}


void step_3_films(string zdani, string email,  map<string, films*>&m) {
	int choic;
	do {
		choic = menu_3_films(m);
		if (!choic)break;
		step_4_films(zdani, email, choic, m);

	} while (true);
}


void step_3_books(string zdani, string email, map<string, books*> &m) {
	int choic;
	do {
		choic = menu_3_books(m);
		if (!choic)break;
		step_4_books(zdani, email, choic, m);
	} while (true);
}





void step_2(string zdani,string email, map<string, books*>mb,map<string, films*>&mf ) {
	int choic;
	do {
		choic = menu_2();
		if (!choic)break;
		switch (choic) {
		case 1:
			step_3_films(zdani, email, mf);
			break;
		case 2:
			step_3_books(zdani, email, mb);
			break;

		}
	} while (true);
}



