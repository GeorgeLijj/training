#include<iostream>
using namespace std;
#include"List.h"
List::List() {
	this->head= new Node(-1, NULL,NULL);//ͷ�ڵ�
	this->tail = new Node(-1,NULL,head);
	head->next = tail;
}
List::~List() {
	Node* ptr = this->head->next;
	while (ptr != NULL) {
		delete head;
		head = ptr;
		ptr = head->next;
	}
	delete head;
}
void List::add(int coef) {//��β���һ���½ڵ�
	tail->pre->next = new Node(coef,tail,tail->pre);
	tail->pre = tail->pre->next;
}
void List::clear() {
	Node* ptr = this->head->next;
	while (ptr != NULL) {
		delete head;
		head = ptr;
		ptr = head->next;
	}
	delete head;
	
	this->head= new Node(-1, NULL,NULL);//ͷ�ڵ�
	this->tail = new Node(-1,NULL,head);
	head->next = tail;
}
List List::operator=(List& rlist) {
	clear();
	Node*p = rlist.head->next;
	while (p->next != 0) {
		add(p->coef);
		p = p->next;
		cout << "h";
	}
	return *this;
}