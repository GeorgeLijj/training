#pragma once
class Node {
	public:
		int coef=0;
		Node* next;
		Node* pre;
		Node(int coef, Node* next,Node* pre)
		{
			this->coef = coef;
			this->next = next;
			this->pre = pre;
		}
		Node(Node* ptr) {
			this->coef = ptr->coef;
			this->next = ptr->next;
			this->pre = ptr->pre;
		}
};
class List
{
public:
	List();
	~List();
	void add(int);
	void clear();
	List operator=(List&);
	Node* head;//首指针指向头节点
	Node* tail;
};
