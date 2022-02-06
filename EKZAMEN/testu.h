#include"Tester.h"


class putany_testiv {
	string test, str;
	map<int, string>m;
	int v=0,you=0;
public:
	void set_putany() {
		cout << "Ведіть запитання: ";
		getline(cin, test);
		for (int i = 0; i < 4; i++)
		{
			cout << "Ведіть (" << i + 1 << ") - варіант відповіді : ";
			cin >> str;
			m.insert({ i + 1,str });
		}
		cout << "Ведіть номер відповеді яка правельна: ";
		(cin >> v).get();
		system("pause");
		system("cls");
	}

	void print_putany() {
		cout << "Питання: " << test;
		cout << "\nВаріанти відповідей:\n";
		for (int i = 0; i < 4; i++)
		{
			auto el = m.find(i + 1);
			cout << "(" << i + 1 << ") - варіант відповіді : " << el->second;
			if (i % 2 == 0)cout << "\t";
			else cout << "\n";
		}
	}
	//SET
	void set_test(string test) {this->test = test; }
	void set_variant(int i,string v1) {m.insert({ i,v1 });}
	void set_vidpovid(int i) { v = i; }
	void set_you_vidpovid(int i) { you = i; }


	//GET
	string get_test()const { return   test; }
	string get_v1(int i)const { auto el = m.find(i); return el->second; }
	int get_v()const { return v; }
	int get_you()const { return you; }


};

#define SIZE 2 //6

class zavdany {
public:
	virtual void set_name_testa() {};
	virtual void set_test() { };
	virtual void print_test() = 0;
	virtual void reply_test() = 0;
	virtual void print_correct_test() = 0;
	virtual void print_wrong_test() = 0;

	virtual void set_bal_vidsotok() = 0;
	
virtual void resault() = 0;

	virtual void set_test_in_fille()=0;

	virtual void print_zdani_t(string, string )=0;
	virtual void set_zdani_testu(string, string)=0;


	virtual string get_test(int i) = 0;

	virtual string get_variant(int i, int j) = 0;

	virtual int get_v(int i) = 0;
	virtual int get_v_you(int i) = 0;

};


class work_file {
	fstream fin;
	string str;
	int v=0;
public:

	void cout_fille(string path, list<putany_testiv> &p){
		fin.open(path, fstream::in);
		auto el = p.begin();
		for (int i = 0; i < SIZE; i++)
		{

			getline(fin, str);
			el->set_test(str);
			for (int j = 1; j < 5; j++)
			{
			fin >> str;
			el->set_variant(j, str);
			}
			fin >> v;
			el->set_vidpovid(v);
			getline(fin, str);
			getline(fin, str);
			el++;
		}
		fin.close();
	}
	
	void cin_fille(string path, putany_testiv p[SIZE]){
		fin.open(path, fstream::out);
		for (int i = 0; i < SIZE; i++){
			fin << p[i].get_test()<<"\n";
			for (int j = 1; j < 5; j++){
				if (j % 2 == 0)fin<< p[i].get_v1(j) << "\t";
				else fin << p[i].get_v1(j)<<"\n";
			}
			fin << p[i].get_v() << "\n";
			fin << string(30, '=')<<"\n";
	     }
		fin.close();
	}
	
	void app_fille(string path, putany_testiv p[SIZE]){
		fin.open(path, fstream::app);
		for (int i = 0; i < SIZE; i++){
			fin << p[i].get_test()<<"\n";
			for (int j = 1; j < 5; j++){
				if (j % 2 == 0)fin<< p[i].get_v1(j) << "\t";
				else fin << p[i].get_v1(j)<<"\n";
			}
			fin << p[i].get_v() << "\n";
			fin << string(30, '=')<<"\n";
	     }
		fin.close();
	}



	void cin_correct_wrong_fille(string email,string path, map<int, putany_testiv> correct, map<int, putany_testiv> wrong,double ball,double vidsotk ){
		fin.open(path, fstream::app);
		fin << "\nEmail: " << email<<"\n";
		string str;
		for (auto el = correct.begin(); el != correct.end(); el++) {
			fin << el->first << ") ";
			str = el->second.get_test();
			for (int i = 0;  i < str.size(); i++)
				fin << str[i];
			fin << "\n";
			for (int j = 1; j < 5; j++) {
				if (j % 2 == 0)fin << "(" << j << ") - варіант відповіді: "<< el->second.get_v1(j) << "\n";
				else fin << "(" << j << ") - варіант відповіді: " << el->second.get_v1(j) << "\t";
			}
			fin<<"Ваша відповідь: " << el->second.get_v() << " | Правельна відповідь: " << el->second.get_you() << "\n";
			fin << string(30, '=') << "\n";
		}

		for (auto el = wrong.begin(); el != wrong.end(); el++) {
			fin << el->first << ") ";
				str = el->second.get_test();
				for (int i = 0; i < str.size(); i++)
					fin << str[i];
			fin << "\n";
			for (int j = 1; j < 5; j++) {
				if (j % 2 == 0)fin << "(" << j << ") - варіант відповіді: "<< el->second.get_v1(j) << "\n";
				else fin << "(" << j << ") - варіант відповіді: " << el->second.get_v1(j) << "\t";
			}
			fin << "Ваша відповідь: " << el->second.get_v() << " | Правельна відповідь: " << el->second.get_you() << "\n";
			fin << string(30, '=') << "\n";
		}
		fin<<"Оцінка: " << ball << " | Ваш %" << vidsotk<<" із 100%" << "\n";
		fin.close();
	}

	void cout_correct_wrong_fille(string email, string path) {
		string str;
		fin.open(path, fstream::in);
		while (!fin.eof()) {
			fin >> str;
				if (str == email) {
					for (int i = 0; i <= 11; i++) {
						getline(fin, str);
						cout << str<<"\n";
					}
				}
		}
			fin.close();
	}
};






class films :public zavdany {
	int nomer;
	double bal,vidsot=8.33333;
	int vidpo;

	list<putany_testiv> l;

	putany_testiv p;
	map<int, putany_testiv> correct, wrong;
	string path = "Питання по фільмах.txt";
	work_file wf;

public:
	void set_test()override{
		for (int i = 0; i < SIZE; i++)
		{
			p.set_putany();
			l.push_back(p);
			//l.push_back(p);
		}

		for (auto el = l.begin(); el != l.end(); el++) {
			el->print_putany();
			cout << string(50, '=') << "\n";
		}

   }


	void set_test_in_fille()override {
			wf.cout_fille(path, l);
	}


	void print_test() override {
		for (auto el = l.begin(); el != l.end(); el++) {
			el->print_putany();
		}
	}
	void reply_test()override {
		auto el = l.begin();
		for (int i = 0; i < SIZE; i++)
		{
			cout << "Завдання: " << i + 1 << "\n";
			el->print_putany();
			(cin >> vidpo).get();
			el->set_you_vidpovid(vidpo);
			if (vidpo == el->get_v()) {
				cout << el->get_v1(vidpo);
				correct.insert({ vidpo,*el});
			}
			else {
				wrong.insert({ vidpo,*el });
			}
			el++;
		}
	}
	void print_correct_test()override {
		cout << string(50, '^')<<"\n";
		for (auto el = correct.begin(); el !=correct.end(); el++)
		{
			el->second.print_putany();
			cout << "Ви відповіли правельно: " << el->second.get_v1(el->first)<<"\n";
		}
		cout << string(50, '^')<<"\n";
	}
	void set_bal_vidsotok()override {
		bal = 2*correct.size();
		vidsot *= bal;
		vidsot = ceil(vidsot);
	}

	void resault()override {
		cout << "Бали за тест: " << bal << "\n";
		cout << "Процент правельних відповідей: " <<  vidsot << "%\n";
	}
	void print_wrong_test() override {
		cout << string(50, '^') << "\n";
		for (auto el = wrong.begin(); el != wrong.end(); el++)
		{
			el->second.print_putany();
			cout << "Ви відповіли: " << el->second.get_v1(el->first);
			cout << "\nПравельна віідповідь: " << el->second.get_v1(el->second.get_v())<<"\n";
		}
		cout << string(50, '^') << "\n";
	}

	void print_zdani_t(string email, string path)override {
		wf.cout_correct_wrong_fille(email, path);
	}

	string get_test(int i) override {
		auto el = l.begin();
		advance(el,i);
		return el->get_test();
	}
	
	string get_variant(int i,int j) override {
		for (auto el = l.begin(); el != l.end(); el++) {
			el->print_putany();
			cout << string(50, '=') << "\n";
		}
		
		/*	auto el = l.begin();
		cout << i << "\n";
		
		advance(el,);

		cout<<el->get_v1(j)<<"\n";
		system("pause");*/

//		return el->get_v1(j);

		return "dfsdfsd";
	}
	
	int get_v(int i) override {
		auto el = l.begin();
		advance(el,i);
		return el->get_v();
	}
	int get_v_you(int i) override{
		auto el = l.begin();
		advance(el,i);
		return el->get_you();
	}


	void set_zdani_testu(string email,string path)override {
		wf.cin_correct_wrong_fille(email, path, correct, wrong, bal, vidsot);
	}
	~films() {

	}
};

	class books :public zavdany {
	int nomer;
	double bal,vidsot=8.33333;
	int vidpo;
	list<putany_testiv> l;
	putany_testiv p;
	map<int, putany_testiv> correct, wrong;
	string path = "Питання по книгах.txt";
	work_file wf;

public:
	void set_test()override{
		for (int i = 0; i < SIZE; i++)
		{
			p.set_putany();
			l.push_back(p);
		}
   }
	string get_test(int i) override {
		auto el = l.begin();
		advance(el, i);
		return el->get_test();
	}

	string get_variant(int i, int j) override {
		auto el = l.begin();
		advance(el, i);
		return el->get_v1(j);
	}

	int get_v(int i) override {
		auto el = l.begin();
		advance(el, i);
		return el->get_v();
	}
	int get_v_you(int i) override {
		auto el = l.begin();
		advance(el, i);
		return el->get_you();
	}

	void set_test_in_fille()override {
			wf.cout_fille(path, l);
	}
	void print_test() override {
		for (auto el = l.begin(); el != l.end(); el++) {
			el->print_putany();
		}
	}
	void reply_test()override {
		auto el = l.begin();
		for (int i = 0; i < SIZE; i++)
		{
			cout << "Завдання: " << i + 1 << "\n";
			el->print_putany();
			(cin >> vidpo).get();
			el->set_you_vidpovid(vidpo);
			if (vidpo == el->get_v()) {
				cout << el->get_v1(vidpo);
				correct.insert({ vidpo,*el});
			}
			else {
				wrong.insert({ vidpo,*el });
			}
			el++;
		}
	}
	void print_correct_test()override {
		cout << string(50, '^')<<"\n";
		for (auto el = correct.begin(); el !=correct.end(); el++)
		{
			el->second.print_putany();
			cout << "Ви відповіли правельно: " << el->second.get_v1(el->first)<<"\n";
		}
		cout << string(50, '^')<<"\n";
	}
	void set_bal_vidsotok()override {
		bal = 2*correct.size();
		vidsot *= bal;
		vidsot = ceil(vidsot);
	}
	void resault()override {
		cout << "Бали за тест: " << bal << "\n";
		cout << "Процент правельних відповідей: " <<  vidsot << "%\n";
	}
	void print_wrong_test() override {
		cout << string(50, '^') << "\n";
		for (auto el = wrong.begin(); el != wrong.end(); el++)
		{
			el->second.print_putany();
			cout << "Ви відповіли: " << el->second.get_v1(el->first);
			cout << "\nПравельна віідповідь: " << el->second.get_v1(el->second.get_v())<<"\n";
		}
		cout << string(50, '^') << "\n";
	}

	void print_zdani_t(string email, string path)override {
		wf.cout_correct_wrong_fille(email, path);
	}

	void set_zdani_testu(string email,string path)override {
		wf.cin_correct_wrong_fille(email, path, correct, wrong, bal, vidsot);
	}
	~books() {

	}

};
	