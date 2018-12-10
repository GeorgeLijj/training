#include<iostream>
#include"Poly.h"
using namespace std;
int main() {
	Poly bi1, bi2,bi3;
	bi1.read();
	bi1.show();
	bi2.read();
	bi2.show();
	bi3 = bi1.mult(bi2);
	bi3.show();
	system("pause");
}