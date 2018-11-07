#include<iostream>
#include<string.h>
#include<algorithm> 
#include<vector>
#include <iomanip>
using namespace std;
struct Node{
	int count;
	int depth;
	char c;
	Node* Next[26];
	Node(){
		count=0;
		depth=-1;
		for(int i=0;i<26;i++){
			Next[i]=NULL;
		}
	}
};
void Wstr(char* str,Node* root,int n){
	Node* pLoc=root;
	for(int j=0;j<n;j++){
		int i=str[j]-'a';
		if(pLoc->Next[i]==NULL){
			pLoc->Next[i]=new Node;
			pLoc->Next[i]->depth=j;
			pLoc->Next[i]->c=i+'a';
		}
		pLoc=pLoc->Next[i];
	}
	pLoc->count++;
}

void Read(Node* pLoc,vector<char*> &wl,vector<int> &num,char* str){
	while(pLoc!=NULL){
		if(pLoc->depth>=0){
			str[pLoc->depth]=pLoc->c;
			if(pLoc->count!=0){
				str[pLoc->depth+1]='\0';
				char* tmp=new char[25];
				strcpy(tmp,str);
				wl.push_back(tmp);
				num.push_back(pLoc->count);
				pLoc->count=0;
			}	
		}
		for(int i=0;i<26;i++){
			Read(pLoc->Next[i],wl,num,str);
		}
		break;
	} 
}
int GetW(char* str){
	char c;
	int flag=1,len=0;
	if(scanf("%c",&c)==EOF)return 0;
	do{
		if((c<='z'&&c>='a')||(c<='Z'&&c>='A')){
			flag=0;
			if(c<='Z'&&c>='A')c=c-'A'+'a';
			str[len]=c;
			len++;
			if(len>=25)break;
		}
	}while(((scanf("%c",&c)!=EOF)&&((c<='z'&&c>='a')||(c<='Z'&&c>='A')))||flag);
	str[len]='\0';
	return len;
}
void Sort(vector<char*> &wl,vector<int> &num){
	int k=0;
	for(int i=0;i<num.size()-1;i++){
		k=i;
		for(int j=i+1;j<num.size();j++){
			if(num[j]>num[k])
				k=j;
		}
		int tmp=num[i];
		num[i]=num[k];
		num[k]=tmp;
		char* strtmp=wl[i];
		wl[i]=wl[k];
		wl[k]=strtmp;
	}
}
int main(){
	Node* root=new Node;
	vector<char*> wl;
	vector<int> num;
	if(freopen("in.txt","r",stdin)==NULL){
		cout<<"in.txt fail to open"<<endl;
	}
	char str[25]={0};
	while(GetW(str)){
		if(strlen(str)>3&&strlen(str)<=24)
		Wstr(str,root,strlen(str));	
	}
	Read(root,wl,num,str);
	for(int i=0;i<num.size();i++){
		cout.width(25);
		cout<<setiosflags(ios::left)<<wl[i];
		cout<<num[i]<<endl;
	}
	freopen("out.txt","w",stdout);
	Sort(wl,num);
	for(int i=0;i<num.size();i++){
		cout.width(25);
		cout<<setiosflags(ios::left)<<wl[i];
		cout<<num[i]<<endl;
	}
	
}
