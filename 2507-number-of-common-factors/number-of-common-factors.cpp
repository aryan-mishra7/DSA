class Solution {
public:
    int commonFactors(int a, int b) {
        int cnt = 0;
        int small = (a>b)?b:a;
        for(int i=2;i<=small;i++){
            if(a%i==0&&b%i==0)
            cnt++;
        }
        return cnt+1;
    }
};