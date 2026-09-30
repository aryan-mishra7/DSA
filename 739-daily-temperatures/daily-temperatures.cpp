class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        temperatures.push_back(101);
        int n = temperatures.size();
        s.push(n-1);
        vector<int> ans(n);
        ans[n-1]=101;
        for(int i=n-2;i>=0;i--){
            int curr = temperatures[i];
            while(temperatures[s.top()]<=curr)//eqyal ho tab bhi pop krdo kyuki hame warmer chaiye
            s.pop();
            ans[i]=s.top();
            s.push(i);
        }
        ans.pop_back();
        n=ans.size();
        for(int i=0;i<ans.size();i++){
            if(ans[i]==n)
            ans[i]=0;
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=0)
            ans[i]=ans[i]-i;
        }
        return ans;
    }
};
/*O(n)and o(n) approach*/