class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        unordered_map<int, int> h, v;
        hBars.push_back(1);
        hBars.push_back(n+2);
        vBars.push_back(1);
        vBars.push_back(m+2);
        sort(begin(hBars), end(hBars));
        hBars.erase(unique(begin(hBars), end(hBars)), end(hBars));
        sort(begin(vBars), end(vBars));
        vBars.erase(unique(begin(vBars), end(vBars)), end(vBars));
        for(int i = 0; i < hBars.size(); i++) {
            int le = max(hBars[i] - 1,1);
            for(int j = i, now = hBars[i]; j < hBars.size();j++, now++) {
                if(hBars[j] != now) break;
                h[hBars[j]-le] += 1;
                if(j != hBars.size() - 1) h[hBars[j]-le+1] += 1;
            }
        }
        int res = 4;
        for(int i = 0; i < vBars.size(); i++) {
            int le = max(vBars[i] - 1, 1);
            for(int j = i, now = vBars[i]; j < vBars.size();j ++, now++) {
                if(vBars[j] != now) break;
                int d1 = vBars[j] - le, d2 = d1 + 1;
                if(h.count(d1)) res = max(res, d1 * d1);
                if(j != vBars.size() - 1 and h.count(d2)) res = max(res, d2 * d2);
            }
        }
        return res;
    }
};