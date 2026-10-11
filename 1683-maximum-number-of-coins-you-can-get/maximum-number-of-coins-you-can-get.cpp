class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n = piles.size(), b = (n/3)-1, y =n-2,sum=0;
        while(y>b){
            sum = sum + piles[y];
            y = y-2;
        }
        return sum;
    }
};