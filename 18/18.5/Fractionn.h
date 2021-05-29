#pragma once
#include "Pairrr.h"
#include<iostream>
class Fractionn :public Pairrr {

	
public:
	int cel, drob;
	Fractionn() { cel = 0, drob = 0; };
	Fractionn(int f, int s) { cel = f, drob = s; }
	Fractionn(const  Fractionn& t1) { first = t1.cel; second = t1.drob; }
	~Fractionn() {};
	void operator==(const Fractionn&);
	friend istream& operator>>(istream& in, Fractionn& t);
	friend ostream& operator<<(ostream& out, const Fractionn& t);
};