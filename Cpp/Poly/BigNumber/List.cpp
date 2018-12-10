#include<iostream>
#include"List.h"
using namespace std;
List::List(const List &rlist) {
	this->head= new Node(-1, NULL,NULL);//头节点
	this->tail = head;
	Node* lptr = rlist.head->next;
	while (lptr != NULL) {
		add(lptr->index, lptr->coef);
		lptr = lptr->next;
	}
}
List::List() {
	this->head= new Node(-1, NULL,NULL);//头节点
	this->tail = head;
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
void List::add(int index,int coef) {//在尾添加一个新节点
	if (coef == 0) { return; }
	tail->next = new Node(index, coef, NULL);
	tail = tail->next;
}
void List::add(Node* ptr) {
	add(ptr->index, ptr->coef);
}
void List::clear() {//清除栈内容
	this->~List();
	this->head= new Node(-1, 0, NULL);
	this->tail = head;
}
stack<int> List::show() {//返回一个倒序的栈
	stack<int> s;
	int left = -1, right = 0;
	Node* ptr = head->next;
	while (ptr != NULL) {
		right = ptr->index;
		int count = right - left;
		while (--count) {
			s.push(0);
		}
		s.push(ptr->coef);
		left = right;
		ptr = ptr->next;
	}
	return s;
}
List List::operator=(const List& llist) {
	clear();
	if (head == llist.head) { return *this; }
	Node* lptr = llist.head->next;
	while (lptr != NULL) {
		add(lptr->index, lptr->coef);
		lptr = lptr->next;
	}
	return *this;
}
List List::mult(List& rlist) {
	List sumlist;
	Node* ptr = head->next;
	while (ptr != NULL) {
		List tmp(rlist);
		Node* rp = tmp.head->next;
		while (rp != NULL) {
			rp->coef *= ptr->coef;
			rp->index += ptr->index;
			rp = rp->next;
		}
		sumlist = sumlist.plus(tmp);
		ptr = ptr->next;
	}
	return sumlist;
}
List List::plus(List& rlist) {
	List ret;
	Node*rptr = rlist.head->next;
	Node*ptr = head->next;
	int index = 0;
	int carry = 0;
	while (ptr != NULL && rptr != NULL) {
			if (rptr->index < ptr->index) {
				ret.add(rptr);
				rptr = rptr->next;
			}
			else if (rptr->index > ptr->index) {
				ret.add(ptr);
				ptr = ptr->next;
			}
			else {
				index = ptr->index;
				int sum = ptr->coef + rptr->coef;
				int coef = sum ;
				ret.add(index, coef);
				index++;
				ptr = ptr->next;
				rptr = rptr->next;
			}
	}
	if (ptr == NULL) {
		ptr = rptr;
	}
	while (ptr != NULL) {
		ret.add(ptr);
		ptr = ptr->next;
	}
	return ret;
}
