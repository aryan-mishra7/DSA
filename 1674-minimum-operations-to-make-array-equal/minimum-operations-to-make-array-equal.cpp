class Solution {
public:
    int minOperations(int n) {
        if(n&1)
        return n*((n+1)/2-1)-((n+1)/2-1)*((n+1)/2-1);
        int temp = n-1;
        return n*((temp+1)/2)-((temp+1)/2)*((temp+1)/2);
    }
};