class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool search(int pos1,int pos2,string word,int len,vector<vector<char>> &board,vector<vector<int>> &b01){
        if(len==word.length())return true;
        if(pos1-1>=0&&b01[pos1-1][pos2]){
            b01[pos1-1][pos2]=0;
            if(word[len]==board[pos1-1][pos2]&&search(pos1-1,pos2,word,len+1,board,b01))return true;
            b01[pos1-1][pos2]=1;
        }
        if(pos1+1<board.size()&&b01[pos1+1][pos2]){
            b01[pos1+1][pos2]=0;
            if(word[len]==board[pos1+1][pos2]&&search(pos1+1,pos2,word,len+1,board,b01))return true;
            b01[pos1+1][pos2]=1;
        }
        if(pos2+1<board[0].size()&&b01[pos1][pos2+1]){
            b01[pos1][pos2+1]=0;
            if(word[len]==board[pos1][pos2+1]&&search(pos1,pos2+1,word,len+1,board,b01))return true;
            b01[pos1][pos2+1]=1;
        }
        if(pos2-1>=0&&b01[pos1][pos2-1]){
            b01[pos1][pos2-1]=0;
            if(word[len]==board[pos1][pos2-1]&&search(pos1,pos2-1,word,len+1,board,b01))return true;
            b01[pos1][pos2-1]=1;
        }
        return false;
        
    }
    bool exist(vector<vector<char>> &board, string &word) {
        vector<vector<int>> b01;
        vector<int> tmp;
        for(int i=0;i<board[0].size();i++){
            tmp.push_back(1);
        }
        for(int i=0;i<board.size();i++){
            b01.push_back(tmp);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                b01[i][j]=0;
                if(board[i][j]==word[0]&&search(i,j,word,1,board,b01))
                    return true;
                b01[i][j]=1;
            }
        }
        return false;
    }
};
