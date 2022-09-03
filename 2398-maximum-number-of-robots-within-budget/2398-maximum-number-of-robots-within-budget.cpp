class Solution {
public:
    int maximumRobots(vector<int>& C, vector<int>& R, long long B) {
        long long res = 0, l = 0, r = 0, n = C.size(), now = 0;
        priority_queue<pair<long long, long long>> Q;
        auto eval = [&]() {return (Q.empty() ? 0 : Q.top().first) + (r - l) * now <= B;};
        while(r < n) {
            while(!Q.empty() and Q.top().second < l) Q.pop();
            while(r < n and eval()) {
                res = max(res, r - l);
                Q.push({C[r],r});
                now += R[r];
                r++;
            }
            if(eval()) res = max(res, r - l);
            while(r < n and l < r and !eval()) {
                now -= R[l++];
                while(!Q.empty() and Q.top().second < l) Q.pop();
            }
        }
        return res;
    }
};