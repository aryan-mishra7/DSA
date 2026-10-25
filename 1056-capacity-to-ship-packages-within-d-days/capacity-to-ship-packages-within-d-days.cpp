class Solution {
private:
int check(int n,vector<int>& weights){
    int cnt = 1;
    int sum = 0;
    for(int i=0;i<weights.size();i++){
        if(sum+weights[i]>n){
            cnt++;
            sum = 0;
        }
        sum = sum + weights[i];
    }
    return cnt;
}
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int maxi = INT_MIN;
        for(int i=0;i<weights.size();i++)
        sum = sum + weights[i];
        for(int i=0;i<weights.size();i++)
        maxi = max(maxi,weights[i]);
        int s = maxi;
        int e = sum;
        int ans = e;
        while(s<=e){
            int mid = s +(e-s)/2;
            if(check(mid,weights)<=days){
                ans = mid;
                e = mid - 1;
            } 
            else
                s = mid + 1;
        }
        return ans;
    }
};