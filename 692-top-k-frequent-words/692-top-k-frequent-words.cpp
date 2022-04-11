typedef pair<int, string> p;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        auto cmp = [](p const& a, p const& b)  { return a.first == b.first ? a.second > b.second : a.first < b.first; };
        priority_queue<p, vector<p>, decltype(cmp)> pq(cmp);
        vector<string> res;
        for(auto& w : words) {
            m[w]++;
        }

        for(auto& e : m) {
            pq.push({e.second, e.first});
        }

        while(k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};