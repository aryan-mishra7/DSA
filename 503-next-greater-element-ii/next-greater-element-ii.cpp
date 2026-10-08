class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        for(int i=2*n-1;i>=0;i--){
            int curr = nums[i%n];
            while(!st.empty()&&st.top()<=curr)
            st.pop();
            if(i<n){
                if(st.empty())
                nums[i%n] = -1;
                else
                nums[i%n] = st.top();
            }
            st.push(curr);
        }
        return nums;
    }
};
/*we created a hyphothetical array with double index and elements
example arr = [1,2,3,4,5] => [1,2,3,4,5,1,2,3,4,5]*/