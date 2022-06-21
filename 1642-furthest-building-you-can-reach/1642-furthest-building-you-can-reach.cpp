class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 0;
        for(int i = 0; i < h.size() - 1; i++) {
            if(h[i] >= h[i+1]) continue;
            pq.push(h[i+1] - h[i]);
            if(pq.size() > l) {
                if(pq.top() > b)
                    return i;
                b -= pq.top();
                pq.pop();
            }
        }
        return h.size() - 1;
    }
};