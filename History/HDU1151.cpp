# include<stdio.h>
void merge(long a[],int be,int mi,int ed,long tmp[]){
	int pa=be,pb=mi+1,x=0;
	while(pa<=mi&&pb<=ed){
	if(a[pa]>a[pb])
		tmp[x++]=a[pb++];
	else
		tmp[x++]=a[pa++];
	}
	while(pa<=mi)tmp[x++]=a[pa++];
	while(pb<=ed)tmp[x++]=a[pb++];
	for(int i=0;i<ed-be+1;i++){
		a[i+be]=tmp[i];
	}
}
void msort(long a[],int be,int ed,long tmp[]){
	int mi;
	if(be<ed){
		mi=(be+ed)/2;
		msort(a,be,mi,tmp);
		msort(a,mi+1,ed,tmp);
		merge(a,be,mi,ed,tmp);
	}
}
int main(){
	long a[15999],b[15999],c[15999];
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		int cout=0,j=-1,la,lb;
		la=n;
		lb=m;
		while(n--)scanf("%d",&a[n]);
		while(m--)scanf("%d",&b[m]);
		msort(a,0,la-1,c);
		msort(b,0,lb-1,c);
		for(int i=0;i<lb;i++){
			while(j<la-1&&b[i]>=a[++j]){
				if(b[i]==a[j]){
					j--;
					break;
				}
			}
			if(j>=0){
				if(b[i]<a[j]||j>=la-1){
					cout++;
					j--;	
				}
				
			}
				
		}
		printf("%d\n",cout);
	}
}















