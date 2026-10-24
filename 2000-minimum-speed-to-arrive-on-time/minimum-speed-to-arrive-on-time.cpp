class Solution {
private:
bool check(int n,vector<int> nums,double hr){
    double sum = 0;
    for(int i=0;i<nums.size();i++){
        if(i==nums.size()-1)
            sum =sum +(double)nums[i]/n;
        else
            sum = sum+(nums[i]+n-1)/n;
    }
    return sum<=hr;
}
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int maxi = INT_MIN;
        for(int i=0;i<dist.size();i++)
        maxi = max(maxi,dist[i]);
        int s = 1;
        int e = pow(10,9);
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(check(mid,dist,hour)){
                ans = mid;
                e = mid-1;
            }
            else 
            s = mid+1;
        }
        return ans;
    }
};