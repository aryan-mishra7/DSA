class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st1;//popped;
        stack<int> st2;//pushed;
        for(int i=popped.size()-1;i>=0;i--){
            st1.push(popped[i]);
        }
        for(int i=0;i<pushed.size();i++){
            st2.push(pushed[i]);
            while((!st1.empty()&&!st2.empty())&&st2.top()==st1.top()){
            st1.pop();
            st2.pop();
            }
        }
        while(!st1.empty()){
            if(st1.top()!=st2.top())
            return false;
            else{
                st1.pop();
                st2.pop();
            }
        }
        return st1.empty()&&st2.empty();
    }
};