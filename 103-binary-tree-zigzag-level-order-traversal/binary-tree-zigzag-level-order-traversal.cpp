/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr)
        return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        int cnt = 0;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();
                    if(front->left!=nullptr)
                    q.push(front->left); 
                    if(front->right!=nullptr)
                    q.push(front->right);
                temp.push_back(front->val);
            }
            cnt++;
            if(!(cnt&1)){
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            }
            else 
            ans.push_back(temp);
        }
        return ans;
    }
};