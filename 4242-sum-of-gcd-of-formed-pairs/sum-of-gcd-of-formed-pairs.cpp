class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long ans=0;
        vector<int> arr;
        int big = nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>big)
            big = nums[i];
            arr.push_back(gcd(nums[i],big));
        }
        sort(arr.begin(),arr.end());
        int s = 0;
        int e = arr.size()-1;
        while(s<e){
            int x = gcd(arr[s],arr[e]);
            ans = ans+x;
            s++;
            e--;
        }
        return ans;
    }
};