# include<stdio.h>
# include<math.h>
int jud(int a,int cout){
	int ret=0;
	a=(a-1)*2;
	cout--;
	if(cout>0)a=jud(a,cout);
	ret=a;
	return ret;
}
int main(){
	int n,a,b;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			printf("%d\n",jud(3,a));
		}
	
	}
}
