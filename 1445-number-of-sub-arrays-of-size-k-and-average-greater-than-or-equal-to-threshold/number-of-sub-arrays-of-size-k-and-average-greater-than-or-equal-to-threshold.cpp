class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0;
        int r = k-1;
        int sum = 0;
        for(int i=l;i<=r;i++)
        sum = sum + arr[i];
        int avg = sum/k;
        int cnt = 0;
        while(r<arr.size()){
            if(avg>=threshold)
            cnt++;
            sum = sum - (arr[l]);
            l++;
            r++;
            if(r<arr.size())
            sum = sum + (arr[r]);
            avg = sum/k;
        }
        return cnt;
    }
};