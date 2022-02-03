#include"Tester.h"


class putany_testiv {
	string test, str;
	map<int, string>m;
	int v;
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

	string get_test()const { return   test; }

	string get_v1(int i)const { auto el = m.find(i); return el->second; }

	int get_v()const { return v; }


};

#define SIZE 2

class zavdany {
public:
	virtual void set_name_testa() = 0;
	virtual void set_test() = 0;
	virtual void print_test() = 0;
	virtual void reply_test() = 0;
	virtual void print_correct_test() = 0;
	virtual void print_wrong_test() = 0;
};

class films :public zavdany {
	string name;
	int size, nomer;
	int vidpo;
	list<putany_testiv> l;
	putany_testiv p[5];
	map<int, putany_testiv> correct, wrong;
public:
	void set_name_testa()override {
		cout << "Ведіть назву теста: ";
		getline(cin, name);
	}

	void set_test()override {
		cout << "Назва тесту " << name << "\n";
		for (int i = 0; i < SIZE; i++)
		{
			p[i].set_putany();
			l.push_back(p[i]);
		}
	}

	void print_test() override {
		cout << "Назва тесту " << name << "\n";
		for (int i = 0; i < SIZE; i++)
			p[i].print_putany();
	}

	void reply_test()override {
		cout << "Назва тесту " << name<<"\n";
		for (int i = 0; i < SIZE; i++)
		{
			cout << "Завдання: " << i + 1 << "\n";
			p[i].print_putany();
			(cin >> vidpo).get();
			if (vidpo == p[i].get_v()) {
				cout << p[i].get_v1(vidpo);
				correct.insert({ vidpo,p[i]});
			}
			else {
				wrong.insert({ vidpo,p[i] });
			}
		}
	}
	void print_correct_test()override {
		for (auto el = correct.begin(); el !=correct.end(); el++)
		{
			el->second.print_putany();
			cout << "Ви відповіли правельно: " << el->second.get_v1(el->first)<<"\n";
		}
	}

	void print_wrong_test() override {
		for (auto el = wrong.begin(); el != wrong.end(); el++)
		{
			el->second.print_putany();
			cout << "Ви відповіли правельно: " << el->second.get_v1(el->first);
			cout << "\nПравельна віідповідь: " << el->second.get_v1(el->second.get_v())<<"\n";
		}
	}



};


