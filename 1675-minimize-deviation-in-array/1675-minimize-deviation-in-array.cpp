class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mi = INT_MAX, res = INT_MAX;
        for(auto num : nums) {
            if(num & 1) {
                mi = min(num * 2, mi);
                pq.push(num * 2);
            } else {
                mi = min(num, mi);
                pq.push(num);
            }
        }
        while((pq.top() & 1) == 0) {
            res = min(res, pq.top() - mi);
            mi = min(mi, pq.top() / 2);
            pq.push(pq.top() / 2);
            pq.pop();
        }
        return min(res, pq.top() - mi);
    }
};