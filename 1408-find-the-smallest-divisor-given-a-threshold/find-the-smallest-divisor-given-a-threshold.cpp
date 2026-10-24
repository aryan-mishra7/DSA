class Solution {
private:
bool check(int n,vector<int> nums,int threshold){
    int sum = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]%n==0)
        sum = sum + nums[i]/n;
        else 
        sum = sum + (nums[i]/n)+1;
    }
    return sum<=threshold;
}
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = 0;
        for(int i=0;i<nums.size();i++)
        maxi = max(maxi,nums[i]);
        int s = 1;
        int e = maxi;
        int ans = 0;
        while(s<=e){
            int mid = s+ (e-s)/2;
            if(check(mid,nums,threshold)){
            ans = mid;
            e = mid-1;
            }
            else 
            s = mid+1;
        }
        return ans;
    }
};