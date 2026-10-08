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
    if(head==nullptr||head->next==nullptr)
    return head;
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* forward = nullptr;
    while(curr!=nullptr){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
private:
void insertattail(ListNode* &head,ListNode*&tail,int val){
    ListNode* temp = new ListNode(val);
    if(head==nullptr){
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1=reverse(l1);
        ListNode* head2 = reverse(l2);
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;
        while(head1!=nullptr && head2!=nullptr){
            int sum = head1->val+head2->val+carry;
            int digit = sum%10;
            insertattail(head,tail,digit);
            carry = sum/10;
            head1 = head1->next;
            head2 = head2->next;
        }
        while(head1!=nullptr){
            int sum = head1->val + carry;
            int digit = sum%10;
            insertattail(head,tail,digit);
            carry = sum/10;
            head1 = head1->next;
        }
        while(head2!=nullptr){
            int sum = head2->val+carry;
            int digit = sum%10;
            insertattail(head,tail,digit);
            carry = sum/10;
            head2 = head2->next;
        }
        if(carry!=0){
            insertattail(head,tail,carry);
        }
        return reverse(head);
    }
};