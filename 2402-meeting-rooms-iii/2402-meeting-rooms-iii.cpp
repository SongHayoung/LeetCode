class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& A) {
        long long now = 0;
        set<long long> rooms;
        unordered_map<long long, long long> count;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> Q;
        sort(begin(A), end(A));
        for(int i = 0; i < A.size(); i++) {
            long long st = A[i][0], ed = A[i][1];
            long long dur = ed - st;
            while(!Q.empty() and Q.top().first <= st) {
                auto [fin, rid] = Q.top(); Q.pop();
                rooms.insert(rid);
            }
            if(now == n) {
                if(rooms.empty()) {
                    auto [fin, rid] = Q.top(); Q.pop();
                    Q.push({fin + dur, rid});
                    count[rid]++;
                } else {
                    auto r = *rooms.begin();
                    rooms.erase(r);
                    Q.push({ed, r});
                    count[r]++;
                }
            } else {
                if(rooms.empty()) {
                    Q.push({ed, now});
                    count[now]++;
                    now += 1;
                } else {
                    auto r = *rooms.begin();
                    rooms.erase(r);
                    Q.push({ed, r});
                    count[r]++;
                }
            }
        }
        long long c = -1, rid = 0;
        for(auto [id, freq] : count) {
            if(freq == c) {
                rid = min(rid, id);
            } else if(freq > c) {
                c = freq;
                rid = id;
            }
        }
        return rid;

    }
};
