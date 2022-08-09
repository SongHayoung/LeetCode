class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        for(auto& p : piles) q.push(p);
        while(k--) {
            auto p = q.top();q.pop();
            q.push(p - p/2);
            if(p == 1) break;
        }
        int res = 0;
        while(!q.empty()) {
            res += q.top(); q.pop();
        }
        return res;
    }
};