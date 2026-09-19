class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        //a pointer start mai b pointer a k baad c pointer b k baad or d pointer last mai
        vector<vector<int>> ans;
        for(long long a=0;a<nums.size();a++){
            if(a >0 &&nums[a]==nums[a-1])
                continue;
            for(long long b=a+1;b<nums.size();b++){
            if(b >a+1 &&nums[b]==nums[b-1])
                continue;
                long long c = b+1;
                long long d = nums.size()-1;
                while(c<d){
                    long long sum = (long long)nums[a]+nums[b]+nums[c]+nums[d];
                    if(sum>target)
                    d--;
                   else if(sum<target)
                    c++;
                    else{
                        ans.push_back({nums[a],nums[b],nums[c],nums[d]});
                        d--;
                        c++;
                    while(c<d &&nums[c]==nums[c-1])
                    c++;                        
                    while(c<d &&nums[d]==nums[d+1])
                    d--;
                    }
                }
            }
        }
        return ans;
    }
};