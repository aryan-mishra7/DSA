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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr!=nullptr) {
            ListNode* forward =curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Find the node before left
        ListNode* leftprev = nullptr;
        ListNode* leftNode = head;
        for(int i=1;i<left;i++){
            leftprev = leftNode;
            leftNode = leftNode->next;
        }
        ListNode* rightNode = leftNode;
        for(int i= left;i< right;i++){
            rightNode = rightNode->next;
        }
        // Save the part after right
        ListNode* rightnext = rightNode->next;
        // Separate the list u want to reverse from the main list
        if(leftprev!=nullptr)
            leftprev->next= nullptr;
        rightNode->next =nullptr;

        // Reverse kardo seperated list ko
        ListNode* newHead = reverse(leftNode);
        // Join with main list
        if(leftprev!=nullptr){
            leftprev->next= newHead;
        } else{
            head = newHead;
        }
        ListNode* tail =newHead;

        while(tail->next!=nullptr){
            tail = tail->next;
        }
        tail->next=rightnext;
        return head;
    }
};