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
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        long long mod = 1e9 + 7;
        vector<int> nextsm = nse(arr);
        vector<int> prevsmeq = psee(arr);
        for(int i=0;i<arr.size();i++){
        long long left = i - prevsmeq[i];
        long long right = nextsm[i] - i;
        long long contribution = (arr[i]*left*right)%mod;
        sum = (sum+contribution)%mod;
        }
        return sum;
    }
};
/*for each element we find the index of its next smaller element and the index of its prev smaller element 
and then that element is minimum till the product of left*right subarrays*/