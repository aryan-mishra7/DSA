class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> ans;
        for(int i=0;i<matrix.size()*matrix.size();i++){
            int row = i/matrix.size();
            int col = i%matrix.size();
            ans.push_back(matrix[row][col]);
        }
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};