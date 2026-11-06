class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.length()>s.length())
        return {};
        int l = 0;
        int r = p.length()-1;
        vector<int> pfreq(26,0);
        for(int i=0;i<p.length();i++)
            pfreq[p[i]-'a']++;
        vector<int> windowfreq(26,0);
        for(int i=l;i<=r;i++)
            windowfreq[s[i]-'a']++;

        while(r<s.size()){
            //check if windowfreq is equal to s1freq
            if(pfreq==windowfreq)
            ans.push_back(l);
            windowfreq[s[l]-'a']--;
            l++;
            r++;
            if(r<s.size())
            windowfreq[s[r]-'a']++;
        }
        return ans;
    }
};