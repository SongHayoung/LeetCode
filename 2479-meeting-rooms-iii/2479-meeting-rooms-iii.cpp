class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> meet;
        priority_queue<long long, vector<long long>, greater<long long>> empty;
        vector<long long> use(n);
        for(int i = 0; i < n; i++) empty.push(i);
        long long best = 0;
        sort(begin(meetings), end(meetings));
        for(auto& meeting: meetings) {
            long long start = meeting[0], end = meeting[1];
            while(meet.size() and meet.top().first <= start) {
                auto [_, id] = meet.top(); meet.pop();
                empty.push(id);
            }
            if(!empty.size()) {
                int dur = end - start;
                start = meet.top().first;
                end = start + dur;
                auto [_, id] = meet.top(); meet.pop();
                empty.push(id);
            }
            auto id = empty.top(); empty.pop();
            best = max(best, ++use[id]);
            meet.push({end,id});
        }
        for(int i = 0; i < n; i++) if(use[i] == best) return i;
        return -1;
    }
};