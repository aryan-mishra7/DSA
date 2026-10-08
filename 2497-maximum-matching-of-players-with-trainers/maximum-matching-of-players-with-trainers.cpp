class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int n = (players.size()>=trainers.size())?trainers.size():players.size();
        int m = trainers.size();
        int cnt = 0;
        int s = players.size()-1;
        int e = trainers.size()-1;
        while(s>=0&&e>=0){
            if(players[s]>trainers[e])
            s--;
            else if(players[s]<=trainers[e]){
                s--;
                e--;
                cnt++;
            }
        }
        return cnt;
    }
};