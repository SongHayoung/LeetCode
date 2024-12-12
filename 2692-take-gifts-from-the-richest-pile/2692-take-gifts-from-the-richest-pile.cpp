class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long res = 0;
        priority_queue<long long> q;
        for(auto g : gifts) q.push(g);
        while(k--) {
            if(q.top() == 1) break;
            auto tp = q.top(); q.pop();
            q.push(sqrt(tp));
        }
        while(q.size()) {
            res += q.top(); q.pop();
        }
        return res;
    }
};