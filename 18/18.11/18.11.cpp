﻿#include <iostream>

#include <vector>
#include <cstdlib>
using namespace std;
typedef vector<double>Vec;//определяем тип для работы с вектором
//функция для формирования вектора
Vec make_vector(int n)
{
	Vec v;//пустой вектор
	for (int i = 0; i < n; i++)
	{
		double a = (double)rand() / (double)RAND_MAX * (100 - -100) + -100;
		//int a = rand() % 100 - 50;
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
float srednee(Vec v)
{
	float s = 0;
	//перебор вектора
	for (int i = 0; i < v.size(); i++)
		s += v[i];
	int n = v.size();//количество элементов в векторе
	return s / n;
}
void add_vector(Vec& v, int el, int pos)
{
	//добавляем на место pos элемент el
	v.insert(v.begin() + pos, el);
}
int max(Vec v)
{
	int m = v[0],//минимальный элемент
		n = 0;//номер минимального элемента
	for (int i = 0; i < v.size(); i++)//перебор вектора
		if (m < v[i])
		{
			m = v[i];//максимальный элемент
			n = i;//номер максимального
		}
	return n;
}
//удалить элемент из позиции pos
void del_vector(Vec& v, int pos)
{
	v.erase(v.begin() + pos);
}
int min(Vec v)
{
	int m = v[0],//минимальный элемент
		n = 0;//номер минимального элемента
	for (int i = 0; i < v.size(); i++)//перебор вектора
		if (m > v[i])
		{
			m = v[i];//минимальный элемент
			n = i;//номер минимального
		}
	return n;
}
void delenie(Vec& v)
{
	int r = min(v);
	double a = v[r];
	for (int i = 0; i < v.size(); i++)
	{
		v[i] =  v[i]/a;
	}
}
//основная функция
void main()
{
	try
	{
		vector<double> v;
		vector<double>::iterator vi = v.begin();
		//формирование вектора
		int n;
		cout << "N?"; cin >> n;
		v = make_vector(n);
		print_vector(v);
		//вычисление среднего
		float el = srednee(v);
		cout << el;
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
		int n_max = max(v);//найти номер максимального
		cout << n_max<<endl;
		del_vector(v, n_max);//удалить элемент с этим номером
		print_vector(v);
		delenie(v);//
		print_vector(v);
	}
	catch (int)//блок обработки ошибок
	{
		cout << "error!";
	}
}