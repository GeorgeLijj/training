class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &numbers) {
         vector<vector<int>> ret;
         vector<int> a;
        int n=numbers.size(),k;
        int p,q,m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++){
                if(numbers[j]<numbers[n-i-1]){
                    int tmp;
                    tmp=numbers[j];
                    numbers[j]=numbers[n-i-1];
                    numbers[n-i-1]=tmp;
                }
            }
        }
        int f=1;
        for(int i=n-1;i>=0;i--){
            if(numbers[i]==0&&(i-2>=0)&&f){
                if((numbers[i-1]==0)&&(numbers[i-2]==0)){
                    a.push_back(0);
                    a.push_back(0);
                    a.push_back(0);
                    ret.push_back(a);
                    f=0;
                }
            }
            if(numbers[i]>0){  //m是最后的正数
                m=i;
                break;
            }
        
        }
        
        if(numbers[n-1]>=0)return ret;
        if(numbers[0]<=0)return ret;
        for(int i=m;i>=1;i--){
            k=m+1;
            for(int j=i-1;j>=0;j--){
                if(j<0)break;
                for(k=k;k<n;k++){
                    if(-numbers[k]==(numbers[i]+numbers[j])){
                        a.clear();
                        a.push_back(numbers[k]);
                        a.push_back(numbers[i]);
                        a.push_back(numbers[j]);
                        ret.push_back(a);
                        a.clear();
                        break;
                    }
                    if(-numbers[k]>(numbers[i]+numbers[j])){
                        k--;
                        break;
                    }
                }
                while(j!=0&&numbers[j]==numbers[j-1])j--;
            }
            while(i!=1&&numbers[i]==numbers[i-1])i--;
        }
//==============================================================================

        for(int i=m+1;i<n-1;i++){
            k=m;
            for(int j=i+1;j<n;j++){
                if(j==n)break;
                for(k=k;k>=0;k--){
                    if(-numbers[k]==(numbers[i]+numbers[j])){
                        a.clear();
                        a.push_back(numbers[j]);
                        a.push_back(numbers[i]);
                        a.push_back(numbers[k]);
                        ret.push_back(a);
                        a.clear();
                        break;
                    }
                    if(-numbers[k]<(numbers[i]+numbers[j])){
                        k++;
                        break;
                    }
                }
                while(j!=n&&numbers[j]==numbers[j+1])j++;
            }
            while(i!=(n-1)&&numbers[i]==numbers[i+1])i++;
        }
        return ret;
    }
};
