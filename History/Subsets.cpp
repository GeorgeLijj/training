class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
     int N=1;
    vector<vector<int>> subsets(vector<int> nums) {
        vector<vector<int>> ret;
        vector<vector<int>> tmp;
        vector<int> a;
        int n=nums.size();
        if(n==0){
            ret.push_back(a);
            return ret;
        }
        if(N){
            for(int i=0;i<n;i++){
                for(int j=0;j<n-i;j++){
                    if(nums[j]<nums[n-i-1]){
                        int tmp;
                        tmp=nums[j];
                        nums[j]=nums[n-i-1];
                        nums[n-i-1]=tmp;
                    }
                }
            }
            N=0;
        }
        a=nums;
        a.erase(a.begin());
        tmp=subsets(a);
        for(int i=0;i<tmp.size();i++){
            ret.push_back(tmp[i]);
            tmp[i].push_back(nums[0]);
            ret.push_back(tmp[i]);
        }
        
        return ret;
    }
};
