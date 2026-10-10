class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size())
        return "0";
        stack<char> st;
        string ans = "";
        int cnt = 0;
        int cnt1 =0;//for monotonically increasing
        for(int i=0;i<num.size()-1;i++){
            if(num[i]<=num[i+1])
            cnt1++;
        }
        if(cnt1+1==num.size()){
            for(int i=0;i<=num.size()-k-1;i++)
            ans.push_back(num[i]);
            return ans;
        }

        //main logic for monotonic decreasing and random string
        for(int i=0;i<num.size();i++){
            char curr = num[i];
            if(cnt==k){
                st.push(curr);
            }
            else{
                if(st.empty())
                    st.push(curr);
                else{
                    while((!st.empty())&&curr<st.top()&&cnt<k){
                        st.pop();
                        cnt++;
                    }
                st.push(curr);
                }
            }
        }
        while(cnt<k&&!st.empty()){
            st.pop();
            cnt++;
        }

        //ans mai dal do
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        int s = 0;
        int e = ans.size()-1;
        while(s<=e){
            swap(ans[s],ans[e]);
            s++;
            e--;
        }
          while(ans.size()>0&&ans[0]=='0')
                ans.erase(0,1);
        if(ans.empty())
        return "0";
        return ans;

    }
};