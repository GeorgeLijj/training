class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if(prices.empty())return 0;
        int min=prices[0];
        int ret=0;
        for(int i=1;i<prices.size();i++){
            if((prices[i]<prices[i-1]&&prices[i-1]>min)){
                ret+=prices[i-1]-min;
                min=prices[i];
            }else if((i==prices.size()-1&&prices[i]>min)){
                ret+=prices[i]-min;
            }
            if(prices[i]<min)min=prices[i];
        }
        return ret;
    }
};
