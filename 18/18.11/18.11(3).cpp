// 18.11(3).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Vector.h"
#include <cstdlib>
#include "Time.h"
#include <math.h>
using namespace std;


void main()
{
	/*Vector<Time>vec(5);//создать вектор из 5 элементов
	//печать вектора
	vec.Print();
	*/
	Vector<Time>vec(5);//создать вектор из 5 элементов
	vec.Print();//печать вектора
	Time s = vec.Srednee();//среднее ариметическое
	cout << "Srednee=" << s << endl;
	cout << "pos?";
	int p;
	cin >> p;//ввести позицию для добавления
	vec.Add(s, p);//добавить элемент в вектор
	vec.Print();//печать вектора
	Time r = vec.Max();//найти максимальный элемент
	vec.Add(r, 0);
	vec.Print();//печать
	vec.Delenie();//деление
	vec.Print();
//печать


	
}