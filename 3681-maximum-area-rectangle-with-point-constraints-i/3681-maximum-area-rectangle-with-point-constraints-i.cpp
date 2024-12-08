class Solution {
    int fenwick[102];
    void update(int n, int k) {
        while(n < 102) {
            fenwick[n] += k;
            n += n & -n;
        }
    }
    int query(int n) {
        int res = 0;
        while(n) {
            res += fenwick[n];
            n -= n & -n;
        }
        return res;
    }
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        map<int,vector<int>> mp;
        sort(begin(points), end(points));
        for(auto& p : points) mp[p[0]].push_back(p[1] + 1);
        int res = -1;
        for(auto it = begin(mp); it != end(mp); it++) {
            for(auto jt = next(it); jt != end(mp); jt++) {
                int i = 0, j = 0, h = jt->first - it->first;
                while(i + 1 < it->second.size() and j + 1 < jt->second.size()) {
                    if(it->second[i] == jt->second[j] and it->second[i+1] == jt->second[j+1]) {
                        int w = it->second[i+1] - it->second[i];
                        if(query(it->second[i+1]) - query(it->second[i] - 1) == 0) {
                            res = max(res, h * w);
                        }
                        i++,j++;
                    } else {
                        if(it->second[i] < jt->second[j]) i++;
                        else j++;
                    }
                }
                for(auto& x : jt->second) update(x,1);
            }
            memset(fenwick, 0, sizeof fenwick);
        }
        
        
        return res;
    }
};