class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        int* a=new int[m+1];
        int* b=new int[m+1];
        for(int i=0;i<m+1;i++)a[i]=0;
        for(int i=0;i<m+1;i++)b[i]=0;
        for(int i=0;i<A.size();i++){
            if(A[i]<=m){
        	    for(int i=0;i<m+1;i++)a[i]=b[i];
                for(int j=1;j<m+1;j++){
                    if(a[j]==1&&(j+A[i]<=m)){
                    	b[j+A[i]]=1;
			    	}
                }
            b[A[i]]=1;
            }
        }
        for(int i=m;i>0;i--){
            if(b[i]==1)return i;
        }
        return 0;
    }
};
