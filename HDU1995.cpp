# include<stdio.h>
void hanoi(int n,int *a){
	if(n==0)return;
	hanoi(n-1,&a[0]);
	a[n]++;
	hanoi(n-1,&a[0]);
}
int main(){
	int f,n,x,a[10000];
	while(scanf("%d",&f)!=EOF){
		for(int i=0;i<f;i++){
			for(int j=0;j<=n;j++){
					a[j]=0;
				}
			scanf("%d %d",&n,&x);
			hanoi(n,&a[0]);
			printf("%d\n",(a[x]));
			
		}
	}
}
