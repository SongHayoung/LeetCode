class Solution {
public:
    //stops, position, fuel
    int minRefuelStops(int target, int f, vector<vector<int>>& s) {
        priority_queue<int> pq;
        int res, p = 0;
        for(res = 0; f < target; res++) {
            while(p < s.size() and s[p][0] <= f) {
                pq.push(s[p++][1]);
            }
            if(pq.empty()) return -1;
            f += pq.top(); pq.pop();
        }
        return res;
    }
};