class Solution {
public:
    int fib(int n) {
        if(n<=1)
        return n;
        int a = 0;
        int b = 1;
        int sum = a+b;
        for(int i=2;i<n;i++){
            a = b;
            b = sum;
            sum = a+b;
        }
        return sum;
    }
};
/*can also be done through recusrion but time complexity is high*/