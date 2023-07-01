class Solution {
    vector<int> makeDebt(vector<vector<int>>& transactions) {
        map<int, int> m;
        for(auto& tr : transactions) {
            m[tr[0]] += tr[2];
            m[tr[1]] -= tr[2];
        }
        vector<int> debt(m.rbegin()->first + 1,0);
        for(auto [id, amount] : m) {
            debt[id] = amount;
        }
        return debt;
    }
    int backTracking(vector<int>& debt, int id) {
        while(id < debt.size() and !debt[id]) id++;
        if(id == debt.size()) return 0;

        int res = INT_MAX;
        for(int nxt = id + 1; nxt < debt.size(); nxt++) {
            if(debt[nxt] * debt[id] < 0) {
                debt[nxt] += debt[id];
                res = min(res, 1 + backTracking(debt, id + 1));
                debt[nxt] -= debt[id];
            }
        }
        return res;
    }
public:
    int minTransfers(vector<vector<int>>& transactions) {
        vector<int> debt = makeDebt(transactions);
        return backTracking(debt, 0);
    }
};