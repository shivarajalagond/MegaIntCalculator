#include "MegaCalc.h"
#include<iostream>

void Megacalc::run()
{
	cout << "====================================" << endl;
	cout << "This is a MegaCalculator" << endl;
	cout << "====================================" << endl;

	accumilator.mega_int.push_back('0');
	accumilator.sign = '+';
	char command;


	do {
		MegaInt megaIntobject;
		cout << "Accumulator Value: ";
		cout << accumilator.sign;
		for (std::deque<char>::iterator it = accumilator.mega_int.begin(); it != accumilator.mega_int.end(); ++it) {
			cout << *it;
		}
		cout << endl;
		cout << "Enter a command : ";
		getline(cin, input);
		command = input[0];
		megaIntobject = parseCommand(input, megaIntobject);
		execute(command, megaIntobject);


	} while (command != 'q');
}

//To parse the input command to get the input and command
MegaInt& Megacalc::parseCommand(string input, MegaInt& megaIntobject)
{

	if (!isalpha(input[1]) && isdigit(input[1])) {

		for (int count = 1; count < input.length(); count++) {
			megaIntobject.mega_int.push_back(input[count]);
		}
		megaIntobject.sign = '+';
	}

	else {
		for (int count = 2; count < input.length(); count++) {

			megaIntobject.mega_int.push_back(input[count]);
		}
		megaIntobject.sign = input[1];
	}

	return megaIntobject;
}
void Megacalc::execute(char command, MegaInt megaIntobject)
{
	switch (command) {
	case 'f':
		factorial(accumilator);
		break;
	case 'h':
		hailstone(accumilator);
		break;
	case'+':
		megaIntobject + accumilator;
		break;
	case'-':megaIntobject - accumilator;
		break;
		//Multiply M2
	case'*':megaIntobject*accumilator;
		break;

		//Divison D2
	case'/':
		megaIntobject / accumilator;
		break;

	case'%':megaIntobject%accumilator;
		break;
	case'=':accumilator.mega_int.clear();
		accumilator = megaIntobject;
		if (megaIntobject.sign == '-') {
			accumilator.sign = '-';
		}
		else {
			accumilator.sign = '+';
		}
		break;

		//Multiply M1
		//case '*'
		//Multiply(megaIntobject,acc);
		//break;
	case'c':
		accumilator.mega_int.clear();
		accumilator.mega_int.push_back('0');
		accumilator.sign = '+';
		break;
		//Division  D1
		//case'/':megaIntobject.divide(megaIntobject, acc);
		//break;*/
	case'n':
		if (accumilator.sign == '-') {
			accumilator.sign = '+';
		}
		else {
			accumilator.sign = '-';
		}
		break;

	case'q':
		break;
	default:break;
	}
}
//To calculate the hailstone of the number
void Megacalc::hailstone(MegaInt accumilator)
{
	static int count = 0;
	deque<string> newdeque;
	int hailstoneNumber = atoi(&accumilator.mega_int[0]);
	newdeque.push_back(to_string(hailstoneNumber));
	do {

		if (hailstoneNumber % 2 == 0) {
			hailstoneNumber = hailstoneNumber / 2;
			newdeque.push_back(to_string(hailstoneNumber));
			count++;
		}
		else {
			hailstoneNumber = (hailstoneNumber * 3) + 1;
			newdeque.push_back(to_string(hailstoneNumber));
			count++;
		}

	} while (hailstoneNumber > 1);

	for (int i = 0; i < newdeque.size(); i++) {
		cout << "+ " << newdeque[i] << endl;
	}
	cout << " The length of hailstone h (" << newdeque[0] << ") " << " sequence : " << count + 1 << endl;
}
//TO calulate the factorial of the number and factorial for each number
void Megacalc::factorial(MegaInt &acc)
{
	MegaInt one;
	one.mega_int.push_back('1');
	MegaInt megafact;
	megafact = one;
	MegaInt zero;
	zero.mega_int.push_back('0');
	MegaInt temp;
	for (MegaInt megint_k = one; megint_k <= acc; ++megint_k) {
		temp = megint_k;
		megafact *= megint_k;
		megint_k = temp;
		cout << ++zero << "!= " << megafact << endl;
	}
}



