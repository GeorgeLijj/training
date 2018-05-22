#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	//freopen("in.txt","r",stdin);
	int N,n;
	cin>>N;
	while(N--){
		cin>>n;
		int a[1000],time=0,i;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(i=n-1;i>=3;i-=2){
			if(2*a[0]+a[i]+a[i-1]<a[0]+2*a[1]+a[i])
				time+=2*a[0]+a[i]+a[i-1];
			else 
				time+=a[0]+2*a[1]+a[i];
		}
		if(i==2)
			time+=a[0]+a[1]+a[2];
		else
			time+=a[1];
		cout<<time<<endl;
	}
}
