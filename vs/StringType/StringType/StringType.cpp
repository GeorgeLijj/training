#include<iostream>
#include"StringType.h"
using namespace std;
const StringType& StringType::operator=(StringType str) {
	int len=str.length();
	if (len > capacity) {
		cerr << "out of capacity" << endl;
		return *this;
	}
	for (int i = 0; i < len; i++) {
		s[i] = str.s[i];
	}
	return *this;
}
StringType StringType::substr(int pos, int len) {
	StringType tmps(len+1);
	//if (pos > length()) {
	//	cerr << "illegal pos" << endl;
	//}
	int i = 0;
	for (i = 0;i<len||i+pos<=length(); i++) {
			tmps.s[0] = s[pos + i];
	}
	tmps.s[i] = '\0';
	return tmps;
}
StringType& StringType::insert(StringType& str, int pos) {
	int begin = (length());
	int len=str.length();
	if (pos > length()) {
		cerr << "illegal pos" << endl;
		return *this;
	}
	StringType tmps(length());
	tmps = substr(pos, length() - pos);
	s[pos] = '\0';
	append(str);
	append(tmps);
	return *this;
}
StringType::StringType(int capacity, char* s) {
	this->s = new char[capacity];
	if (s!=NULL) {
		int i;
		for (i=0; s[i] != '\0'; i++) {
			this->s[i] = s[i];
		}
		this->s[i] = '\0';
	}
}
StringType::StringType(int capacity) {
	s = new char[capacity];
	s[0] = '\0';
}
int StringType::length() {
	int i = 0;
	for (; s[i] != '\0'; i++) {
	}
	return i;
}
int StringType::getCapactiy() {
	return capacity;
}
StringType& StringType::reverse() {
	char tmp;
	int len = length();
	for (int i = 0; i < len / 2; i++) {
		tmp = s[i];
		s[i] = s[len - i];
		s[len - i] = tmp;
	}
	return *this;
}
void StringType::clear() {
	s[0] = '\0';
}
int StringType::empty() {
	if (s[0] == '\0') {
		return 1;
	}
	else {
		return 0;
	}
}
char StringType::at(int i) {
	if (i >= (length())) {
		cerr << "out of range" << endl;
		return '\0';
	}
	else {
		return s[i];
	}
}
StringType& StringType::append(StringType& str) {
	int begin = (length());
	int len=str.length();
	if (capacity < begin + len + 1) {
		cerr << "out of capacity" << endl;
		return *this;
	}
	for (int i = 0; i <= len; i++) {
		s[begin + i] = str.s[i];
	}
	return *this;
}
StringType& StringType::erase(int pos, int len) {
	StringType tmps(length());
	if (pos > length()) {
		cerr << "illegal pos" << endl;
		return *this;
	}
	tmps = substr(pos + len, length() - pos - len);
	s[pos] = '\0';
	append(tmps);
	if (pos > length()) {
		cerr << "illegal pos" << endl;
		return *this;
	}
	return *this;
}
int StringType::compare(StringType& str) {
	if (length() > str.length()) {
		return 1;
	}
	else if (length() < str.length()) {
		return -1;
	}
	for (int i = 0; i < length(); i++) {
		if (s[i]>str.s[i]) {
			return 1;
		}
		else if (s[i]<str.s[i]) {
			return -1;
		}
	}
	return 0;
}
ostream& StringType::display(ostream& out) {
	cout << s;
	return out;
}
ostream& operator << (ostream& out, StringType& str) {
	str.display(out);
	return out;
}