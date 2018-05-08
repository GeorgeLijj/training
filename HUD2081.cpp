# include<stdio.h>
# include<string.h>
int main(){
	int n;
	char a[100];
	while(scanf("%d",&n)!=EOF){
		while(n--){
			int k=1;
			char b[100]={'6'};
			scanf("%s",a);
			for(int i=5;i>0;i--){
				b[k]=a[strlen(a)-i];
				k++;
			}
			printf("%s\n",b);
		}
	}

}
