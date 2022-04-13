class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int> pq(begin(s),end(s));
        while(pq.size() > 1) {
            auto y = pq.top(); pq.pop();
            auto x = pq.top(); pq.pop();
            if(y > x)
                pq.push(y-x);
        }
        return pq.empty() ? 0 : pq.top();
    }
};