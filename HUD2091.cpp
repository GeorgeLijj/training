# include<stdio.h>
# include<string.h>
int main(){
	char ch;
	int n;
	while((ch=getchar())!='@'){
		scanf("%d",&n);
		getchar();
		printf("\n");
		for(int i=n;i>1;i--){
			for(int j=0;j<i-1;j++){
				printf(" ");
				
			}
			if(i!=n){
				printf("%c",ch);
				for(int k=0;k<2*(n-i-1)+1;k++){
					printf(" ");
				}
				
			}
			printf("%c\n",ch);
		}
		for(int i=0;i<2*n-1;i++)printf("%c",ch);
		printf("\n");
		
	}
}
