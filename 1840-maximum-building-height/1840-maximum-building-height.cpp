class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        map<int,int> mp;
        mp[n] = n - 1;
        mp[1] = 0;
        for(auto& r : restrictions) {
            int p = r[0], h = min(r[1],p-1);
            if(!mp.count(p)) mp[p] = h;
            else mp[p] = min(mp[p], h);
        }
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<>> q;
        for(auto& [k,v] : mp) q.push({v,k});
        int res = 0;
        while(q.size()) {
            auto [h,idx] = q.top(); q.pop();
            if(h != mp[idx]) continue;
            auto it = mp.find(idx);
            res = max(res, h);
            if(it != begin(mp)) {
                auto lit = prev(it);
                int pos = lit->first, height = lit->second;
                if(height >= h) {
                    int len = abs(pos - idx);
                    if(len + h != height) {
                        if(len + h < height) {
                           mp[pos] = len + h;
                            q.push({len + h,pos});
                       }
                    }
                }
            }
            if(next(it) != end(mp)) {
                auto rit = next(it);
                int pos = rit->first, height = rit->second;
                if(height >= h) {
                    int len = abs(pos - idx);
                    if(len + h != height) {
                        if(len + h < height) {
                           mp[pos] = len + h;
                           q.push({len + h,pos});
                       }
                    }
                }
            }
        }
        for(auto it = begin(mp); it->first != n; it++) {
            int i = it->first, h1 = it->second;
            auto nit = next(it);
            int j = nit->first, h2 = nit->second;
            int diff = abs(h1-h2), len = j - i;
            int rem = len - diff;
            res = max(res, max(h1,h2) + rem / 2);
        }
        return res;
    }
};