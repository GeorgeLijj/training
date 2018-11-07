#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int N=15;
const int D=10;
const char defaultp=' ';
const char playerp='O';
const char computerp='X';
char Board[N][N];
char OldBoard[N][N][D];
int x,y;
typedef struct Boardepthoint {
	int direct[4];
	int score;
	int enclose[4];

} Boardepthoint;
typedef struct Node {
	int px,py;
	int score;
	struct Node *left;
	struct Node *right;
} Node;
Node root;
Boardepthoint point[N][N][2];
void InitialBoard();     //初始化棋盘 
void PrintBoard();       //打印棋盘 
void Playerturn();
void Computerturn();
void Assess(int y,int x);//计算每个点的评分 
int Judge(int side);     //判断是否达成胜利条件 
int Count(int y,int x);  //计算连续棋子数量并判断是否已经被堵截 
void Gamestart();
void Findoption(Node*previous);
int AlphaBeta(Node*previous,int depth,int alpha,int beta);
void SetBoard(char oldB[N][N][D],int depth,char curtB[N][N]);
void RevBoard(char oldB[N][N][D],int depth,char curtB[N][N]);
void CreatTree(Node*p,int depth);

int main() {
	int tryagain=1;
	CreatTree(&root,D+1) ;
	while(tryagain){
		Gamestart();
		cout<<"(1)tryagain   (0)quit"<<endl;
		cin>>tryagain;
	}

}
void Gamestart(){
	int n=5,turn=0;
	InitialBoard();
	PrintBoard();
	while(++turn<102) {  //如果超过102个回合直接结束对局 
		Playerturn();
		PrintBoard();
		Count(y,x);
		if(Judge(0)){
			cout<<"win"<<endl;
			break;
		}
		Computerturn();
		Count(y,x);
		PrintBoard();
		if(Judge(1)){
			cout<<"lose"<<endl;
			break;	
		}
	}
	if(turn>=102){
		cout<<"draw"<<endl;
	}
}
void InitialBoard() {
	for (int i = 0; i < N + 1; ++i) {
		for (int j = 0; j < N + 1; ++j) {
			Board[i][j] =defaultp;
		}
	}
}
void PrintBoard() {
	system("cls");
	cout<<"   ";
	for(int i=0; i<N; i++) {
		printf("%c ",'A'+i);
	}
	cout<<endl;
	for(int i=0; i<N; i++) {
		cout<<"  ";
		for(int k=0; k<2*N+1; k++) {
			cout<<"-";
		}
		cout<<endl;
		for(int j=0; j<N; j++) {
			if(!j)printf("%2d|",i+1);
			cout<<Board[i][j]<<"|";
		}
		cout<<endl;
	}
	cout<<"  ";
	for(int i=0; i<2*N+1; i++) {
		cout<<"-";
	}
	cout<<endl;

}
void Playerturn() {
	char c;
	while(1) {
		cout<<"Please enter the position you want to place the piece(sample:A6,G14)"<<endl;
		cin>>c>>y;
		y--;
		x=c-'A';
		if(Board[y][x]!=defaultp||(x>N-1||x<0)||(y>N-1||y<0)) {
			cout<<"error"<<endl;
		} else {
			Board[y][x]=playerp;
			break;
		}
	}
}
void Computerturn() {
	AlphaBeta(&root,0,INT_MIN,INT_MAX) ;
	RevBoard(OldBoard ,0,Board); 
	Board[y][x]=computerp;
}
void SetBoard(char oldB[N][N][D],int depth,char curtB[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
				oldB[i][j][depth]=curtB[i][j];
		}
	}
}
void RevBoard(char oldB[N][N][D],int depth,char curtB[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
				curtB[i][j]=oldB[i][j][depth];
		}
	}
}
void CreatTree(Node*p,int depth){
	if(depth==0){
		return;
	}
	p->left =(Node*)malloc(sizeof(Node)) ;
	p->right =(Node*)malloc(sizeof(Node)) ;
	CreatTree (p->left,depth-1);
	CreatTree (p->right,depth-1);
}
int AlphaBeta(Node*previous,int depth,int alpha,int beta){
	int score1,score2,ans;
	Findoption(previous);
	if(depth%2==0){
		previous->left->score=-(previous->left->score)/2;
		previous->right->score=-(previous->right->score)/2;	
	} 
	previous->left->score+=previous->score;
	previous->right->score+=previous->score;
	if(depth>=D){
		return previous->score ;
	}else{
		if(depth%2==0){
			SetBoard(OldBoard ,depth,Board);
			x=previous->left->px;
			y=previous->left->py;
			Board[y][x]=computerp; 
			ans=AlphaBeta(previous->left,depth+1,alpha,beta);
			if(alpha >ans){
				x=previous->left->px;
				y=previous->left->py;
				return alpha ;
			}else{
				alpha =ans;
			}
			RevBoard(OldBoard ,depth,Board);
			x=previous->right->px;
			y=previous->right->py;
			Board[y][x]=computerp;
			ans=AlphaBeta(previous->right,depth+1,alpha,beta);
			if(ans<alpha ){
				alpha =ans;
			}
			x=previous->right->px;
			y=previous->right->py;
			return alpha ;
		} else{
			SetBoard(OldBoard ,depth,Board);
			x=previous->left->px;
			y=previous->left->py;
			Board[y][x]=playerp; 
			ans=AlphaBeta(previous->left,depth+1,alpha,beta);
			if(beta <ans){
				x=previous->left->px;
				y=previous->left->py;
				return beta ;
			}else{
				beta =ans;
			}
			RevBoard(OldBoard ,depth,Board);
			x=previous->right->px;
			y=previous->right->py;
			Board[y][x]=playerp; 
			ans=AlphaBeta(previous->right,depth+1,alpha,beta);
			if(ans>beta ){
				beta =ans;
			}
			x=previous->right->px;
			y=previous->right->py;
			return beta ;
		}
		
	}
	
	
}
void Findoption(Node*previous){   //输入父节点指针将两个最优解写入分别写入子节点 
	int score_current,score_max=0,score_min=0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			Count(i,j);
			Assess(i,j); 
			//printf("%2d %2d %d\n",i,j,point[i][j][0].score);
			score_current=point[i][j][0].score+point[i][j][1].score;
			
			if((Board[i][j]==defaultp)&&(score_current>=score_min)) {
				if(score_current>score_max){
					score_min=score_max ;
					score_max=score_current ; 
					previous->right->px=j;
					previous->right->py=i;
				}else{
					score_min =score_current ;
					previous->left->px=j;
					previous->left->py=i;
				}
			//	cout<<y<<x<<endl;
			}
		}
	}
	//cout<<y<<x<<endl;
}
int Count(int y,int x) {       //对于某点y,x调用Board来计算连线长度并将结果写入point 
	char piece,unpiece;
	int Count=1,n=2;
	while(n--) {
		if(n==0) {
			piece=playerp;
			unpiece=computerp;
		} else {
			piece=computerp;
			unpiece=playerp;
		}
		Count=1;
		
		for (int i=0; i<5&&(x>=0&&x<N)&&(y>=0&&y<N); i++) {
			point[y][x][n].enclose[0]=0;
			point[y][x][n].enclose[0]=0;
			if(Board[y+i+1][x]==piece) {
				Count++;
			} else {
				if(Board[y+i+1][x]==unpiece||y+i+1==0||x==0){     //判断是否被堵截或到达棋盘边缘 
					point[y][x][n].enclose[0]++;
				}
				break;
			}
		}
		for (int i=0; i<5&&(x>=0&&x<N)&&(y>=0&&y<N); i++) {
			if(Board[y-i-1][x]==piece) {
				Count++;
			} else {
				if(Board[y-i-1][x]==unpiece||y-i-1==0||x==0){
					point[y][x][n].enclose[0]++;
				}
				break;
			}
		}

		point[y][x][n].direct[0]=Count;            //90度方向的连续棋子数

		Count=1;
		
		for (int i=0; i<5&&(x>=0&&x<N)&&(y>=0&&y<N); i++) {
			point[y][x][n].enclose[1]=0;
			if(Board[y][x+i+1]==piece) {
				Count++;
			} else {
				if(Board[y][x+i+1]==unpiece||y==0||x+i+1==0){
					point[y][x][n].enclose[1]++;
				}
				break;
			}
		}
		for (int i=0; i<5&&(x>=0&&x<N)&&(y>=0&&y<N); i++) {
			if(Board[y][x-i-1]==piece) {
				Count++;
			} else {
				if(Board[y][x-i-1]==unpiece||y==0||x-i-1==0){
					point[y][x][n].enclose[1]++;
				}
				break;
			}
		}
		point[y][x][n].direct[1]=Count;            //0度方向的连续棋子数
		
		Count=1;
		
		for (int i=0; i<5&&(x>=0&&x<N)&&(y>=0&&y<N); i++) {
			point[y][x][n].enclose[2]=0;
			if(Board[y+i+1][x+i+1]==piece) {
				Count++;
			} else {
				if(Board[y+i+1][x+i+1]==unpiece||y+i+1==0||x+i+1==0){
					point[y][x][n].enclose[2]++;
				}
				break;
			}
		}
		for (int i=0; i<5&&(x>=0&&x<N)&&(y>=0&&y<N); i++) {
			if(Board[y-i-1][x-i-1]==piece) {
				Count++;
			} else {
				if(Board[y-i-1][x-i-1]==unpiece||y-i-1==0||x-i-1==0){
					point[y][x][n].enclose[2]++;
				}
				break;
			}
		}

		point[y][x][n].direct[2]=Count;            //45度方向的连续棋子数

		Count=1;
		
		for (int i=0; i<5&&(x>=0&&x<N)&&(y>=0&&y<N); i++) {
			point[y][x][n].enclose[3]=0;
			if(Board[y-i-1][x+i+1]==piece) {
				Count++;
			} else {
				if(Board[y-i-1][x+i+1]==unpiece||y-i-1==0||x+i+1==0){
					point[y][x][n].enclose[3]++;
				}
				break;
			}
		}
		for (int i=0; i<5&&(x>=0&&x<N)&&(y>=0&&y<N); i++) {
			if(Board[y+i+1][x-i-1]==piece) {
				Count++;
			} else {
				if(Board[y+i+1][x-i-1]==unpiece||y+i+1==0||x-i-1==0){
					point[y][x][n].enclose[3]++;
				}
				break;
			}
		}
		point[y][x][n].direct[3]=Count;            //135度方向的连续棋子数
		Assess(y,x);
	}

}
void Assess(int y,int x) {
	int n=2,casenum;
	while(n--) {
		point[y][x][n].score=0;
		for(int i=0; i<4; i++) {
			if(point[y][x][n].direct[i]<5){   //如果连续串一侧已经被截断 降低优先级  
				casenum=point[y][x][n].direct[i]-point[y][x][n].enclose[i];  
			}else{
				casenum=point[y][x][n].direct[i];
			}
			switch(casenum) {
				case 1:
					if(n==0){
						point[y][x][n].score +=0;	
					}else{
						point[y][x][n].score +=0;	
					}
					break;
				case 2:
					if(n==0){
						point[y][x][n].score +=1;	
					}else{
						point[y][x][n].score +=2;	
					}
					break;
				case 3:
					if(n==0){
						point[y][x][n].score +=5;	
					}else{
						point[y][x][n].score +=10;	
					}
					break;
				case 4:
					if(n==0){
						point[y][x][n].score +=80;	
					}else{
						point[y][x][n].score +=400;	
					}
					break;
				case 5 :
				case 6 :
				case 7 :
				case 8 :
				case 9 :
				case 10 :	
					if(n==0){
						point[y][x][n].score +=2000;	
					}else{
						point[y][x][n].score +=10000;	
					}
			}
		}

	}
}
int Judge(int side) {
	int ret=0;
	for(int i=0; i<4; i++) {
		if(point[y][x][side].direct[i]>=5)ret=1;
	}
	return ret;
}

