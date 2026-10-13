class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            nums[i] = nums[i]*nums[i];
        sort(nums.begin(),nums.end());
        long long plus = 0,minus=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(i>=(nums.size())/2)
            plus = plus + nums[i];
            else
            minus = minus + nums[i];
        }
        return plus-minus;
    }
};