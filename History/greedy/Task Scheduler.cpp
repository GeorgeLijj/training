class Solution {
public:
    /**
     * @param tasks: the given char array representing tasks CPU need to do
     * @param n: the non-negative cooling interval
     * @return: the least number of intervals the CPU will take to finish all the given tasks
     */
    int leastInterval(string &task, int n) {
        const char* tasks=task.c_str();
        vector<char> c;
        int a[27]={0},j=0;
        int len=strlen(tasks);
        if(len==0)return 0;
        for(int i=0;i<len;i++){
            for(j=0;j<c.size();j++){
                if(tasks[i]==c[j]){
                    a[j]++;
                    break;
                }
                    
            }
            if(j==c.size()){
                a[j]++;
                c.push_back(tasks[i]);
            }
        }
        int s=c.size();
        sort(a,a+s);
        int ret=(a[s-1]-1)*(n+1);
        for(int i=1;i<=n&&s-i>=0;i++){
            if(a[s-1]==a[s-i])ret++;
        }
        if((a[s-1]-1)*(n+1)+1>=len)
            return ret;
        else 
            return len;
        
        
        
        
    }
};
