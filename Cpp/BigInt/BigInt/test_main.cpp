#include<iostream>
#include<time.h>
#include"List.h"
#include"BigInt.h"
using namespace std;
void main() {
	BigInt bint1,bint2,bint3;
	bint1.read(cin);
	bint2.read(cin);
	List list1;
	clock_t start, finish;
	double totaltime;
	start = clock();
	bint1.display(cout);
	bint2.display(cout);
	int n = 10;
	//while (n--) {
		bint3 = (bint2.pluse(bint1));
	//}
	bint3.display(cout);
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;
}