class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string ans = "";
        string first = strs[0];
        string end = strs[strs.size()-1];
        int cnt = 0;
        int small = (first.length()>end.length())?end.length():first.length();
        for(int i=0;i<small;i++){
            if(first[i]==end[i])
            cnt++;
            else
            break;
        }
        for(int i=0;i<cnt;i++){
            ans = ans+first[i];
        }
        return ans;
    }
};