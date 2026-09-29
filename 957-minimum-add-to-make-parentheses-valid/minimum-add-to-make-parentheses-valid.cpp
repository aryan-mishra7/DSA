class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int cnt = s.size();
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch=='('){
                st.push(ch);
            }
            else if(ch==')'){
                if(!st.empty()&&st.top()=='('){
                    st.pop();
                    cnt = cnt-2;
                }
            }
        }
        return cnt;
    }
};