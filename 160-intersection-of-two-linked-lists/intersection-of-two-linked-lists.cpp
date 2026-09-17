/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
int getlen(ListNode* head){
    int cnt=0;
    ListNode* temp=head;
    while(head!=nullptr){
        cnt++;
        head=head->next;
    }
    return cnt;
}
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena = getlen(headA);
        int lenb = getlen(headB);
        int small = (lena>=lenb)?lenb:lena;
        int big = (lena>=lenb)?lena:lenb;
        int diff = abs(lena-lenb);

        if(small==lena){
            int cnt1 = 0;
            ListNode* tempb = headB;
            ListNode* tempa = headA;
            while(cnt1<diff){
                tempb = tempb->next;
                cnt1++;
            }
            while(tempb!=tempa && tempa!=nullptr &&tempb!=nullptr){
                tempb = tempb->next;
                tempa = tempa->next;
            }
            if(tempa==nullptr || tempb==nullptr)
            return nullptr;
            return tempa;
        }
        if(small==lenb){
            int cnt1 = 0;
            ListNode* tempb = headB;
            ListNode* tempa = headA;
            while(cnt1<diff){
                tempa = tempa->next;
                cnt1++;
            }
            while(tempb!=tempa && tempa!=nullptr &&tempb!=nullptr){
                tempb = tempb->next;
                tempa = tempa->next;
            }
            if(tempa==nullptr || tempb==nullptr)
            return nullptr;
            return tempa;
        }
        return nullptr;
    }
};