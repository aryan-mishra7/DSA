class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> temp;
        temp.push_back(-1);
        temp.push_back(-1);
        vector<int> ans;
        ListNode* curr = head->next;
        ListNode* prev = head;
        int cnt = 2;
        while(curr != nullptr && curr->next != nullptr){
            if((curr->val >prev->val&&curr->val>curr->next->val)||(curr->val<prev->val&&curr->val<curr->next->val)){
                ans.push_back(cnt);
            }
            cnt++;
            prev = curr;
            curr = curr->next;
        }
        if(ans.size()< 2)
            return temp;
        int mini = INT_MAX;
        for(int i=1;i<ans.size();i++){
            mini = min(mini,ans[i]-ans[i-1]);
        }
        int maxi = ans.back()-ans[0];
        temp[0] = mini;
        temp[1] = maxi;
        return temp;
    }
};