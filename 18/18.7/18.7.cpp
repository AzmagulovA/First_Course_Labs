// 18.7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Vector.h"
#include <iostream>
#include "Time.h"
using namespace std;
int main()
{//инициализация, ввод и вывод значений вектора
	Vector<float>C(3, 0);
	cin >> C;
	cout << C << endl;
	//инициализация и вывод значений вектора
	Vector <float>D(10, 1);
	cout << D << endl;
	//операция присваивания
	D = C;
	cout << D << endl;
	//доступ по индексу
	cout << C[2] << endl;
	//получение длины вектора
	cout << "size=" << C() << endl;
	Vector<int>A(5, 0);
	cin >> A;
	cout << A << endl;
	//инициализация и вывод значений вектора
	Vector <int>B(10, 1);
	cout << B << endl;
	//операция присваивания
	B = A;
	cout << B << endl;
	//доступ по индексу
	cout << A[2] << endl;
	//получение длины вектора
	cout << "size=" << A() << endl;
	//операция сложения с константой
	B = A + 10;
	cout << B << endl;

	Time  t;
	cin >> t;
	cout << t;
	Vector<Time>E(3, t);
	cin >> E;
	cout << E << endl;
	Vector <Time>F(10, t);
	cout << F << endl;
	F = E;
	cout << F << endl;
	cout << E[2] << endl;
	cout << "size=" << E() << endl;
	F = E + t;
	cout << F << endl;
	system("pause");
}