class Solution {
private:
bool even(int n){
    int sum = 0;
    while(n!=0){
        int digit=n%10;
        sum = sum + digit;
        n = n/10;
    }
    if(sum%2==0)
    return true;
    return false;
}
public:
    int countEven(int num) {
        int cnt = 0;
        for(int i=2;i<=num;i++){

            if(even(i))
            cnt++;
        }
        return cnt;
    }
};