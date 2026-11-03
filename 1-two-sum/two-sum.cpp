class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            for(auto it:mp)
            if(nums[it.second]==target-nums[i])
            return {it.second,i};
            mp[nums[i]]=i;
        }
        return {};
    }
};