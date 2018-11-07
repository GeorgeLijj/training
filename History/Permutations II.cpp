class Solution {
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    
    vector<vector<int>> permuteUnique(vector<int> &nums) {
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
		if(x>=n){
			ret.push_back(nums);
			return;
		}
		std::map<int,int> mymap;
		
		for(int i=x;i<n;i++){
		    if(mymap.find(nums[i])==mymap.end())
		        mymap[nums[i]]=1;
			if(mymap[nums[i]]){
			    mymap[nums[i]]=0;
				swap(nums[x],nums[i]);
				allper(ret,nums,x+1,n);
				swap(nums[x],nums[i]);
			}
			
		}
	}
};
