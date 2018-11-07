#include<iostream>
#include<string>
using namespace std;
string replaceAll(string& ns,string& os,string& ms) {
	string ret=ms;
	cout << ret << endl;
	int pos=0;
	while (pos < ret.length()&&(pos = ret.find(os, pos)!=string::npos)){
		cout <<"pos="<< pos << endl;
		ret.erase(pos, os.length());
		cout <<"after erase: "<< ret << endl;
		ret.insert(pos, ns);
		cout << "after insert: "<<ret << endl;
		pos += ns.length();
	}
	return ret;
}

int main() {
	string ns = "ok";
	string os = "not ok";
	string ms = "It is not ok";
	string ret = replaceAll(ns, os, ms);
	cout << ret<<endl;
	system("pause");
}


/*
It is not ok
pos = 1
after erase : Iot ok
after insert : Iokot ok
Iokot ok
*/


/*
#include<iostream>
#include<string>
using namespace std;
string replaceAll(string& ns, string& os, string& ms) {
	string ret = ms;
	cout << ret << endl;
	int pos = 0;
	pos = ret.find(os);
	while (pos < ret.length() && (pos != string::npos)) {
		cout << pos << endl;
		ret.erase(pos, os.length());
		cout << ret << endl;
		ret.insert(pos, ns);
		cout << ret << endl;
		pos += ns.length();
		pos = ret.find(os, pos);
	}
	return ret;
}
int main() {
	string ns = "ok";
	string os = "not ok";
	string ms = "It is not ok";
	string ret = replaceAll(ns, os, ms);
	cout << ret << endl;
	cout << ret.find("ot");
	system("pause");
}
*/