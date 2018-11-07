#include<stdio.h>
#include<string.h>
void rev(char *s,int be,int end){
	int d;
	char t;
	while((end-be)>1){
		t=s[be];
		s[be++]=s[end];
		s[end--]=t;
		
	}
}
int main(){
	int n;
	char s[10000];
	while(scanf("%d",&n)!=EOF){
		getchar();
		while(n--){
			gets(s);
			int be=0,end=0;
			for(int i=0;i<=strlen(s)+1;i++){
				if(s[i]==' '||s[i]=='\0'){
					end=i-1;
					rev(s,be,end);
					be=i+1;
				}
				
			}
			printf("%s\n",s);
		}
		
	}
}

