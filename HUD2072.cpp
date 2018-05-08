# include<stdio.h>
# include<string.h>
int main(){
	char c[10000][100],flag;
	int n,i=0,cunt=1;
	while(scanf("%s",&c[i])&&(c[i][0]!='#')){
		flag=getchar();
		if(flag!=' '){
			for(int j=0;j<i;j++){
				for(int k=j+1;k<=i;k++){
					if(strcmp(c[j],c[k])==0){
						cunt--;
						break;
					}
				}
			}
			printf("%d\n",cunt);
			cunt=1;
			i=0;
		}else{
		i++;
		cunt++;
		}
	}
	
} 
