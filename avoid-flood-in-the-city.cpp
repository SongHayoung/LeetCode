class Solution {
private:
    map<int, list<int>> getRainyDays(vector<int>& rains) {
        map<int, list<int>> res;
        for(int i = 0; i < rains.size(); i++) {
            if(rains[i])
                res[rains[i]].push_back(i);
        }
        return res;
    }
public:
    vector<int> avoidFlood(vector<int>& rains) {
        map<int, list<int>> rainyDays = getRainyDays(rains);
        map<int, int> lakes;
        priority_queue<pair<int, int>> pq;
        vector<int> ans(rains.size());

        for(int i = 0; i < rains.size(); i++) {
            if(rains[i]) {
                lakes[rains[i]]++;
                rainyDays[rains[i]].pop_front();
                if(!rainyDays[rains[i]].empty())
                    pq.push(make_pair(-rainyDays[rains[i]].front(), rains[i]));

                if(lakes[rains[i]] >= 2)
                    return vector<int> {};
                ans[i] = -1;
            } else {
                if(pq.empty()) {
                    ans[i] = 1;
                } else {
                    pair<int,int> dryLake = pq.top();
                    pq.pop();
                    ans[i] = dryLake.second;
                    lakes[dryLake.second]--;
                }
            }
        }

        return ans;
    }
};
