#include<iostream>
#include"StringType.h"
using namespace std;
int main() {
	char s0[] =  "A quick brown fox jumps over a lazy dog!" ;
	cout << s0 << endl;
	StringType s1(50,s0);
	cout << s1<< endl;
	StringType s2(20);
	s2 = s1.substr(2, 6);
	cout << s2<< endl;
	s1.insert(s2, 19);
	cout << s1<< endl;
	s1.erase(2, 6);
	cout << s1<< endl;
	s1.reverse();
	cout << s1<< endl;
	s1.clear();
	cout << s1.empty()<< endl;
	system("pause");

}