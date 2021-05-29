#pragma once
#include <iostream>
#include "Object.h"
#include "Pairrr.h"
#include "Fractionn.h"
#include <string>
#include "Vector.h"
using namespace std;
void main() {
	setlocale(LC_ALL, "rus");
	Vector v(5);
	Pairrr e;
	cin >> e;
	Fractionn f;
	cin >> f;	
	Object* p = &e;
	v.Add(p);
	p = &f;
	v.Add(p);
	cout << v;
	Pairrr a;
	Pairrr b;
	cout << "Первая пара чисел" << endl;
	cin >> a;
	cout << "Вторая пара чисел" << endl;
	cin >> b;
	a == b;
	Fractionn c;
	Fractionn d;
	cout << "Первое число" << endl;
	cin >> c;
	cout << "Второе число" << endl;
	cin >> d;
	c == d;
	system("pause");
}
