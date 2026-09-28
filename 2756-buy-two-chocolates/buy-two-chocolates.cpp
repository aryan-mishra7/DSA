class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int small=INT_MAX;
        int second=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<small){
                second = small;
                small = prices[i];
            }
           else if(prices[i]<second)
            second = prices[i];
        }
        if(money-(small+second)>=0)
        return money-(small+second);
        return money;
    }
};