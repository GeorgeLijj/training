#include<iostream>
#include"Fraction.h"
using namespace std;
int main() {
	Fraction f1,f2,f3,f4;
	bool flag;
	while (cin >> f1) {
		char opt;
		cin >> opt;
		switch (opt){
			case int('+') :
			case int('-') :
			case int('*') :
			case int('/') :
			case int('=') :
			case int('L') :
				cin >> f2;
				switch (opt){
					case int('+') :
						f3 = f1 + f2;
						cout << f3 << endl;
						break;
					case int('-') :
						f3 = f1 - f2;
						cout << f3 << endl;
						break;
					case int('*') :
						f3 = f1 * f2;
						cout << f3 << endl;
						break;
					case int('/') :
						f3 = f1 / f2;
						cout << f3 << endl;
						break;
					case int('=') :
						flag = f1 == f2;
						cout <<flag << endl;
						break;
					case int('L') :
						cout << f1.L(f2) << endl;
						break;
				}
			break;
			case int('I') :
				cout << f1.I()<<endl;
				break;
			case int('R') :
				cout << f1.R()<<endl;
				break;
			case int('M') :
				f1.M();
				break;
			case int('G') :
				cout << f1.G()<<endl;
				break;
			case int('<'):
				if (cin.peek() == '=') {
					cin >> opt;
					cin >> f2;
					flag = f1 <= f2;
					cout << flag << endl;
				}
				else {
					cin >> f2;
					flag = f1 < f2;
					cout << flag << endl;
				}
				break;
			case int('>'):
				if (cin.peek() == '=') {
					cin >> opt;
					cin >> f2;
					flag = f1 >= f2;
					cout << flag << endl;
				}
				else {
					cin >> f2;
					flag = f1 >f2;
					cout << flag << endl;
				}
				break;
			case int('X') :
				cin >> opt;
				cin >> f2;
				cin >> opt;
				cin >> f3;
				f4=f1.X(f2, f3);
				cout <<"X="<< f4 << endl;
				break;
		}
	}
	system("pause");
	return 0;
}