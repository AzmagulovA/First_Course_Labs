#pragma once
#include <iostream>
#include "Object.h"
#include <string>
using namespace std;
class Pairrr :
	public Object{
public:
	Pairrr(void);
public:
	
	virtual ~Pairrr(void);
	void Show();
	
	Pairrr(int f, int s) ;
	Pairrr(const Pairrr& t1);
	int get_first() { return first; }
	int get_second() { return second; }

	void set_first(int f);
	void set_second(int s);

	
	//bool get_Pair(const Pair& t1);
	void operator==(const Pairrr&);
	Pairrr& operator=(const Pairrr&);
	friend istream& operator>>(istream& in, Pairrr& t);
	friend ostream& operator<<(ostream& out, const Pairrr& t);
	protected:
	int first, second;
	
};

