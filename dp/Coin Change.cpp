class Solution {
public:
    /**
     * @param coins: a list of integer
     * @param amount: a total amount of money amount
     * @return: the fewest number of coins that you need to make up
     */
    int coinChange(vector<int> &coins, int amount) {
        int **dp=new int*[coins.size()+1];
        for(int i=0;i<coins.size()+1;i++)dp[i]=new int[amount+1];
        for(int i=0;i<amount+1;i++){
            for(int j=0;j<coins.size()+1;j++){
                if(i==0)dp[j][i]=0;
                else dp[j][i]=-1;
            }
        }
        for(int i=0;i<coins.size();i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i]>j)dp[i+1][j]=dp[i][j];
                else{
                    if(dp[i][j]==-1&&dp[i+1][j-coins[i]]==-1)dp[i+1][j]=-1;
                    else if(dp[i][j]==-1&&dp[i+1][j-coins[i]]!=-1)dp[i+1][j]=dp[i+1][j-coins[i]]+1;
                    else if(dp[i][j]!=-1&&dp[i+1][j-coins[i]]==-1)dp[i+1][j]=dp[i][j];
                    else if(dp[i][j]!=-1&&dp[i+1][j-coins[i]]!=-1){
                        dp[i+1][j]=min(dp[i+1][j-coins[i]]+1,dp[i][j]);
                    }
                }
                
            }
            
        }
        return dp[coins.size()][amount];
    }
};
