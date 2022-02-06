#include"call_classes.h"
int size_films = 0;

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
	cout << "|| (3) - Переглянути можливі тести!\n";
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

int menu_2_admin() {
	int choic=0;
	system("pause");
	system("cls");
	cout << string(40, '=') << "\n";
	cout << "|| (1) - Змінини пароль!\n";
	cout << "|| (2) - ...!\n";
	cout << "|| (3) - ...!\n";
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
work_tester w;

int menu_3(map<string, zavdany*>m) {
	int i=1;
	system("pause");
	system("cls");
	cout << string(40, '=') << "\n";
	for (auto el = m.begin(); el != m.end(); el++) {
		cout << "|| ("<<i<<" - " << el->first << "\n";
		i++;
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
	//advance(el, i);
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

void step_2_in_admin(string admin) {
	int choic;
	work_admina wa;
	do {
		choic = menu_2();
		if (!choic)break;
		switch (choic) {
		case 1:
			wa.zmina_email_end_parol(admin);
			break;
		case 2:



			break;

		}


	} while (true);


}




void step_1(string accou,string zdani,string admin, map<string, zavdany*>m ) {
	int choic;
	tester t;
	do {
		choic = menu_1();
		if (!choic)break;
		switch (choic) {
		case 1:
			if (t.login_account(admin)) {

				step_2_in_admin(admin);
			}
			else {

			}


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