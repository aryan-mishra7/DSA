class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            int temp = nums[i];
            while(temp>=10)
                temp = temp/10;
            for(int j=i+1;j<nums.size();j++){
                int sec = nums[j]%10;
                if(gcd(temp,sec)==1)
                cnt++;
            }
        }
        return cnt;
    }
};