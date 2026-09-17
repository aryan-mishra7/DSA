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
ListNode* reverse(ListNode* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* forward = NULL;
    while(curr!=nullptr){
        forward = curr->next;
        curr->next = prev;
        prev= curr;
        curr = forward;
    }
    return prev;
}
public:
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        int carry = 0;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr!=nullptr){
            int ans = curr->val*2+carry;
            int digit = ans%10;
             carry = ans/10;
            curr->val = digit;
            prev = curr;
            curr = curr->next;
        }
        if(carry!=0){
        ListNode* one = new ListNode(carry);
            prev->next = one;}
        head = reverse(head);
        return head;
    }
};