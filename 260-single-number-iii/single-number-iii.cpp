class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        if(nums.size()==2&&nums[0]!=nums[1]){
        ans.push_back(nums[0]);
        ans.push_back(nums[1]);
        return ans;
        }
        if(nums[0]!=nums[1])
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]!=nums[i-1]&&nums[i]!=nums[i+1])
            ans.push_back(nums[i]);
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2])
        ans.push_back(nums[nums.size()-1]);
        return ans;
    }
};