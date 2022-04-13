class Solution {
    vector<pair<int,int>> memo;
    unordered_map<int, vector<int>> topology;
    pair<int, int> solution(int i, vector<int>& q) {
        if(memo[i].first != -1) return memo[i];
        auto& res = memo[i] = {i, q[i]};
        
        for(auto moreMoney : topology[i]) {
            auto [person, quite] = solution(moreMoney, q);
            if(quite < res.second) {
                res = {person, quite};
            }
        }
        return res;
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& r, vector<int>& q) {
        memo = vector<pair<int,int>>(q.size(), {-1,-1});
        vector<int> res(q.size(), -1);
        for(auto& vec : r) {
            topology[vec[1]].push_back(vec[0]);
        }
        
        for(int i = 0; i < q.size(); i++) {
            auto [person, quite] = solution(i, q);
            res[i] = person;
        }
        
        return res;
    }
};