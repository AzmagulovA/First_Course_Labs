﻿#include <iostream>
#include <map>
#include "Time.h"
using namespace std;
typedef map<int, Time>TMap;//определяем тип для работы со словаре
typedef TMap::iterator it;
//функция для формирования словаря
TMap make_map(int n)
{
	TMap m;//пустой словарь
	Time a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		//создаем пару и добавляем ее в словарь
		m.insert(make_pair(i, a));
	}
	return m;//возвращаем вектор как результа работы функции
}
//функция для печати словаря
void print_map(TMap m)
{
	for (int i = 0; i < m.size(); i++)
		cout << i << " - " << m[i] << " " << endl;
}
//вычисление среднего арифметического
Time srednee(TMap m)
{
	Time s = m[0];//первый элемент – начальное значение суммы
	//перебор словаря
	for (int i = 1; i < m.size(); i++)
		s = s + m[i];
	int n = m.size();//количество элементов в словаре
	return s / n;
}
//поиск максимального элемента
int Max(TMap v)
{
	it i = v.begin(); int nom = 0, k = 0;
	Time m = (*i).second;//значение первого элемента
	while (i != v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;//итератор
		k++;//счетчик элементов
	}
	return nom;//номер max
}
//поиск минимального элемента
int Min(TMap v)
{
	it i = v.begin(); int nom = 0, k = 0;
	Time m = (*i).second;//значение первого элемента
	while (i != v.end())
	{
		if (m > (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;//итератор
		k++;//счетчик элементов
	}
	return nom;//номер max
}
void delenie(TMap& v)
{
	Time m = v[Min(v)];
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] / m;
}
void udalenie(TMap& v)
{
it i = v.begin(); int nom = 0, k = 0;
	TMap m;
	it t=m.begin();
	Time c = v[Min(v)];
	Time e = (*i).second;//значение первого элемента
	int r = 0;
	int y=0;
	while (i != v.end())
	{
		if (e==c!=0)
		{
			m[y] = (*i).second;
			y++;
		}
		i++;//итератор		
	}
	y = 0;
	t = v.begin();
	while (i != v.end())
	{
		
			v[y] = (*t).second;
			y++;
		
		t++;//итератор		
	}
	
}
void main()
{
	int n;
	cout << "N?"; cin >> n;
	map<int, Time> m = make_map(n);
	print_map(m);
	//вычисление среднего
	Time el = srednee(m);
	cout << "srednee=" << el << endl;
	//добавление в конец
	m.insert(make_pair(n, el));
	print_map(m);
	int min = Min(m);
	//cout << "max=" << m[max] << " nom=" << max << endl;
	//m.erase(max);
	m.erase(min);
	//cout << "udalenie min: ";
	//udalenie(m);
	print_map(m);

	
	//cout << "min=" << m[min] << " nom=" << min << endl;
	//delenie(m);
	//print_map(m);
}