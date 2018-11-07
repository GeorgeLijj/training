#include<iostream>
using namespace std;
class StringType {
	char* s;
	int capacity;
public:
	StringType(int,char*);
	StringType(int);
	int length();
	int getCapactiy();
	StringType& reverse();
	void clear();
	int empty();
	char at(int );
	StringType& append(StringType&);
	StringType& insert(StringType&,int pos);
	StringType& erase(int pos,int);
	StringType substr(int pos, int n);
	int compare(StringType&);
	const StringType& operator=(StringType);
	ostream& display(ostream&);

};
ostream& operator << (ostream& out, StringType& str);
