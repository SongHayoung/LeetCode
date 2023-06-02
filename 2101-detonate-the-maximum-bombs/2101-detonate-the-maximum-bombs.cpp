class Solution {
    long long distance(vector<int>& a, vector<int>& b) {
        return pow(abs(1ll* (a[0]-b[0])),2) + pow(abs(1ll* (a[1]-b[1])),2);
    }
    bool inRange(vector<int>& a, vector<int>& b) {
        return 1ll* a[2] * a[2] >= distance(a,b);
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int res = 0, n = bombs.size();
        sort(bombs.begin(), bombs.end(), []( const vector<int>& a, const vector<int>& b ){return a[2] < b[2];});
        unordered_map<int, set<int>> m;
        for(int i = 0; i < n; i++) {
            queue<int> q;
            set<int> s;
            unordered_set<int> skip;
            q.push(i);
            s.insert(i);
            while(!q.empty()) {
                int pos = q.front();
                q.pop();
                if(skip.count(pos)) continue;
                for(int np = 0; np < n; np++) {
                    if(s.count(np)) continue;
                    if(!inRange(bombs[pos], bombs[np])) continue;
                    if(m.count(np)) {
                        s.insert(m[np].begin(), m[np].end());
                        skip.insert(m[np].begin(), m[np].end());
                    } else {
                        s.insert(np);
                        q.push(np);
                    }
                }
            }
            res = max(res, (int)s.size());
            m[i] = s;
        }
        return res;
    }
};