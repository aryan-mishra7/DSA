class Solution {
private:

    vector<int> nextSmallerElement(vector<int>& arr,int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int curr= arr[i];

            while(s.top()!=-1&&arr[s.top()]>=curr){
                s.pop();
            }
            ans[i] =s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerElement(vector<int>& arr,int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            int curr= arr[i];
            while(s.top()!=-1&&arr[s.top()]>=curr){
                s.pop();
            }
            ans[i] =s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights,int n){
        vector<int> next = nextSmallerElement(heights,n);
        vector<int> prev = prevSmallerElement(heights,n);
        int area = 0;

        for(int i=0;i<n;i++){

            if(next[i] ==-1)
                next[i]= n;
            int l =heights[i];
            int b=next[i]- prev[i] -1;

            int newArea =l*b;

            area = max(area,newArea);
        }

        return area;
    }

public:

    int maximalRectangle(vector<vector<char>>& matrix) {

        if(matrix.empty()||matrix[0].empty()){
            return 0;
        }
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> arr(m,0);
        int area = 0;
        for(int i=0;i<n;i++){

            //nayi array banao :
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1')
                    arr[j]++;
                else
                    arr[j] = 0;
            }

            // largest rectangle dekho in each row
            area =max(area, largestRectangleArea(arr,m));
        }

        return area;
    }
};
/*treat it like largest rectangle in histogram just create a new array as the input 
array is of char data type*/