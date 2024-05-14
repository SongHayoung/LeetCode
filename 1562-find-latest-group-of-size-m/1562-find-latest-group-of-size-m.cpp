class Solution {
    map<int, int> r;
    multiset<int> ms;
    void merge(int x) {
        r[x] = x;
        ms.insert(1);
        {
            auto it = r.lower_bound(x);
            if(it != begin(r)) {
                --it;
                if(it->second + 1 == x) x = it->first;
            }
        }
        auto rm = [&](int len) {
            ms.erase(ms.find(len));
        };
        while(r.count(r[x] + 1)) {
            int y = r[r[x] + 1];
            rm(y - (r[x] + 1) + 1);
            rm(r[x] - x + 1);
            r.erase(r[x] + 1);
            r[x] = y;
            ms.insert(y - x + 1);
        }
    }
public:
    int findLatestStep(vector<int>& arr, int m) {
        int res = -1;
        r = {};
        ms = {};
        for(int i = 0; i < arr.size(); i++) {
            merge(arr[i]);
            if(ms.count(m)) res = i + 1;
        }
        return res;
    }
};