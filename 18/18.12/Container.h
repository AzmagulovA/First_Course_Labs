
#include <iostream>
#include <map> //�������

using namespace std;
//������������������� �����
template<class T>
class Container
{
	map<int, T> v; //��������� �������
	int len; //����� �������
	
public:
	Container(void); //����������� ��� ����������
	Container(int n); //����������� � �����������
	void Print(); //������
	~Container(void); //����������
	T Srednee();
	void Add(int n, T el);
	int Max();
	void Del();
	void summa(T t);
};
//���������� �������
//����������� ��� ����������
template <class T>
Container<T>::Container() {
	len = 0;
}
//����������
template <class T>
Container<T>::~Container(void)
{
}
//����������� c �����������
template <class T>
Container<T>::Container(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v[i] = a;//�������� � � �������
	}
	len = v.size();
}
//����� ����������
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
	T s = v[0];//��������� �������� ����� � ������ ������� �������
	//������� �������
	for (int i = 1; i < v.size(); i++)s = s + v[i];
	int n = v.size();//���������� ��������� � �������
	return s / n;
}
//����������
template<class T>
void Container<T>::Add(int n, T el)
{
	v.insert(make_pair(n, el));//��������� ���� � ��������� �� � �������
}
template <class T>
int Container<T>::Max()
{
	typedef map<int, T>TMap;//���������� ��� ��� ������ �� �������
	typedef TMap::iterator it;
	it i = v.begin();//�������� ��������� �� ������ �������
	int nom = 0, k = 0;
	T m = (*i).second;//�������� ������� ��������
	while (i != v.end()) //���� ��� ����� ����������
	{
		if (m < (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;//��������
		k++;//������� ���������
	}
	return nom;//����� max
}
template <class T>
void Container<T>::Del()
{
	int max = Max();
	cout << "max=" << v[max] << " nom=" << max << endl;
	v.erase(max);//������� ������������ �������
}
template <class T>
void Container<T>::summa(T t) {
	//typedef map<int, T>TMap;//���������� ��� ��� ������ �� �������
	//typedef TMap::iterator it;
	//it i = v.begin();//�������� ��������� �� ������ �������
	
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + t; 
	
}