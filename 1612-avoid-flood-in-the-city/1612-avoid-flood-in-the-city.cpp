class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> dryDays;
        vector<int> res(rains.size(), 1);
        map<int, int> rainedLakes;
        
        for(int i = 0; i < rains.size(); i++) {
            if(!rains[i])
                dryDays.insert(i);
            else {
                auto isRained = rainedLakes.find(rains[i]);
                if(isRained == rainedLakes.end()) {
                    res[i] = -1;
                    rainedLakes[rains[i]] = i;
                } else {
                    auto hasDried = dryDays.upper_bound(isRained->second);
                    if(hasDried == dryDays.end())
                        return {};
                    res[*hasDried] = rains[i];
                    dryDays.erase(hasDried);
                    res[i] = -1;
                    rainedLakes[rains[i]] = i;
                }
            }
        }
        return res;
    }
};