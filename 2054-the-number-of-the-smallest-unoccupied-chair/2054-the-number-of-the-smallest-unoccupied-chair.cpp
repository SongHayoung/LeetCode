class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        set<int> chair;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> aq, rq;
        for(auto& time : times) {
            if(time[0] <= times[targetFriend][0]) {
                aq.push({time[0], time[1]});
                chair.insert(chair.size());
            }
        }
        while(!aq.empty()) {
            if(!rq.empty() && rq.top().first <= aq.top().first) {
                chair.insert(rq.top().second);
                rq.pop();
            } else {
                auto a = aq.top();
                aq.pop();
                if(aq.empty()) return *chair.begin();
                rq.push({a.second, *chair.begin()});
                chair.erase(chair.begin());
            }
        }
        return -1;
    }
};