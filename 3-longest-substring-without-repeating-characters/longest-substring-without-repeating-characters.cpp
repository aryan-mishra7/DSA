class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int arr[128] = {0};
        int maxi = 1;
        while(r<s.length()){
            if(arr[s[r]]==1){
                //agar agle element ki freq phle se he 1 hai to shrink karo
                arr[s[l]]--;
                l++;
            }
            else if(r<s.length()){
            //expand
            arr[s[r]]++;
            r++;
            }
            maxi = max(maxi,r-l+1);
        }
        return maxi-1;
    }
};