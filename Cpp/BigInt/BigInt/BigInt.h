#pragma once
#include<iostream>
using namespace std;
#include"List.h"
class BigInt {
private:
	List list;
	bool isMinus = false;
public:
	BigInt();
	~BigInt();
	BigInt pluse(BigInt&);
	istream& read(istream&);
	ostream& display(ostream&);
	BigInt operator=(BigInt);
};
