class Solution {
private:
bool even(int n){
    int cnt = 0;
    while(n>0){
        n = n/10;
        cnt++;
    }
    if(cnt%2==0)
    return true;
    return false;
}
public:
    int alternateDigitSum(int n) {
        int sum = 0;
        int cnt = 0;
        if(even(n)){
            while(n>0){
                cnt++;
                if(cnt&1)
                sum = sum-n%10;
                else
                    sum = sum+n%10;
                n=n/10;
            }
            cnt = 0;
        }
        else{
            while(n>0){
                cnt++;
                if(cnt&1)
                sum = sum+n%10;
                else
                sum = sum-n%10;
                n=n/10;
            }
        }
        return sum;
    }
};