#include <iostream>
#include <stack>
#include <vector>
#include "Vector.h"
#include "Time.h"
using namespace std;
//typedef vector<Time>Vec; 
void main()
{
	
	Vector<Time>v(3);
	v.Print();
	Time t = v.Srednee();
	cout << "\nSrednee=" << t << endl;
	v.Summa();
	v.Print();
	cout << "Add srednee" << endl;
	cout << "pos?";
	int pos;
	cin >> pos;
	v.Add(t, pos);
	v.Print();
	cout << "Max=" << v.Max() << endl;
	cout << "Delete Max:" << endl;
	v.Del();
	v.Print();
	cout << "Delenie na min" << endl;
	cout << "Min=" << v.Min() << endl;
	v.Delenie();
	v.Print();
	
}