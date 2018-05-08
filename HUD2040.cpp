# include<stdio.h>
# include<math.h>
int jud(int a){
	int ret=1;
	for(int i=2;i<=sqrt(a)+1;i++){
		if(a%i==0){
			ret+=i;
			ret+=a/i;
		}
	}
	return ret;
}
int main(){
	int n,a,b;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d %d",&a,&b);
			if(jud(a)==b && jud(b)==a){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
}
