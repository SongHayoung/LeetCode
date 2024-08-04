class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int, unordered_map<int,int>> freq;
        unordered_set<int> us;
        for(auto& vec : pick) {
            int x = vec[0], y = vec[1];
            if(++freq[x][y] > x) us.insert(x);
        }
        return us.size();
    }
};