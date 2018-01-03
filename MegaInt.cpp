#include "MegaInt.h"
#include<iostream>

//using namespace::std;


MegaInt::MegaInt()
{

}

MegaInt & MegaInt::normalize(MegaInt &megaInt)
{
	MegaInt normalisedMegaInt;
	int count = 0;
	int i = 0;
	if (megaInt.mega_int.size() == 1) {
		return megaInt;
	}
	else {
		while (i < megaInt.mega_int.size()) {
			if (megaInt.mega_int.at(i) == '0') {
				i++;

			}
			else {
				break;
			}
		}
		if (i == megaInt.mega_int.size()) {

			megaInt.mega_int.erase(megaInt.mega_int.begin() + 1, megaInt.mega_int.end());

		}
		else {
			if (i > 0) {
				megaInt.mega_int.erase(megaInt.mega_int.begin(), megaInt.mega_int.begin() + i);
			}

		}

	}
	deque<char>::iterator it;
	it = megaInt.mega_int.begin() + count;
	normalisedMegaInt.mega_int.assign(it, megaInt.mega_int.end());
	megaInt.mega_int.assign(normalisedMegaInt.mega_int.begin(), normalisedMegaInt.mega_int.end());
	return megaInt;
}

bool operator<=(MegaInt &lhs, int val)
{
	char c = { '0' };
	int digits = 0;
	while (val) {
		val /= 10;
		digits++;
	}
	if (lhs.mega_int.size() == digits) {
		for (int i = 0; i < lhs.mega_int.size(); i++) {
			if ((lhs.mega_int[i] - int{ c }) <= val) {
				return true;
			}
			else if ((lhs.mega_int[i] - int{ c }) >= val) {
				return false;
			}
		}
	}
	else {
		return lhs.mega_int.size() < digits;
	}

}

MegaInt& operator+(MegaInt & megaInt, MegaInt & acc)
{

	MegaInt obj;
	megaInt = megaInt.normalize(megaInt);
	acc = acc.normalize(acc);
	obj.addition(megaInt, acc);
	return acc;
}

MegaInt operator-(MegaInt &megaInt, MegaInt &acc)
{
	MegaInt obj;

	megaInt = megaInt.normalize(megaInt);
	acc = acc.normalize(acc);
	obj.subtract(megaInt, acc);
	return acc;
}

MegaInt Multiply(MegaInt &megaInt, MegaInt &acc)
{

	megaInt.normalize(megaInt);
	acc.normalize(acc);

	MegaInt multiplier;
	MegaInt multiplicand;
	MegaInt one;
	MegaInt mega_k;
	one.mega_int.push_back('1');

	//Resolving sign

	if (megaInt.sign != acc.sign) {
		acc.sign = '-';
	}
	else {
		acc.sign = '+';
	}

	if (megaInt > acc) {
		multiplier = acc;
		multiplicand.mega_int.push_back('0');
		for (mega_k = one; mega_k <= multiplier; mega_k = ++mega_k) {
			megaInt += multiplicand;
		}

	}
	else {
		multiplier = megaInt;
		multiplicand.mega_int.push_back('0');
		for (mega_k = one; mega_k <= multiplier; mega_k = ++mega_k) {
			acc += multiplicand;
		}

	}

	acc = multiplicand;
	return acc;
}

MegaInt operator/(MegaInt &megInt, MegaInt &acc)
{
	MegaInt n;
	MegaInt d;
	MegaInt q;
	MegaInt qk;
	MegaInt r;
	MegaInt n1;
	MegaInt product;
	MegaInt qk1;
	MegaInt zero;
	MegaInt product1;
	MegaInt n2;
	n2 = acc;
	int dividendSize = megInt.mega_int.size();
	acc = acc.normalize(acc);
	megInt = megInt.normalize(megInt);
	d = megInt;
	n = acc;
	n1.sign = '+';
	product.sign = '+';
	n1.mega_int.assign(acc.mega_int.begin(), acc.mega_int.begin() + dividendSize);

	while (dividendSize > 0) {
		dividendSize--;
		acc.mega_int.pop_front();
	}

	qk.mega_int.push_back('0');
	q.mega_int.push_back('0');
	qk1 = qk;
	product = d*qk;
	product1 = product;
	qk = qk1;
	n = n1;
	r = n1 - product;
	product = product1;
	n1 = n;
	d = megInt;
	zero.mega_int.push_back('0');
	bool flag = false;

	if (n2 == d) {
		q.mega_int.push_back('1');
		r = zero;
	}

	while (acc.mega_int.size() > 0) {



		while (n1 < d) {
			n1.mega_int.push_back(acc.mega_int.at(0));
			acc.mega_int.pop_front();

			n1 = n1.normalize(n1);


			if (n1 < d) {
				if (acc.mega_int.size() == 0) {
					qk.mega_int.push_back('0');
					q.mega_int.push_back(qk.mega_int.at(qk.mega_int.size() - 1));
					flag = true;
					break;
				}
				else {

					n1.mega_int.push_back(acc.mega_int.at(0));
					acc.mega_int.pop_front();
					if (acc.mega_int.size() == 0) {

						int sz = n1.mega_int.size();
						while (sz > 0) {
							qk.mega_int.push_back('0');
							sz--;
							q.mega_int.push_back('0');
						}

						flag = true;
						break;
					}
					qk.mega_int.clear();
					qk.mega_int.push_back('0');
					q.mega_int.push_back('0');

				}

			}
			qk1.mega_int.clear();
			qk.mega_int.clear();
			qk1.mega_int.push_back('0');
			qk.mega_int.push_back('0');
			qk1 = qk;
			product = d*qk;
			product1 = product;
			qk = qk1;
			n1 = n1.normalize(n1);
			n = n1;
			r = n1 - product;
			product = product1;
			n1 = n;
			d = megInt;

		}
		if (flag) {
			break;
		}
		qk.mega_int.push_back('5');

		qk1 = qk;
		product = d*qk;
		product1 = product;
		qk = qk1;
		d = megInt;

		n = n1;
		r = n1 - product;
		product = product1;
		n1 = n;

		if (r == zero) {
			qk.mega_int.clear();
			qk.mega_int.push_back('5');
			q.mega_int.push_back('5');

			r = r.normalize(r);
			n1 = r;
		}
		else if (n1 > product) {

			while (r >= d) {
				qk = ++qk;
				qk1 = qk;
				product = d*qk;
				product1 = product;
				qk = qk1;
				n = n1;
				r = n1 - product;
				product = product1;
				n1 = n;
				d = megInt;
			}
			q.mega_int.push_back(qk.mega_int.at(qk.mega_int.size() - 1));

			r = r.normalize(r);
			n1 = r;
		}

		else {

			while (n1 <product) {


				qk = --qk;
				qk1 = qk;
				product = d*qk;
				product1 = product;
				qk = qk1;
				n = n1;
				if (product.sign == '+') {
					product.sign = '-';
				}
				if (n1.sign == '+') {
					n1.sign = '-';
				}

				r = product - n1;
				product = product1;
				n1 = n;
				d = megInt;

			}
			q.mega_int.push_back(qk.mega_int.at(qk.mega_int.size() - 1));
			product.sign = '+';
			n1.sign = '+';

			//n1 = r;
			r = r.normalize(r);
			n1 = r;
		}


	}
	acc.mega_int.assign(q.mega_int.begin(), q.mega_int.end());
	acc = acc.normalize(acc);

	if (megInt.sign != acc.sign) {
		acc.sign = '-';
	}
	else {
		acc.sign = '+';
	}
	return acc;
}


MegaInt operator%(MegaInt &megInt, MegaInt &acc)
{

	MegaInt n;
	MegaInt d;
	MegaInt q;
	MegaInt qk;
	MegaInt r;
	MegaInt n1;
	MegaInt product;
	MegaInt qk1;
	MegaInt zero;
	MegaInt product1;
	MegaInt n2;
	n2 = acc;
	int dividendSize = megInt.mega_int.size();
	acc = acc.normalize(acc);
	megInt = megInt.normalize(megInt);
	d = megInt;
	n = acc;
	n1.sign = '+';
	product.sign = '+';
	n1.mega_int.assign(acc.mega_int.begin(), acc.mega_int.begin() + dividendSize);
	//reduce the number of digits from n
	while (dividendSize > 0) {
		dividendSize--;
		acc.mega_int.pop_front();
	}

	//Initail values 
	qk.mega_int.push_back('0');
	q.mega_int.push_back('0');
	qk1 = qk;
	product = d*qk;
	product1 = product;
	qk = qk1;
	n = n1;
	r = n1 - product;
	product = product1;
	n1 = n;
	d = megInt;
	zero.mega_int.push_back('0');
	bool flag = false;

	if (n2 == d) {
		q.mega_int.push_back('1');
		r = zero;
	}

	while (acc.mega_int.size() > 0) {



		while (n1 < d) {
			n1.mega_int.push_back(acc.mega_int.at(0));
			acc.mega_int.pop_front();
			n1 = n1.normalize(n1);


			if (n1 < d) {
				if (acc.mega_int.size() == 0) {
					qk.mega_int.push_back('0');
					q.mega_int.push_back(qk.mega_int.at(qk.mega_int.size() - 1));
					flag = true;
					break;
				}
				else {

					n1.mega_int.push_back(acc.mega_int.at(0));
					acc.mega_int.pop_front();
					if (acc.mega_int.size() == 0) {

						int sz = n1.mega_int.size();
						while (sz > 0) {
							qk.mega_int.push_back('0');
							sz--;
							q.mega_int.push_back('0');
						}

						flag = true;
						break;
					}
					qk.mega_int.clear();
					qk.mega_int.push_back('0');
					q.mega_int.push_back('0');

				}

			}
			qk1.mega_int.clear();
			qk.mega_int.clear();
			qk1.mega_int.push_back('0');
			qk.mega_int.push_back('0');
			qk1 = qk;
			product = d*qk;
			product1 = product;
			qk = qk1;
			n1 = n1.normalize(n1);

			n = n1;
			r = n1 - product;
			product = product1;
			n1 = n;
			d = megInt;

		}
		if (flag) {
			break;
		}
		qk.mega_int.push_back('5');

		qk1 = qk;
		product = d*qk;
		product1 = product;
		qk = qk1;
		d = megInt;

		n = n1;
		r = n1 - product;
		product = product1;
		n1 = n;

		if (r == zero) {
			qk.mega_int.clear();
			qk.mega_int.push_back('5');
			q.mega_int.push_back('5');

			r = r.normalize(r);
			n1 = r;
		}
		else if (n1 > product) {

			while (r >= d) {
				qk = ++qk;
				qk1 = qk;
				product = d*qk;
				product1 = product;
				qk = qk1;
				n = n1;
				r = n1 - product;
				product = product1;
				n1 = n;
				d = megInt;
			}
			q.mega_int.push_back(qk.mega_int.at(qk.mega_int.size() - 1));
			//n1 = r;
			r = r.normalize(r);
			n1 = r;
		}

		else {

			while (n1 <product) {


				qk = --qk;
				qk1 = qk;
				product = d*qk;
				product1 = product;
				qk = qk1;
				n = n1;
				if (product.sign == '+') {
					product.sign = '-';
				}
				if (n1.sign == '+') {
					n1.sign = '-';
				}
				r = product - n1;
				product = product1;
				n1 = n;
				d = megInt;

			}
			q.mega_int.push_back(qk.mega_int.at(qk.mega_int.size() - 1));
			product.sign = '+';
			n1.sign = '+';
			r = r.normalize(r);
			n1 = r;
		}


	}

	acc.mega_int.assign(r.mega_int.begin(), r.mega_int.end());
	acc = acc.normalize(acc);
	return acc;
}

MegaInt operator*(MegaInt &megaInt, MegaInt &acc)
{
	MegaInt multiplicand;
	MegaInt temp;
	MegaInt partialSum;
	MegaInt multiplier;
	int count1 = 0;
	int count2 = 0;
	multiplier = acc;
	multiplicand.mega_int.push_back(megaInt.mega_int.at(megaInt.mega_int.size() - 1));
	megaInt.mega_int.pop_back();
	temp = Multiply(multiplicand, multiplier);
	multiplicand.mega_int.clear();
	while (megaInt.mega_int.size() > 0) {
		multiplicand.mega_int.push_back(megaInt.mega_int.at(megaInt.mega_int.size() - 1));
		multiplier = acc;
		partialSum = Multiply(multiplicand, multiplier);
		count1++;
		count2 = count1;
		while (count2 > 0) {
			partialSum.mega_int.push_back('0');
			count2--;
		}
		temp = temp + partialSum;
		megaInt.mega_int.pop_back();
		partialSum.mega_int.clear();
		multiplicand.mega_int.clear();
	}

	acc.mega_int.assign(temp.mega_int.begin(), temp.mega_int.end());
	if (megaInt.sign != acc.sign) {
		acc.sign = '-';
	}
	else {
		acc.sign = '+';
	}
	return acc;

}

ostream & operator<<(ostream & out, MegaInt &acc)
{
	for (int i = 0; i < acc.mega_int.size(); i++) {
		out << acc.mega_int[i];
	}
	return out;
}

void MegaInt::divide(MegaInt &megaInt, MegaInt &acc)
{
	megaInt = megaInt.normalize(megaInt);
	acc = acc.normalize(acc);
	MegaInt zero;
	MegaInt quotient;
	MegaInt remainder;
	zero.mega_int.push_back('0');
	char sign;
	if (megaInt.sign != acc.sign) {
		sign = '-';
	}
	else {
		sign = '+';
	}

	//n is megaint , acc is d
	do {
		if (acc == zero) {
			quotient.mega_int.push_back('0');
		}
		else if (acc > megaInt || acc == megaInt) {
			megaInt -= acc;
			quotient = ++quotient;

		}
		else {
			break;
		}


	} while (acc > zero);
	acc = quotient;
	acc.sign = sign;
}


void MegaInt::addition(MegaInt& megaInt, MegaInt& acc)
{
	megaInt = megaInt.normalize(megaInt);
	acc = acc.normalize(acc);

	MegaInt result;
	int i = 0;
	int count = 0;
	char sign;
	if (megaInt.sign == acc.sign) {
		sign = megaInt.sign;
		result = plus(megaInt, acc);
		acc.mega_int.assign(result.mega_int.begin(), result.mega_int.end());
		acc.sign = sign;
	}
	else {

		if (megaInt>acc) {
			sign = megaInt.sign;
			result = Minus(megaInt, acc);
			result = normalize(result);
			acc.mega_int.assign(result.mega_int.begin(), result.mega_int.end());
			acc.sign = sign;
		}
		else if (acc > megaInt) {
			sign = acc.sign;
			result = Minus(acc, megaInt);
			result = normalize(result);
			acc.mega_int.assign(result.mega_int.begin(), result.mega_int.end());
			acc.sign = sign;

		}
		else {
			acc.mega_int.erase(acc.mega_int.begin(), acc.mega_int.end());
			acc.mega_int.push_front('0');
			acc.sign = '+';
		}

	}
}

MegaInt& MegaInt::plus(MegaInt& megaInt, MegaInt& acc)
{
	int carry = 0;
	int temp = 0;
	char c = '0';
	int megaIntsize = megaInt.mega_int.size() - 1;
	int accSize = acc.mega_int.size() - 1;
	int resultSize = (megaIntsize > accSize ? megaIntsize : accSize) + 1;
	MegaInt result;

	while (megaIntsize >= 0 && accSize >= 0) {
		int megaintDigit = megaInt.mega_int[megaIntsize] - int{ c };
		int accDigit = acc.mega_int[accSize] - int{ c };
		temp = megaintDigit + accDigit + carry;
		result.mega_int.push_back(static_cast<char>((temp % 10) + c));
		carry = temp / 10;
		resultSize = resultSize - 1;
		accSize = accSize - 1;
		megaIntsize = megaIntsize - 1;

	}
	while (accSize >= 0) {
		int accDigit = acc.mega_int[accSize] - int{ c };
		temp = accDigit + carry;
		result.mega_int.push_back(static_cast<char>((temp % 10) + c));
		carry = temp / 10;
		resultSize = resultSize - 1;
		accSize = accSize - 1;
	}
	while (megaIntsize >= 0) {
		int megaintDigit = megaInt.mega_int[megaIntsize] - int{ c };
		temp = megaintDigit + carry;
		result.mega_int.push_back(static_cast<char>((temp % 10) + c));
		carry = temp / 10;
		resultSize = resultSize - 1;
		megaIntsize = megaIntsize - 1;
	}
	if (carry != 0) {
		result.mega_int.push_back(static_cast<char>(carry + c));
	}
	acc.mega_int.assign(result.mega_int.rbegin(), result.mega_int.rend());
	return acc;

}
void MegaInt::subtract(MegaInt &megaInt, MegaInt &acc)
{
	MegaInt result;
	int i = 0;
	int count = 0;
	char sign;
	if (megaInt.sign != acc.sign) {

		sign = acc.sign;
		result = plus(megaInt, acc);
		result = normalize(result);
		acc.mega_int.assign(result.mega_int.begin(), result.mega_int.end());
		acc.sign = sign;
	}
	else {
		if (megaInt > acc) {

			sign = megaInt.sign;
			result = Minus(megaInt, acc);
			result = normalize(result);
			acc.mega_int.assign(result.mega_int.begin(), result.mega_int.end());
			acc.sign = sign;

		}
		else if (acc > megaInt) {
			if (megaInt.sign == '-') {
				sign = '+';
			}
			else {
				sign = '-';
			}
			//sign = acc.sign;
			result = Minus(acc, megaInt);
			result = normalize(result);
			acc.mega_int.assign(result.mega_int.begin(), result.mega_int.end());
			acc.sign = sign;
		}
		else {
			acc.mega_int.erase(acc.mega_int.begin(), acc.mega_int.end());
			acc.mega_int.push_front('0');
			acc.sign = '+';
		}
	}

}

MegaInt & MegaInt::operator+=(MegaInt &megaInt)
{

	MegaInt lhs;
	lhs.mega_int.assign(this->mega_int.begin(), this->mega_int.end());
	lhs = plus(lhs, megaInt);
	return lhs;
	// TODO: insert return statement here
}

MegaInt & MegaInt::operator-=(MegaInt &megaInt)
{
	MegaInt lhs;
	lhs.mega_int.assign(this->mega_int.begin(), this->mega_int.end());
	megaInt = Minus(megaInt, lhs);
	megaInt = normalize(megaInt);
	return megaInt;

}

MegaInt & MegaInt::operator--()
{
	MegaInt one;
	MegaInt lhs;
	lhs.mega_int.assign(this->mega_int.begin(), this->mega_int.end());
	one.mega_int.push_back('1');
	one -= lhs;
	this->mega_int.assign(lhs.mega_int.begin(), lhs.mega_int.end());
	return*this;

}

MegaInt & MegaInt::operator*=(MegaInt &acc)
{
	MegaInt lhs;
	MegaInt result;
	lhs.mega_int.assign(this->mega_int.begin(), this->mega_int.end());
	result = lhs*acc;
	this->mega_int.assign(result.mega_int.begin(), result.mega_int.end());
	acc.mega_int.clear();
	return *this;

}

MegaInt & MegaInt::operator/=(MegaInt &acc)
{
	MegaInt lhs;
	MegaInt result;
	lhs.mega_int.assign(this->mega_int.begin(), this->mega_int.end());
	result = lhs / acc;
	this->mega_int.assign(result.mega_int.begin(), result.mega_int.end());
	acc.mega_int.clear();
	return *this;

}

MegaInt & MegaInt::operator%=(MegaInt &acc)
{
	MegaInt lhs;
	MegaInt result;
	lhs.mega_int.assign(this->mega_int.begin(), this->mega_int.end());
	result = lhs % acc;
	this->mega_int.assign(result.mega_int.begin(), result.mega_int.end());
	acc.mega_int.clear();
	return *this;

}

MegaInt & MegaInt::operator++()
{

	MegaInt one;
	MegaInt lhs;
	lhs.mega_int.assign(this->mega_int.begin(), this->mega_int.end());
	one.mega_int.push_back('1');
	lhs += one;
	this->mega_int.assign(one.mega_int.begin(), one.mega_int.end());
	return *this;
}

MegaInt& MegaInt::Minus(MegaInt & X, MegaInt & Y)
{
	int borrow = 0;
	int Xsize = X.mega_int.size() - 1;
	int Ysize = Y.mega_int.size() - 1;
	int resultSize = (Xsize > Ysize ? Xsize : Ysize);
	int temp = 0;
	char c = '0';
	MegaInt result;
	while (Xsize >= 0 && Ysize >= 0) {
		int Xint = X.mega_int[Xsize] - int{ c };
		int Yint = Y.mega_int[Ysize] - int{ c };
		temp = Xint - (Yint + borrow);
		borrow = 0;
		if (temp < 0) {
			borrow = 1;
			temp = temp + 10;
		}
		result.mega_int.push_back(static_cast<char>(temp + c));
		resultSize = resultSize - 1;
		Xsize = Xsize - 1;
		Ysize = Ysize - 1;
	}
	while (Xsize >= 0) {
		int Xint = X.mega_int[Xsize] - int{ c };
		temp = Xint - borrow;
		borrow = 0;
		if (temp < 0) {
			borrow = 1;
			temp = temp + 10;
		}
		result.mega_int.push_back(static_cast<char>(temp + c));
		Xsize = Xsize - 1;
		Ysize = Ysize - 1;
	}

	if (borrow == 1 || Ysize >= 0) {
		throw "X cannot be less than Y in (X-Y)";
	}
	else {
		Y.mega_int.assign(result.mega_int.rbegin(), result.mega_int.rend());
		return Y;
	}

}

bool MegaInt::operator==(MegaInt &lhs)
{
	if (this->mega_int.size() != lhs.mega_int.size()) {
		return false;
	}

	for (int k = 0; k < this->mega_int.size(); k++)
	{
		if (this->mega_int[k] != lhs.mega_int[k]) {
			return false;
		}

	}
	return true;
}

MegaInt & MegaInt::operator=(MegaInt & megInt)
{
	if (this != &megInt) {
		mega_int.clear();
		mega_int.assign(megInt.mega_int.begin(), megInt.mega_int.end());

	}
	return *this;

}

bool MegaInt::operator!=(MegaInt &lhs)
{
	return !(this->operator==(lhs));
}

bool MegaInt::operator<=(MegaInt &lhs)
{
	return (this->operator<(lhs) || this->operator==(lhs));
}

bool MegaInt::operator>=(MegaInt &lhs)
{
	return !(this->operator<(lhs));
}

char MegaInt::operator[](int i)
{
	MegaInt zero;
	zero.mega_int.push_back('0');

	if (i > 0 && i < this->mega_int.size()) {

		return this->mega_int[i];
	}
	else {
		throw "Index out bound";
	}

}
bool MegaInt::operator>(MegaInt &rhs)
{
	return !(this->operator<(rhs));
}
bool  MegaInt::operator<(MegaInt &rhs)
{
	char c = { '0' };

	if (this->mega_int.size() == rhs.mega_int.size()) {

		for (int i = 0; i < this->mega_int.size(); i++) {
			if ((this->mega_int[i] - int{ c }) < (rhs.mega_int[i] - int{ c })) {
				return true;
			}
			else if ((this->mega_int[i] - int{ c }) > (rhs.mega_int[i] - int{ c })) {
				return false;
			}
			else if ((this->mega_int[i] - int{ c }) == (rhs.mega_int[i] - int{ c })) {
				continue;
			}
		}
	}
	else {
		return this->mega_int.size() < rhs.mega_int.size();
	}
	return false;
}




