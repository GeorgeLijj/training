class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: The majority number that occurs more than 1/3
     */
    int majorityNumber(vector<int> &nums) {
        map<int,int> map;
        int max=0,max_int;
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++){
            if(map.find(*it)==map.end()){
                map[*it]=1;
            }
            else{
                map[*it]+=1;
            }
            if(map[*it]>(nums.size()/3))return *it;
        }
    }
};
