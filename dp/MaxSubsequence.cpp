#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,num,a[100001],sum[100001],be,ed;
	while(scanf("%d",&n)!=EOF){
		for(int k=0;k<n;k++){
			cin>>num;
			for(int i=0;i<num;i++){
				cin>>a[i];
			}
			sum[0]=a[0];
			for(int j=1;j<num;j++){
				if(sum[j-1]>0){
					sum[j]=sum[j-1]+a[j];
				}else{
					sum[j]=a[j];
				}
			}
			int max=-1;
			for(int i=0;i<num;i++){
				if(sum[i]>max){
					max=sum[i];
					ed=i;
				}
			}
			for(int i=ed;i>=0;i--){
				if(sum[i]==a[i]){
					//cout<<sum[i]<<" "<<a[i]<<endl;
					be=i;
					break;
				}
			}
			cout<<"Case "<<k+1<<":"<<endl;
			cout<<max<<" "<<be+1<<" "<<ed+1<<endl;
			if(k<n-1)cout<<endl;
		}
	}
}
