# include<stdio.h>
# include<math.h>
int isprime(int n){
	int i,a,f=1;
	a=sqrt(n)+1;
	for(i=2;i<a;i++){
		if(n%i==0)break;
	}
	if(i<a)f=0;
	return f;
}
int main(){
	int n,a[10000],k=1;
	a[0]=2;
	for(int i=3;i<10000;i++){
		if(isprime(i)){
			a[k]=i;
			k++;
		}
	}
	while(scanf("%d",&n)&&n!=0){
		int sum=0;
		for(int i=0;a[i]<n/2;i++){
			for(int j=0;a[j]<=n-a[i];j++){
				if(a[i]+a[j]==n){
					sum++;
					break;
				}
			}
		}
		printf("%d\n",sum);
	}
}
