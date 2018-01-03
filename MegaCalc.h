#ifndef  MEGACALC_H
#define  MEGACALC_H
#include<iostream>
#include<string>
#include "MegaInt.h"
using namespace std;

class Megacalc {

private:
	MegaInt& parseCommand(string, MegaInt&);
	void execute(char, MegaInt);
	string input;
	void factorial(MegaInt &);
	void hailstone(MegaInt);

public:
	void run();
	MegaInt accumilator;	
};


#endif // ! MEGACALC_H

