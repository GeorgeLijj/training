#include<iostream>
using namespace std;
#include"BigInt.h"
const int len = 4;
const int maxint = 10000;
BigInt::BigInt() {

}
BigInt::~BigInt() {
	//list.~List();
}
BigInt BigInt::pluse(BigInt& rint) {
	BigInt retint;
	Node* lp = list.tail->pre;
	Node* rp = rint.list.tail->pre;
	int r = 0;
	while (lp->pre != 0 && rp->pre != 0) {
		retint.list.add((lp->coef + rp->coef + r)%maxint);
		r = (lp->coef + rp->coef+r) / maxint;
		lp = lp->pre;
		rp = rp->pre;
	}
	if (lp->pre == 0) {
		lp = rp;
	}
	while (lp->pre != 0) {
		retint.list.add((lp->coef+r)%maxint);
		r = (lp->coef + r) / maxint;
		lp = lp->pre;
	}
	return retint;
}
ostream& BigInt::display(ostream& out) {
	Node* p = list.head->next;
	while (p->next != 0) {
		out << p->coef;
		p = p->next;
	}
	out << endl;
	return out;

}
istream& BigInt::read(istream& in) {
	if (list.head->next != list.tail) {
		cerr << "非空大数不能读取新数据" << endl;
	}
	char ch;
	int x = 10;
	while (in.get(ch)) {
		int b = 0;
		if (ch == '\n') { break; }
		b = ch - '0';
		for (int i = 0; i < len-1; i++) {
			in.get(ch);
			if (ch == '\n') { break; }
			b *= x;
			b += (ch - '0');
		}
		list.add(b);
		if (ch == '\n') { break; }
	}
	return in;
}
BigInt BigInt::operator=(BigInt rint) {
	isMinus = rint.isMinus;
	list = rint.list;
	return *this;
}