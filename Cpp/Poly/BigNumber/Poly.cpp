#include<iostream>
#include<stack>
#include"Poly.h"
using namespace std;
Poly::Poly(){}
Poly::Poly(const Poly& rpoly) {
	list = rpoly.list;
}
Poly::Poly(List& list) {
	this->list = list;
}
Poly::~Poly() {
}
void Poly::read() { //�Ӽ��̶������
	char digi;
	int ite = 0;
	stack<int> s;		//������λ����ջ
	while (cin >> digi) {
		if (digi == 'E') { break; }
		//if (digi != '\n') {
			s.push(int(digi));
		//}
	}
	list.clear();
	while (!s.empty()) { //��λ�ȳ�ջʵ���˵���д��
		digi = s.top();
		s.pop();
		list.add(ite, int(digi) - 48);
		ite++;
	}
}
void Poly::show() {//����Ļ�������
	stack<int> s;
	s = list.show(); //ȡ�õ���ջ
	while (!s.empty()) {
		cout << s.top()<<":";
		s.pop();
	}
	cout << endl;
}
Poly& Poly::operator=(const Poly& lbi) {
	list = lbi.list;
	return *this;
}
Poly Poly::plus(Poly& lbi) {
	List retlist=list.plus(lbi.list);
	Poly retbi(retlist);
	if (retbi.list.head == NULL) { cout << "NULL"; }
	return retbi;
}
Poly Poly::mult(Poly& rpoly) {
	List retlist = list.mult(rpoly.list);
	Poly retPoly(retlist);
	return retPoly;
}