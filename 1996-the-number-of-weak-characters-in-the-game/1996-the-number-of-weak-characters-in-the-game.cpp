class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        map<int, multiset<int>> m;
        int res(0);
        for(auto& p : properties) {
            m[p[0]].insert(p[1]);
        }

        multiset<int> less;
        for(auto it = begin(m); it != end(m); it++) {
            auto lowerBound = less.lower_bound(*it->second.rbegin());
            if(lowerBound != begin(less)) {
                res += distance(begin(less), lowerBound);
                less.erase(begin(less), lowerBound);
            }
            less.insert(begin(it->second), end(it->second));
        }

        return res;
    }
};