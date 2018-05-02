# include<iostream>
void merge(int a[],int be,int mi,int ed,int tmp[]){
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
	for(int i=0;i<10;i++){
		printf("%d",a[i]);
	}
	printf("\n"); 
}
void msort(int a[],int be,int ed,int tmp[]){
	int mi;
	if(be<ed){
		mi=(be+ed)/2;
		msort(a,be,mi,tmp);
		msort(a,mi+1,ed,tmp);
		merge(a,be,mi,ed,tmp);
	}
}
int main(){
	int a[10]={7,5,4,2,6,0,0,1,3,8};
	int b[10];
	msort(a,0,9,b);
	for(int i=0;i<10;i++){
		printf("%d",a[i]);
	}
}
