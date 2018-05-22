class Solution {
public:
    /**
     * @param asteroids: a list of integers
     * @return: return a list of integers
     */
    vector<int> asteroidCollision(vector<int> &asteroids) {
     vector<int> ret;
     stack<int> s;
     for(int i=0;i<asteroids.size();i++){
         if(asteroids[i]<0){
             int f=1;
             while(!s.empty()&&s.top()>0){
                 
                 if(s.top()<abs(asteroids[i])){
                     s.pop();
                 }
                 else if(s.top()==abs(asteroids[i])){
                     s.pop();
                     f=0;
                     break;
                 }
                 else
                    break;
             }
             if((s.empty()||s.top()<0)&&f){
                 s.push(asteroids[i]);
             }
         }
        else
            s.push(asteroids[i]);
     }
     while(s.size()){
         ret.push_back(s.top());
         s.pop();
     }
     reverse(ret.begin(),ret.end());
     return ret;
     
    }
};
