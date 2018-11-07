class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        if(A.empty())return 0;
        int **dp=new int*[A.size()+1];
        for(int i=0;i<A.size()+1;i++)dp[i]=new int[m+1];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<A.size()+1;j++)dp[j][i]=0;
        }
        for(int i=0;i<A.size();i++){
            for(int j=0;j<m+1;j++){
                if(j<A[i])dp[i+1][j]=dp[i][j];
                else dp[i+1][j]=max(dp[i][j],dp[i][j-A[i]]+V[i]);
            }
        }
        return dp[A.size()][m];
    }
};
