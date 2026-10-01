class MinStack {
public:
        stack<long long> s;
        long long mini;
    MinStack() {
    }
    
    void push(int value) {
        // for first element:
        if(s.empty()){
        s.push(value);
        mini = value;
        }
        
        else{
            if(value<mini){
                long long val = 2LL*value-mini;
                s.push(val);
                mini = value;
            }
            else{
                s.push(value);
            }
        }      
    }
    
    void pop() {
        if(s.empty())
        return ;
        long long curr = s.top();
        s.pop();
            if(curr>=mini){
                return ;
            }
            else{
                long long prevmini = mini;
                long long val = 2LL*mini-curr;
                mini = val;
                return ;
            }
    }
    
    int top() {
        if(s.empty())
        return -1;
        long long curr = s.top();
        if(curr<mini)
        return mini;
        else 
        return curr;       
    }
    
    int getMin() {
        if(s.empty())
        return -1;
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */