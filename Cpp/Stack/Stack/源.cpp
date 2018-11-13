#include<iostream>
#include<stack>
using namespace std;
void translate();
void calculate();
int main() {
	calculate();
	getchar();
}
void translate() {
	stack<char> s;
	char ch;
	double num;
	while( cin>>ch) {
		if (isdigit(ch)) {
			cin.putback(ch);
			cin >> num;
			cout << num;
		}
		else {
			switch (ch)
			{
			case '+':
			case '-':
				if (s.empty() || (s.top() != '*'&&s.top() != '/')) {
					s.push(ch);
				}
				else {
					cout << s.top();
					s.pop();
					s.push(ch);
				}
				break;
			case '*':
			case '/':
				s.push(ch);
				break;
			case '(':
				s.push(ch);
				break;
			case ')':
				while (s.top() != '(') {
					cout << s.top();
					s.pop();
				}
				s.pop();
				break;
			}
		}
		
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
}
void calculate() {
	stack<double> s;
	char ch;
	double num,left,right;
	while (cin >> ch) {
		if (isdigit(ch)) {
			cin.putback(ch);
			cin >> num;
			s.push(num);
		}
		else {
			switch (ch) {
			case '+':
				left = s.top();
				s.pop();
				right = s.top();
				s.pop();
				s.push(left + right);
				break;
			case '-':
				left = s.top();
				s.pop();
				right = s.top();
				s.pop();
				s.push(left - right);
				break;
			case '*':
				left = s.top();
				s.pop();
				right = s.top();
				s.pop();
				s.push(left * right);
				break;
			case '/':
				left = s.top();
				s.pop();
				right = s.top();
				s.pop();
				s.push(left / right);
				break;
			}
		}
	}
	cout << s.top() << endl;
	s.pop();
}