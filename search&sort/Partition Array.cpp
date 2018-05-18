class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        if(nums.size()==0)return 0;
        nums.insert(nums.begin(),k);
        int p=0,q=nums.size()-1;
        while(p<q){
            while(p<q){
                if(nums[p]>nums[q]){
                    swap(nums[p],nums[q]);
                    break;
                }
                q--;
            }
            while(p<q){
                if(nums[p]>=nums[q]){
                    swap(nums[p],nums[q]);
                    break;
                }
                p++;
            }
        }
        return p;
    }
};
