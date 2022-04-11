class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& u, vector<int>& t, vector<string>& w) {
        int sz = u.size();
        unordered_map<string, map<int, string>> m;
        map<vector<string>, int> mm;
        for(int i = 0; i < sz; i++) {
            m[u[i]][t[i]] = w[i];
        }
        for(auto& user : m) {
            set<vector<string>> s;
            for(auto i = begin(user.second); i != end(user.second); i++) {
                for(auto j = next(i); j != end(user.second); j++) {
                    for(auto k = next(j); k != end(user.second); k++) {
                        s.insert({i->second, j->second, k->second});
                    }
                }
            }
            for(auto vec : s) {
                mm[vec]++;
            }
        }

        return max_element(begin(mm), end(mm), [](const auto& a, const auto& b) { return a.second == b.second ? a.first > b.first : a.second < b.second; })->first;
    }
};
