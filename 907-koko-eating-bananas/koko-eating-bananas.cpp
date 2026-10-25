class Solution {
private:
bool time(int n,vector<int> &piles,int hr){
    long long cnt = 0;
    for(int i=0;i<piles.size();i++){
        if(piles[i]%n==0)
        cnt = cnt + 1LL*(piles[i]/n);
        else
        cnt = cnt + 1LL*(piles[i]/n)+1;
    }
    return cnt<=hr;
}
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for(int i=0;i<piles.size();i++)
            maxi = max(maxi,piles[i]);
        int s = 1;
        int e = maxi;
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(time(mid,piles,h)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};