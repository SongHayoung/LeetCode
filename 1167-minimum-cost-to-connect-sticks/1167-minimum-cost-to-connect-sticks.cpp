class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto n : sticks) pq.push(n);
        while(pq.size() != 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            res += a + b;
            pq.push(a + b);
        }
        return res;
    }
};