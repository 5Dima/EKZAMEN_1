#include"call_classes.h"
int size_films = 0;

int menu_1() {
	cout << "|| (1) - Вхід акаунт адміна!\n";
	cout << "|| (2) - Вхід акаунт тестира!\n";
	cout << "|| (3) - Регістарція акаунта тестора !\n";
	cout << "|| (0) - Вихід\n";
	cout << "Натисніть на клавішу: ";
	switch (_getch()) {
	case '1': return 1; break;
	case '2': return 2; break;
	case '3': return 3; break;
	case '0': return 0; break;
	}
}




int menu_2() {
	cout << "|| (1) - Фільми!\n";
	cout << "|| (2) - Книги!\n";
	cout << "|| (3) - Переглянути можливі тести!\n";
	cout << "|| (0) - Вихід\n";
	cout << "Натисніть на клавішу: ";
	switch (_getch()) {
	case '1': return 1; break;
	case '2': return 2; break;
	case '3': return 3; break;
	case '0': return 0; break;
	}
}


int menu_4() {
	cout << "|| (1) - Переглянути резульат тесту!\n";
	cout << "|| (2) - Пройти тест!\n";
	cout << "|| (3) - Переглянути усі тести які здані!\n";
	cout << "|| (0) - Вихід\n";
	cout << "Натисніть на клавішу: ";
	switch (_getch()) {
	case '1': return 1; break;
	case '2': return 2; break;
	case '3': return 3; break;
	case '0': return 0; break;
	}
}
work_tester w;

int menu_3(map<string, zavdany*>m) {
	int i=1;
	for (auto el = m.begin(); el != m.end(); el++) {
		cout << "|| ("<<i<<" - " << el->first << "\n";
	}
	cout << "|| (0) - Вихід\n";
	cout << "Натисніть на клавішу: ";
	int choic;
(	cin >> choic).get();
	return choic;
}




void step_4(string zdani,string email,int i, map<string, zavdany*>m) {
	int choic;
	auto el = m.begin();
	advance(el, i);
	do {

		choic = menu_4();
		if (!choic)break;
		switch (choic) {

		case 1:
			w.verification_passed_tests(el->second);
			w.checking_overwhelmed_tests(el->second);
			break;
		case 2:
			w.zdacha(el->second, email, zdani);
			break;
		case 3:
			w.print_zdani_testu(email, zdani);
			break;
		}


	} while (true);


}


void step_3(string zdani, string email, map<string, zavdany*>m) {
	int choic;
	do {
		choic = menu_3 (m);
		if (!choic)break;
		step_4(zdani, email, choic, m);

	} while (true);

}


void step_2(string zdani,string email, map<string, zavdany*>m) {
	int choic;
	do {
		choic = menu_2();
		if (!choic)break;
		switch (choic) {
		case 1:
			 step_3(zdani, email, m);
			break;

		}


	} while (true);


}




void step_1(string accou,string zdani, map<string, zavdany*>m ) {
	int choic;
	tester t;
	do {
		choic = menu_1();
		if (!choic)break;
		switch (choic) {
		case 1:

			break;
		case 2:
			if (t.login_account(accou) == true) {
				step_2(zdani, t.get_email(), m);
			}
			else {


			}
		
			break;
		case 3:

			break;

		}


	} while (true);




}