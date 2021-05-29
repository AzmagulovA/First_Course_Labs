
#include <iostream>
#include <map> //словарь

using namespace std;
//параметризированный класс
template<class T>
class Container
{
	map<int, T> v; //контейнер словарь
	int len; //длина словаря
	
public:
	Container(void); //конструктор без параметров
	Container(int n); //конструктор с параметрами
	void Print(); //печать
	~Container(void); //деструктор
	T Srednee();
	void Add(int n, T el);
	int Max();
	void Del();
	void summa(T t);
};
//реализация методов
//конструктор без параметров
template <class T>
Container<T>::Container() {
	len = 0;
}
//деструктор
template <class T>
Container<T>::~Container(void)
{
}
//конструктор c параметрами
template <class T>
Container<T>::Container(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v[i] = a;//записать а в словарь
	}
	len = v.size();
}
//вывод контейнера
template <class T>
void Container<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
		cout << i << " - " << v[i] << " " << endl;
	cout << endl;
}
template<class T>
T Container<T>::Srednee()
{
	T s = v[0];//начальное значение суммы – первый элемент словаря
	//перебор словаря
	for (int i = 1; i < v.size(); i++)s = s + v[i];
	int n = v.size();//количество элементов в словаре
	return s / n;
}
//добавление
template<class T>
void Container<T>::Add(int n, T el)
{
	v.insert(make_pair(n, el));//формируем пару и добавляем ее в словарь
}
template <class T>
int Container<T>::Max()
{
	typedef map<int, T>TMap;//определяем тип для работы со словаре
	typedef TMap::iterator it;
	it i = v.begin();//итератор поставили на первый элемент
	int nom = 0, k = 0;
	T m = (*i).second;//значение первого элемента
	while (i != v.end()) //пока нет конца контейнера
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
template <class T>
void Container<T>::Del()
{
	int max = Max();
	cout << "max=" << v[max] << " nom=" << max << endl;
	v.erase(max);//удалить максимальный элемент
}
template <class T>
void Container<T>::summa(T t) {
	//typedef map<int, T>TMap;//определяем тип для работы со словаре
	//typedef TMap::iterator it;
	//it i = v.begin();//итератор поставили на первый элемент
	
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + t; 
	
}