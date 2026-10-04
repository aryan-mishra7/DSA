class Solution {
private:
void solve(int index,vector<int>&sum,vector<vector<int>> &ans,vector<int>& candidates,int target){
    if(index>=candidates.size()){
        if(target==0)
        ans.push_back(sum);
        return;
    }
    //include karo
    if(target>=candidates[index]){
    sum.push_back(candidates[index]);
    solve(index,sum,ans,candidates,target-candidates[index]);
    sum.pop_back();
    }
    //exclude karo
    solve(index+1,sum,ans,candidates,target);
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sum;
        vector<vector<int>> ans;
        solve(0,sum,ans,candidates,target);
        return ans;
    }
};