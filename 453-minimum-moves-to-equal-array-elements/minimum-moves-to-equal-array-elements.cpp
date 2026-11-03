class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int first = nums[0];
        for(int i=0;i<nums.size();i++)
        ans = ans + nums[i]-first;
        return ans;
    }
};