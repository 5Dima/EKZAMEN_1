#include"menu.h"



//
//void step_3_admn(string zdani, string email, map<string, books*>mb, map<string, films*>mf) {
//	int choic;
//	do {
//		choic = menu_2();
//		if (!choic)break;
//		switch (choic) {
//		case 1:
//			step_3_films_admin(zdani, email, mf);
//			break;
//		case 2:
//			step_3_books_admin(zdani, email, mb);
//			break;
//
//		}
//	} while (true);
//}



void step_2_in_admin(string admin, string email, map<string, books*>&mb, map<string, films*>&mf, string zdani,string accou) {
	int choic;
	work_admina wa;
	do {
		choic = menu_2_admin();
		if (!choic)break;
		switch (choic) {
		case 1:
			wa.zmina_email_end_parol(admin);
			break;
		case 2:
			wa.pereglyt(zdani, accou);
			break;
				case 3:
					wa.add_test(mf, mb);
			break;
					case 4:
					wa.work_acount_testera_remove(accou);
			break;
					case 5:
					wa.work_acount_testera_zamina(accou);
			break;

		}


	} while (true);


}

void step_1(string accou, string zdani, string admin, map<string, books*>&mb, map<string, films*>&mf) {
	int choic;
	tester t;
	do {
		choic = menu_1();
		if (!choic)break;
		switch (choic) {
		case 1:
			if (t.login_account(admin)) {
				step_2_in_admin(admin, t.get_email(), mb, mf, zdani,accou);
			}
			else {
				cout << "\nВи не змогли увійти в систему!\n";
				system("pause");
				system("cls");
			}


			break;
		case 2:
			if (t.login_account(accou) == true) {
				step_2(zdani, t.get_email(), mb, mf);
			}
			else {
				cout << "\nВи не змогли увійти в систему!\n";
				system("pause");
				system("cls");
			}

			break;
		case 3:
			t.register_account(accou);
			break;

		}


	} while (true);
}
