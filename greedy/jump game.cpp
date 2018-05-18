class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        int max=0;
        for(int i=0;i<=max;i++){
            if(A[i]+i>max)max=A[i]+i;
            if(max>=A.size()-1)return true;
        }
        return false;
    }
};
