class Solution {
    map<string, map<string, int>> m;
    int arrive;

    bool build(vector<string> &res, const string &from) {
        if (res.size() == arrive) return true;
        for (auto &to : m[from]) {
            if (!to.second) continue;
            res.push_back(to.first);
            to.second--;
            if (build(res, to.first)) return true;
            to.second++;
            res.pop_back();
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        arrive = tickets.size() + 1;
        for (auto &t : tickets) {
            m[t.front()][t.back()]++;
        }
        vector<string> res{"JFK"};
        build(res, "JFK");
        return res;
    }
};
