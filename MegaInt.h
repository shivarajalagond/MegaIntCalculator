#ifndef  MEGAINT_H
#define  MEGAINT_H
#include<deque>
#include<iostream>
using namespace std;

class MegaInt {
private:deque<char> result;
		MegaInt& normalize(MegaInt&);
		MegaInt & operator-=(MegaInt &);
		friend bool operator<=(MegaInt&, int val);
		MegaInt & operator+=(MegaInt &);
		MegaInt& operator--();
		void addition(MegaInt &, MegaInt &);
		MegaInt& plus(MegaInt&, MegaInt&);
		MegaInt& Minus(MegaInt&, MegaInt&);
		void subtract(MegaInt&, MegaInt&);


public:
	deque<char> mega_int;
	char command;
	char sign;
	MegaInt();
	void divide(MegaInt &megaInt, MegaInt &acc);
	friend MegaInt& operator +(MegaInt&, MegaInt&);
	friend MegaInt operator -(MegaInt&, MegaInt&);
	friend MegaInt Multiply(MegaInt&, MegaInt&);
	friend MegaInt operator /(MegaInt&, MegaInt&);
	friend MegaInt operator %(MegaInt&, MegaInt&);
	friend MegaInt operator*(MegaInt&, MegaInt&);
	char operator[](int);
	bool operator<(MegaInt&);
	bool operator>(MegaInt&);
	bool operator==(MegaInt&);
	MegaInt & operator=(MegaInt & megInt);
	MegaInt& operator*=(MegaInt&);
	MegaInt& operator/=(MegaInt&);
	MegaInt& operator%=(MegaInt&);
	friend ostream& operator<<(ostream& out, MegaInt&);
	bool operator!=(MegaInt&);
	bool operator<=(MegaInt&);
	bool operator>=(MegaInt&);
	MegaInt& operator++();
	

};

#endif // ! MEGAINT_h

