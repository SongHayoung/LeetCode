class Solution {
    int merge(map<int,int>& mp, int pos, int& m) {
        auto it = mp.lower_bound(pos);
        bool wasM = false;
        if(it != end(mp) and it->first == pos + 1) {
            auto nxt = it;
            if(nxt->second - nxt->first + 1 == m)
                wasM = true;
            it = mp.insert({pos, nxt->second}).first;
            mp.erase(nxt);
        } else {
            it = mp.insert({pos, pos}).first;
        }
        
        if(it != begin(mp)) {
            auto prv = prev(it);
            if(prv->second + 1 == it->first) {
                auto nxt = it;
                it = prv;
                if(it->second - it->first + 1 == m)
                    wasM = true;
                it->second = nxt->second;
                mp.erase(nxt);
            }
        }
        if(it->second - it->first + 1 == m)
            return 1;
        if(wasM)
            return -1;
        return 0;
    }
public:
    int findLatestStep(vector<int>& arr, int m) {
        map<int, int> mp;
        int res = -1;
        for(int i = 0; i < arr.size(); i++) {
            int merged = merge(mp, arr[i], m);
            if(merged == 1)
                res = i + 1;
            else if(merged == -1)
                res = i;
        }
        return res;
    }
};