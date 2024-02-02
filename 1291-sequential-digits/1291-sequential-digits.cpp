class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        queue<long long> q;
        q.push(12);
        q.push(23);
        q.push(34);
        q.push(45);
        q.push(56);
        q.push(67);
        q.push(78);
        q.push(89);
        while(!q.empty()) {
            auto n = q.front(); q.pop();
            if(low <= n and n <= high) {
                res.push_back(n);
            }
            if(n <= high) {
                auto last = n % 10 + 1;
                if(last < 10) q.push(n * 10 + last);
            }
        }
        return res;
    }
};