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
private:
void insertattail(ListNode* &head,ListNode* &tail,int val){
    ListNode* newnode = new ListNode(val);
    if(head==nullptr){
        head=newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
public:
    ListNode* removeNodes(ListNode* head) {
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
        ListNode* head1=nullptr;
        ListNode* tail1=nullptr;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==0){
                insertattail(head1,tail1,temp[i]);
            }
        }
        return head1;
    }
};
/*try to do it in 0(1) space*/
/*my solution is in 0(n) time and 0(n) space*/