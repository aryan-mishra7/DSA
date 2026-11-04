class Solution {
public:
    int minOperations(int n) {
        if(n&1){
            int k = (n+1)/2;
            return n*(k-1)-(k-1)*(k-1);
        }
        int temp = n-1;
        int k = (temp+1)/2;
        return n*(k)-(k)*(k);
    }
};