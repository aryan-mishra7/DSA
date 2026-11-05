class Solution {
public:
    string customSortString(string order, string s) {
        int arr[26] = {0};//s
        string ans = "";
        for(int i=0;i<s.length();i++)
            arr[s[i]-'a']++;
        for(int i=0;i<order.size();i++){
            if(arr[order[i]-'a']>0){
            for(int j = arr[order[i]-'a'];j>0;j--){
            ans = ans + order[i];
            }
            arr[order[i]-'a']=0;
            }
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=0){
            for(int j = arr[i];j>0;j--)
            ans = ans + char('a'+i);
            }
        }
        return ans;
    }
};
/*my approach is to add (common words in both string + extra words in s) to the ans*/
/*Remember:
when you encounter a character in order , you need to add all its occurrences present in s , not just one.*/