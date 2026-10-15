class Solution {
public:
    string removeDuplicateLetters(string s) {
        int arr[26]={0};
        string ans = "";
        for(int i=0;i<s.length();i++){
            int num = s[i]-'a';
            arr[num]++;
        }
        stack<char> st;
        int visited[26]={0};
        for(int i=0;i<s.length();i++){
            char curr = s[i];
            arr[curr-'a']--;                 
            if(visited[curr-'a']) 
            continue; 
            while(!st.empty()&&st.top()>curr&&arr[st.top()-'a']>0){
                visited[st.top()-'a'] = 0;
                st.pop();
            }
            st.push(curr);
            visited[curr-'a'] = 1;
        }
        while(!st.empty()&&arr[st.top()-'a']>1)
        st.pop();

        while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};