class Solution {
private:
double p(double x,int n){
    if(n==0)
    return 1;
    if(n==1)
    return x;
    double ans = p(x,n/2);
    if(n&1)
    return x* ans*ans;
    else return ans*ans;
}
public:
    double myPow(double x, int n) {
        if(n<0)
        return 1/p(x,n);
        return p(x,n);
    }
};