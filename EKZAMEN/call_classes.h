#include"testu.h"






class work_tester {
	work_file f;
public:
	void zdacha(zavdany* z,string email,string path) {
		z->reply_test();
		z->set_zdani_testu(email, path);
	}
	void verification_passed_tests(zavdany *z) {
		z->print_correct_test();
	}
	void checking_overwhelmed_tests(zavdany* z) {
		z->print_wrong_test();
	}

	//доробити метод для перегляду усіх можливих тестів
	void resault(zavdany* z) {
		z->set_bal_vidsotok();
		z->resault();
	}

	void print_zdani_testu(string email,string path) {
	f.cout_correct_wrong_fille(email, path);
	}
};



