
#include <iostream>
#include "Data.h"

using namespace std;


void Date::Init(int F, int S) {
	first = F;
	second = S;
}
void Date::Read() {
	first = -1;
	while (first < 0) {
		cout << "Введите положительное значение числителя: ";
		cin >> first;
	}
	second = -1;
	while (second < 0) {
		cout << "Знаменатель: ";
		cin >> second;
	}
}

int Date::Ipart() {
	int op=0;
	if (second == 0) {
		op = -1;
	}	
	else {
		op = first / second;
	}
	return op;
}
void Date::Show(int op) {
	
	if (op == -1) {
		cout << "На ноль делить нельзя" << endl;

	}
	else {
		cout << op;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	Date date;
	date.Init(5, 2);
	date.Read();	
	date.Show(date.Ipart());	
	return 0;
	system("pause");  
}
