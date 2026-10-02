class StockSpanner {
private:
public:
stack<int> s;
vector<int> arr;
int i = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        if(s.empty()){
            s.push(i);
            i++;
            return 1;
        }
            while(!s.empty() && arr[s.top()]<=price)
            s.pop();
            if(s.empty()){
            s.push(i);
            i++;
            return i;   
            }
            int k = s.top();
            s.push(i);
            int n = i;
            i++;
            return n-k;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */