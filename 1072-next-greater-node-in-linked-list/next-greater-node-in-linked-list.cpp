/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        vector<int> temp;
        ListNode* curr = head;
        while(curr!=nullptr){
            temp.push_back(curr->val);
            curr = curr->next;
        }
        vector<int> ans(temp.size());
        for(int i=temp.size()-1;i>=0;i--){
            int curr = temp[i];
            while(!st.empty()&&st.top()<=curr)
            st.pop();
            ans[i]=(st.empty())?0:st.top();
            st.push(curr);
        }
        return ans;
    }
};