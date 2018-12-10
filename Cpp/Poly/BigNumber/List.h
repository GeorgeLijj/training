#pragma
#include<stack>
using namespace std;
class Node {
	public:
		int index;
		int coef=0;
		Node* next;
		Node(int index, int coef, Node* next)
		{
			this->index = index;
			this->coef = coef;
			this->next = next;
		}
		Node(Node* ptr) {
			this->index =ptr->index;
			this->coef = ptr->coef;
			this->next = ptr->next;
		}
};
class List
{
public:
	List();
	List(const List&);
	~List();
	void add(int, int);
	void add(Node*);
	void clear();
	stack<int> show();
	List operator=(const List&);
	List plus(List&);
	List mult(List&);
//private:
	Node* head;//首指针指向头节点
	Node* tail;
};
