#include <iostream>
#include <vector>
#include <cstdlib>
#include "Time.h"
#include <math.h>

using namespace std;
typedef vector<Time>Vec;//определяем тип для работы с вектором
//функция для формирования вектора
Vec make_vector(int n)
{
	Vec v;//пустой вектор
	for (int i = 0; i < n; i++)
	{
		int c = abs(rand() % 100 - 50);
		int b = abs(rand() % 100 - 50)+c/60;
		c = c % 60;
		
		Time a(b,c);
		v.push_back(a);//добавляем а в конец вектора
	}
	return v;//возвращаем вектор как результа работы функции
}
//функция для печати вектора
void print_vector(Vec v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
Time srednee(Vec v)
{
	Time s(0,0);
	//перебор вектора
	for (int i = 0; i < v.size(); i++)
		s=s + v[i];
	int n = v.size();//количество элементов в векторе
	
	Time c= s / n;
	return c;
	
}
void add_vector(Vec& v, Time& el, int pos)
{
	//добавляем на место pos элемент el
	v.insert(v.begin() + pos, el);
}
int mini(Vec v)
{
	Time m = v[0];//максимального элемент
		int r = 0;//номер максимального элемента
	for (int i = 0; i < v.size(); i++)//перебор вектора
		if (m > v[i])
		{
			m = v[i];//максимальный элемент
			r = i;//номер максимального
		}
	return r;
}
int max(Vec v)
{
	Time m = v[0];//минимальный элемент
		int n = 0;//номер минимального элемента
	for (int i = 0; i < v.size(); i++)//перебор вектора
		if (m < v[i])
		{
			m = v[i];//минимальный элемент
			n = i;//номер минимального
		}
	return n;
}
void delenie(Vec& v)
{
	int m = mini(v);
	
	Time c = v[m];
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] / c;
}
//удалить элемент из позиции pos
void del_vector(Vec& v, int pos)
{
	v.erase(v.begin() + pos);
}
//основная функция
void main()
{
	try
	{
		vector<Time> v;
		vector<Time>::iterator vi = v.begin();
		//формирование вектора
		int n;
		cout << "N?"; cin >> n;
		v = make_vector(n);
		print_vector(v);
		//вычисление среднего
		Time el= srednee(v);
		cout << el << endl;
		int n_min = mini(v);//найти номер максимального
		cout << n_min<< endl;
		//позиция для вставки
		cout << "pos?";
		int pos;
		cin >> pos;
		//генерируем ошибку, если позиция для вставки больше размера вектора
		if (pos > v.size())throw 1;
		//вызов функции для добавления
		add_vector(v, el, pos);
		//печать вектора
		print_vector(v);
		delenie(v);//
		print_vector(v);
	}
	catch (int)//блок обработки ошибок
	{
		cout << "error!";
	}
}