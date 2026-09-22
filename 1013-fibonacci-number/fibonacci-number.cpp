class Solution {
private:
int f(int n){
    if(n==1||n==0)
    return n;
    return f(n-1)+f(n-2);
}
public:
    int fib(int n) {
        if(n<=1)
        return n;
        return f(n-1)+f(n-2);
    }
};