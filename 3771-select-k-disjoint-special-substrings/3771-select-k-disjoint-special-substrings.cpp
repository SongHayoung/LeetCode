class Solution {
    vector<pair<int,int>> init(string& s) {
        vector<vector<int>> pos(26);
        for(int i = 0; i < s.length(); i++) {
            pos[s[i]-'a'].push_back(i);
        }
        vector<pair<int,int>> range;
        for(int i = 0; i < 26; i++) {
            if(pos[i].size() == 0) continue;
            int l = pos[i].front(), r = pos[i].back();
            for(int j = 0; j < 26; j++) {
                bool ok = false;
                for(int k = 0; k < 26; k++) {
                    auto it = lower_bound(begin(pos[k]), end(pos[k]), l);
                    if(it != end(pos[k]) and *it <= r) {
                        l = min(l, pos[k].front());
                        r = max(r, pos[k].back());
                        ok = true;
                    }
                }
                if(!ok) break;
            }
            range.push_back({l,r});
        }
        sort(begin(range), end(range));
        range.erase(unique(begin(range), end(range)),end(range));
        return range;
    }
public:
    bool maxSubstringLength(string s, int k) {
        auto range = init(s);
        for(int start = 0; start <= k == 1 ? 1 : 0; start++) {
            int best = 0, until = s.length() - (k == 1 ? !start : 0);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> op;
            for(int i = start, j = 0; i <= until; i++) {
                while(op.size() and op.top().first < i) {
                    best = max(best, op.top().second); op.pop();
                }
                while(j < range.size() and range[j].first < i) j++;
                while(j < range.size() and range[j].first == i) {
                    op.push({range[j++].second, best + 1});
                }
            }
            if(best >= k) return true;
        }
        return false;
    }
};