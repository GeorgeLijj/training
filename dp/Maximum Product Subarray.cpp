class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums) {
        int ret=INT_MIN;
        int n=nums.size();
        int *max_=new int[n];
        int *min_=new int[n];
        max_[0]=max(nums[0],0);
        min_[0]=min(nums[0],0);
        ret=nums[0];
        for(int i=1;i<n;i++){
            max_[i]=max(max_[i-1]*nums[i],min_[i-1]*nums[i]);
            max_[i]=max(max_[i],nums[i]);
            ret=max(max_[i],ret);
            min_[i]=min(max_[i-1]*nums[i],min_[i-1]*nums[i]);
            min_[i]=min(min_[i],nums[i]);
        }
        return ret;
    }
};
