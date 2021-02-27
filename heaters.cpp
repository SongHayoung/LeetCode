class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int res = 0;
        for(auto house : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            if(it == heaters.end())
                res = max(res, abs(*prev(it) - house));
            else if(it == heaters.begin())
                res = max(res, abs(*it - house));
            else
                res = max(res, min(abs(*it - house), abs(*prev(it) - house)));
        }

        return res;
    }
};
