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
    int pairSum(ListNode* head) {
        vector<int> ans;
        ListNode* curr = head;
        while(curr!=nullptr){
            ans.push_back(curr->val);
            curr = curr->next;
        }
        int s = 0;
        int e = ans.size()-1;
        int fuck=INT_MIN;
        while(s<e){
            int sum = ans[s]+ans[e];
            if(sum>fuck)
            fuck=sum;
            s++;
            e--;
        }
        return fuck;
    }
};