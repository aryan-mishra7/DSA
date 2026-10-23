class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s = 0;
        int e = 2;
        while(e<nums.size()){
            if(nums[s]==nums[e]){
                while(e<nums.size()&&nums[s]==nums[e])
                    nums.erase(nums.begin()+e);
                s++;
                e++;
            }
            else{
                s++;
                e++;
            }
        }
        return nums.size();
    }
};