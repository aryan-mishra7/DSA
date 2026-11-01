class Solution {
private:
vector<int> nse(vector<int> arr){
    int n = arr.size();
    stack<int> st;
    vector<int> temp(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&arr[st.top()]>=arr[i])
        st.pop();
        temp[i] = (st.empty())?n:st.top();
        st.push(i);
    }
    return temp;
}
vector<int> psee(vector<int> arr){//we take the index of prev small or equal element
    stack<int> st;
    vector<int> temp(arr.size());
    for(int i=0;i<arr.size();i++){
        while(!st.empty()&&arr[st.top()]>arr[i])
        st.pop();
        temp[i] = (st.empty())?-1:st.top();
        st.push(i);
    }
    return temp;
}
vector<int> nge(vector<int> arr){//this is next greatre element
    stack<int> st;
    vector<int> temp(arr.size());
    for(int i=arr.size()-1;i>=0;i--){
        while(!st.empty()&&arr[st.top()]<=arr[i])
        st.pop();
        temp[i] = (st.empty())?arr.size():st.top();
        st.push(i);
    }
    return temp;
}
vector<int> pgee(vector<int> arr){//this is prev greater or equal element
    stack<int> st;
    vector<int> temp(arr.size());
    for(int i=0;i<arr.size();i++){
        while(!st.empty()&&arr[st.top()]<arr[i])
        st.pop();
        temp[i] = (st.empty())?-1:st.top();
        st.push(i);
    }
    return temp;
}
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum1 = 0;
        long long sum2 = 0;
        vector<int> nextsm = nse(nums);
        vector<int> prevsmeq = psee(nums);
        vector<int> nextgre = nge(nums);
        vector<int> prevgreq = pgee(nums);
        for(int i=0;i<nums.size();i++){
        long long left = i - prevsmeq[i];
        long long right = nextsm[i] - i;
        long long contribution = nums[i]*left*right;
        sum1 = sum1+contribution;
        }
        for(int i=0;i<nums.size();i++){
            long long left = i - prevgreq[i];
            long long right = nextgre[i]-i;
            long long contribution = nums[i]*left*right;
            sum2 = sum2 + contribution;
        }
        return sum2-sum1;
    }
};