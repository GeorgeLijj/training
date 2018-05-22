class MinStack {
public:
    MinStack() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
     stack<int> s,mins;
    void push(int number) {
        s.push(number);
        if(mins.empty()||mins.top()>=number){
            mins.push(number);
        }
    }

    /*
     * @return: An integer
     */
    int pop() {
        int n;
        n=s.top();
        s.pop();
        if(n==mins.top())mins.pop();
        return n;
    }

    /*
     * @return: An integer
     */
    int min() {
        return mins.top();
    }
};
