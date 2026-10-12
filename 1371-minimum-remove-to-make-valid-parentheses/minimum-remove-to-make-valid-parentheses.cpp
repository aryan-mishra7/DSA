class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> index;
        string ans="";
        int n = s.length();
        for(int i=0;i<s.length();i++){
            if(index.empty()&&(s[i]=='('||s[i]==')'))
            index.push(i);
            else if(s[i]==')'&&s[index.top()]=='(')
            index.pop();
            else if(s[i]=='('||s[i]==')')
            index.push(i);
        }
        for(int i=n-1;i>=0;i--){
            if(!index.empty()&&i==index.top()){
            index.pop();
            continue;
            }
            else 
            ans.push_back(s[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};