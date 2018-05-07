class Solution {
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> solu;
        char** Board=(char**)malloc(sizeof(char*)*n);
        for(int i=0;i<n;i++){
            Board[i]=(char*)malloc(sizeof(char)*n);
        }
        setBoard(Board,n);
        solveSolu(solu,ret,Board,0,n);
        return ret;
    }
    void setBoard(char** Board,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                Board[i][j]='.';
        }
    }
    void solveSolu(vector<string> &solu, vector<vector<string>> &ret,char** Board,int j,int n){
        for(int i=0;i<n;i++){
            if(check(Board,i,j,n)){
                Board[i][j]='Q';
                if(j==n-1){
                    solu.clear();
                    for(int k=0;k<n;k++){
                        solu.push_back(Board[k]);
                    }
                    ret.push_back(solu);
                    Board[i][j]='.';
                    return;
                }
                solveSolu(solu,ret,Board,j+1,n);
                Board[i][j]='.';
            }
        }
    }
    int check(char** Board,int i,int j,int n){
        for(int k=0;k<n;k++){
            if(Board[i][k]=='Q'||Board[k][j]=='Q')return 0;
            if((i+k<n&&j+k<n&&i+k>=0&&j+k>=0)&&Board[i+k][j+k]=='Q')return 0;
            if((i-k<n&&j+k<n&&i-k>=0&&j+k>=0)&&Board[i-k][j+k]=='Q')return 0;
            if((i+k<n&&j-k<n&&i+k>=0&&j-k>=0)&&Board[i+k][j-k]=='Q')return 0;
            if((i-k<n&&j-k<n&&i-k>=0&&j-k>=0)&&Board[i-k][j-k]=='Q')return 0;
        }
        return 1;
    }
};


















