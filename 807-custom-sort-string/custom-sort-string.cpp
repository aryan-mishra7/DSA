class Solution {
public:
    string customSortString(string order, string s) {
        int arr1[26]={0};//order
        int arr2[26] = {0};//s
        string ans = "";
        for(int i=0;i<order.length();i++)
            arr1[order[i]-'a']++;
        for(int i=0;i<s.length();i++)
            arr2[s[i]-'a']++;
        for(int i=0;i<order.size();i++){
            if(arr1[order[i]-'a']<=arr2[order[i]-'a']&&arr1[order[i]-'a']>=1){
            for(int j = arr2[order[i]-'a'];j>0;j--){
            ans = ans + order[i];
            }
            arr2[order[i]-'a']=0;
            }
        }
        for(int i=0;i<26;i++){
            if(arr2[i]!=0){
            for(int j = arr2[i];j>0;j--)
            ans = ans + char('a'+i);
            }
        }
        return ans;
    }
};