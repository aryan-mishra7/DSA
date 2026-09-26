class Solution {
private:
void solve(vector<int> nums,vector<int> output,int index , vector<vector<int>>&ans){
    if(index>=nums.size()){
        ans.push_back(output);
        return;
    }

    //exclude wala part bas index ko aage badao
    solve(nums,output,index + 1,ans);

    //include wala part (output me push karo or index ko aage badao)
    output.push_back(nums[index]);
    solve(nums,output,index + 1,ans);

}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> ans;
        int index = 0;
        solve(nums,output,index ,ans);
        return ans;
    }
};