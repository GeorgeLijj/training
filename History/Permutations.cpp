class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
     
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ret;
        int n;
        n=nums.size();
        if(n==1){
        	ret.push_back(nums);
        	return ret;
		}else{
			allper(ret,nums,0,n);
		}
		return ret;
    }

    void allper(vector<vector<int>> &ret,vector<int> &nums,int x,int n){
		if(x==n){
			ret.push_back(nums);
			return;
		}
		for(int i=x;i<n;i++){
			swap(nums[x],nums[i]);
			allper(ret,nums,x+1,n);
			swap(nums[x],nums[i]);
		}
	}
};
