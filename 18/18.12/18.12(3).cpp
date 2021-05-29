// 18.12(3).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Time.h"
#include "Container.h"
#include <iostream>
using namespace std;
void main()
{
	int n;
	cout << "N?"; cin >> n;
	Container<Time> v(n);
	v.Print();
	Time t = v.Srednee();//найти среднее арифметическое
	v.summa(t);
	v.Print();
	
	cout << "Srednee=" << t << endl;
	cout << "Add srednee" << endl;
	/*cout << "pos?";
	int pos;
	cin >> pos;//позиция для добавления*/
	
	//v.insert(make_pair(n, t));
	v.Add(n, t);//добавление
	v.Print();//печать
	cout << "Delete max: " << endl;
	v.Del();
	v.Print();
	

}