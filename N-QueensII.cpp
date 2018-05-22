class Solution {
public:
    /**
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
      int ret=0;
        int** Board=(int**)malloc(sizeof(int*)*n);
        for(int i=0;i<n;i++){
            Board[i]=(int*)malloc(sizeof(int)*n);
        }
        setBoard(Board,n);
        solveSolu(ret,Board,0,n);
        return ret;
    }
    void setBoard(int** Board,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                Board[i][j]=0;
        }
    }
    void solveSolu(int &ret,int** Board,int j,int n){
        if(j==n){
            ret++;
            return;
        }
        for(int i=0;i<n;i++){
            if(check(Board,i,j,n)){
                Board[i][j]=1;
                solveSolu(ret,Board,j+1,n);
                Board[i][j]=0;
            }
        }
    }
    int check(int** Board,int i,int j,int n){
        for(int k=0;k<n;k++){
            if(Board[i][k]==1||Board[k][j]==1)return 0;
            if((i+k<n&&j+k<n&&i+k>=0&&j+k>=0)&&Board[i+k][j+k]==1)return 0;
            if((i-k<n&&j+k<n&&i-k>=0&&j+k>=0)&&Board[i-k][j+k]==1)return 0;
            if((i+k<n&&j-k<n&&i+k>=0&&j-k>=0)&&Board[i+k][j-k]==1)return 0;
            if((i-k<n&&j-k<n&&i-k>=0&&j-k>=0)&&Board[i-k][j-k]==1)return 0;
        }
        return 1;
    }
};
