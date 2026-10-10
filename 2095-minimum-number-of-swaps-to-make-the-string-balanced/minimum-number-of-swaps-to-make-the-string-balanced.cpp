class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            char curr = s[i];
            if(curr == '[')
            st.push(curr);
            else if(!st.empty()&&st.top()=='[')
            st.pop();
            else
            st.push(curr);
        }
        //ab st mai invalid brackets hai
        int cnt1 = 0;//closing brackets
        int cnt2 = 0;//for opening brackets
        while(!st.empty()){
            if(st.top()=='[')
            cnt1++;
            else cnt2++;
            st.pop();
        }
        if(cnt1&1)
        return (cnt1+1)/2;
        return cnt1/2;
    }
    //sirf ek cnt se he kaam ho jayega kyuki number of openeing and closing brackes same hai bas even even ya odd odd ho sakte hai invalid 
    //in case of even 2 bracket k liye 1 swap chaiye 
    //in case of odd return (cnt1+1)/2
};