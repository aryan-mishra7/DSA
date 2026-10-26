class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        n  = target[target.size()-1];
        vector<string> ans;
        stack<int> st;
        for(int i=0;i<target.size();i++)
        st.push(target[i]);
        while(!st.empty()){
            if(st.top()!=n){
                ans.push_back("Pop");
                ans.push_back("Push");
                n--;
            }
            else{
                ans.push_back("Push");
                n--;
                st.pop();
            }
        }
        while(n!=0){
            ans.push_back("Pop");
            ans.push_back("Push");
            n--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};