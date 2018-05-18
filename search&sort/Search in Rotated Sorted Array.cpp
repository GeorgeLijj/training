class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        int ret=0;
        ret=pos(A,0,A.size()-1,target);
    }
    int pos(vector<int> &A,int be,int ed,int t){
        int ret;
        int mid=(be+ed)/2;
        if(be>ed)return -1;
        if(A[be]<=A[ed]){
            if(A[mid]==t)return mid;
            else if(A[mid]<t)ret=pos(A,mid+1,ed,t);
            else if(A[mid]>t)ret=pos(A,be,mid-1,t);
            return ret;
        }
        else{
            ret=pos(A,mid+1,ed,t);
            if(ret==-1)ret=pos(A,be,mid,t);
            return ret;
        }
    }
};
