class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
            // int smalldiff;
            // int bigdiff ; 
            int ans = 0;
            int diff = INT_MAX;
            int olddiff;
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1])
            continue;
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum>target){
                    olddiff = diff;
                    diff = min(diff,sum-target);
                    if(diff<olddiff)
                    ans = sum;
                    k--;
                }
                else if(sum<target){
                    olddiff = diff;
                    diff = min(diff,target-sum);
                    if(diff<olddiff)
                    ans = sum;
                    j++;
                }
                else{
                    j++;
                    k--;
                    ans = sum;
                }
            }
        }
        return ans;
    }
};