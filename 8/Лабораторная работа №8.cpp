#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

struct Abiturient {
	string Name;
	string Surname;
	string Patr;
	string b_year;
	string Ocenki;
	string sr_att;
};

void vvod(Abiturient b[], const int size) {
	for (int i = 0; i < size; i++) {
		cout << "Введите имя Аббитуриента: ";
		cin>> b[i].Name;
		cout<< "Введите Фамилию Аббитуриента: ";
		cin>> b[i].Surname;
		cout << "Введите Отчество Аббитуриента: ";
		cin >> b[i].Patr;
		cin.ignore();
		cout << "Год рождения: ";
		getline(cin, b[i].b_year);
		cout << "Вступительные оценки(3): ";
		getline(cin, b[i].Ocenki);
		
		cout << "Средний балл аттестата: ";
		getline(cin, b[i].sr_att);
	}
}

void vivod(Abiturient b[], const int size) {
	for (int i = 0; i < size; i++) {
		cout << endl;
		cout << "ФИО : " << b[i].Surname << " " << b[i].Name << " " << b[i].Patr << endl;
		cout << "Год рождения " <<b[i].b_year << endl;
		cout <<"Вступительные оценки(3) " <<b[i].Ocenki<< endl;
		cout << "Средний балл аттестата: " <<b[i].sr_att << endl;
	}
}

void delet(Abiturient*& b, int& size) {
	cout << "Введите номер элемента который нужно удалить: ";
	int n;
	cin >> n;
	size--;
	Abiturient* newb = new Abiturient[size];
	for (int i = 0; i < size; i++) {
		if (i == n - 1) {
			newb[i] = b[i + 1];
		}
		else {
			newb[i] = b[i];
		}
	}
	delete[] b;
	b = newb;
}
void zamena(Abiturient b[], const int size) {
	string a,c,d,e,f,g,h;
	cout << "Введите фамилию, после которой надо поставить новый элемент";
	cin >> a;
	cout << "Введите имя Аббитуриента: ";
	cin >> c;
	cout << "Введите Фамилию Аббитуриента: ";
	cin >> d ;
	cout << "Введите Отчество Аббитуриента: ";
	cin >> e;
	cin.ignore();
	cout << "Год рождения: ";
	getline(cin,f);
	cout << "Вступительные оценки(3): ";
	getline(cin, g);
	cout << "Средний балл аттестата: ";
	getline(cin, h);

	for (int i = 0; i < size; i++) {
		if (b[i].Surname != a) {
			cout << endl;
			cout << "ФИО : " << b[i].Surname << " " << b[i].Name << " " << b[i].Patr << endl;
			cout << "Год рождения " << b[i].b_year << endl;
			cout << "Вступительные оценки(3) " << b[i].Ocenki << endl;
			cout << "Средний балл аттестата: " << b[i].sr_att << endl;
		}
		else {
			cout << endl;
			cout << "ФИО : " << b[i].Surname << " " << b[i].Name << " " << b[i].Patr << endl;
			cout << "Год рождения " << b[i].b_year << endl;
			cout << "Вступительные оценки(3) " << b[i].Ocenki << endl;
			cout << "Средний балл аттестата: " << b[i].sr_att << endl;

			cout << endl;
			cout << "ФИО : " << d << " " << c << " " << e << endl;
			cout << "Год рождения " << f << endl;
			cout << "Вступительные оценки(3) " << g << endl;
			cout << "Средний балл аттестата: " << h << endl;


		}
	}
}

/*void add(Owner b[3]) {
cout « "Задайте фамилию перед которой нужно добавить 2 элемента ";
string n;
getline(cin, n);
for (int i = 0; i < 3; i++) {
if (b[i].Surname == n) {

}
}

}*/

int main() {
	system("chcp 1251>nul");
	int size;
	cout << "Введите количество записей: ";
	cin >> size;
	while (size <= 0) {
		cout << "Введено некоректное число, введите заново: ";
		cin >> size;
	}
	Abiturient* b = new Abiturient[size];
	vvod(b, size);
	vivod(b, size);
	delet(b, size);
	vivod(b, size);
	zamena(b, size);
}