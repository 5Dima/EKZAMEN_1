#include"testu.h"






class work_tester {
public:
	void zdacha(zavdany* z) {
		z->reply_test();
	}
	void verification_passed_tests(zavdany* z) {
		z->print_correct_test();
	}
	void checking_overwhelmed_tests(zavdany* z) {
		z->print_wrong_test();
	}
	void resault(zavdany* z) {
		z->set_bal_vidsotok();
		z->resault();
	}


};

