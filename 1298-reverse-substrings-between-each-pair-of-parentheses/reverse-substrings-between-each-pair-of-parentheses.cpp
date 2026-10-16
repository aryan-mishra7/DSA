class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans  = "";
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
            st.push(i);
            if(!st.empty()&&s[st.top()]=='('&&s[i]==')'){
                int start = st.top();
                int e = i;
                st.pop();
                while(start<=e){
                    swap(s[start],s[e]);
                    start++;
                    e--;
                }
            }
        }
        for(int i=0;i<s.length();i++){
            if(s[i]!='('&&s[i]!=')')
            ans.push_back(s[i]);
        }
        return ans;
    }
};