class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> pq;
        stringstream ss;
        char prev = '*';
        for(char& c : s) {
            m[c]++;
        }
        for(auto& entity : m) {
            pq.push({entity.second, entity.first});
        }
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            if(p.second != prev) {
                prev = p.second;
                ss << prev;
                if(--p.first) {
                    pq.push(p);
                }
            } else {
                if(pq.empty()) return "";
                auto p2 = pq.top();
                pq.pop();
                pq.push(p);
                if(p2.second != prev) {
                    prev = p2.second;
                    ss << prev;
                    if(--p2.first) {
                        pq.push(p2);
                    }
                }
            }
        }
        return ss.str();
    }
};
