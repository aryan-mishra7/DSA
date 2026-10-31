class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;
        int i = 0;
        while(i<n){
            char curr = chars[i];
            int cnt = 0;
            while(i<n&&curr==chars[i]){
                cnt++;
                i++;
            }
            chars[index] = curr;
            index++;
            if(cnt>1){
                string count = to_string(cnt);
                for(int i=0;i<count.length();i++){
                    chars[index] = count[i];
                    index++;
                }
            }
        }
        return index;
    }
};