

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long l = 0, r = costs.size() - 1, res = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        while(l < candidates) {
            q.push({costs[l],l});
            l++;
        }
        while(r >= costs.size() - candidates and r >= l) {
            q.push({costs[r], r});
            r--;
        }
        while(k--) {
            auto [v,idx] = q.top(); q.pop();
            res += v;
            if(idx < l) {
                if(l <= r) {
                    q.push({costs[l], l});
                    l++;
                }
            } else {
                if(l <= r) {
                    q.push({costs[r], r});
                    r--;
                }
            }
        }
        return res;
    }
};

