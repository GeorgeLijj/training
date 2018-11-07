#include<iostream> 
using namespace std;
lclass Solution {
public:
    /*
     * @param : An integer
     * @param : An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n) {
int a,ret=0,x=10,y=1,b,t=0;
	do{
		b=n%x;
		a=b/y;
		t=10*t+y/10;
		ret+=a*t;
		if(a>k)ret+=y;
		else if(a==k)ret+=b%y+1;
		x*=10;
		y*=10;
	}while(n/y>0); 
	if(k==0&&y!=10){
		ret-=y/10;
	}
	return ret;
    }
};

