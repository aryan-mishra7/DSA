class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> ans;
/*collioson bas ek he case mai hoga jab s.top()>0 hai or curr<0*/
        for(int i=0;i<asteroids.size();i++){
            int curr = asteroids[i];
            if(s.empty()){
                s.push(curr);
            }
            else if(curr<0 && s.top()>0){
                while(!s.empty() && s.top()>0 && s.top()<abs(curr)){
                    s.pop();
                }
                if(s.empty()){
                    s.push(curr);
                }
                else if(s.top()<0){
                    s.push(curr);
                }
                else if(s.top()==abs(curr)){
                    s.pop();
                }
            }
            else{
                s.push(curr);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        int st = 0;
        int e = ans.size()-1;
        while(st<=e){
            swap(ans[st],ans[e]);
            st++;
            e--;
        }
        return ans;
    }
};