class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> &nums, int k) {
        int n=nums.size(),sum=INT_MIN;
        vector<vector<int>> a(k+1,vector<int>(n+1));
        vector<vector<int>> b(k+1,vector<int>(n+1));
        nums.insert(nums.begin(),0);
        for(int i=1;i<=k;i++){
            a[i][i]=a[i-1][i-1]+nums[i];
            b[i][i]=a[i][i];
            sum=b[i][i];
            for(int j=i;j<n;j++){
                if(a[i][j]<b[i-1][j]){
                    a[i][j+1]=nums[j+1]+b[i-1][j];
                }else{
                    a[i][j+1]=nums[j+1]+a[i][j];
                }
                sum=max(sum,a[i][j+1]);
                b[i][j+1]=sum;
            }
        }
        int ret=INT_MIN;
        for(int j=k;j<=n;j++){
            ret=max(ret,b[k][j]);
        }
        return ret;
    }
};
