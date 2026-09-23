class Solution {
public:
    bool detectCapitalUse(string word) {
        int capital = 0;
        int first = 0;
        if(word[0]>=65&&word[0]<=90)
        first = 1;
        for(int i=0;i<word.length();i++){
            if(word[i]>=65&&word[i]<=90)
            capital++;
        }
        return (first==1&&capital==1) || (capital == word.length()) || (capital==0);
    }
};