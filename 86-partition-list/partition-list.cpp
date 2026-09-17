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
void insertattail(ListNode* &head,ListNode* &tail,int d){
    if(head==nullptr){
        
    }
    ListNode* newnode = new ListNode(d);
    if(head==nullptr){
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next = newnode;
        tail = newnode;
    }
}
public:
    ListNode* partition(ListNode* head, int x) {
    if(head==nullptr||head->next==nullptr){
        return head;
    }
        //ListNode less = new ListNode(-101);
        ListNode* head1 = nullptr;
        ListNode* tail1 = nullptr;
        //ListNode more = new ListNode(101);
        ListNode* head2 = nullptr;
        ListNode* tail2 = nullptr;
        ListNode* temp = head;

        while(temp!=nullptr){
            if(temp->val<x){
                insertattail(head1,tail1,temp->val);
            }
            else{
                insertattail(head2,tail2,temp->val);
            }
            temp=temp->next;
        }
        if(head1==nullptr)
        return head2;
        
        tail1->next = head2;
        return head1;

    }
};