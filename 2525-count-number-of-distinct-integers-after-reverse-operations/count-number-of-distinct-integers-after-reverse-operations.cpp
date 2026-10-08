class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int rev = 0;
            int num = nums[i];
            while(num>0){
                int digit = num%10;
                rev = rev*10+digit;
                num = num/10;
            }
            nums.push_back(rev);
        }
        sort(nums.begin(),nums.end());
        int cnt = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1])
            cnt++;
        }
        return cnt+1;
    }
};