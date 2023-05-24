class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long res = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> inc;
        priority_queue<pair<int, int>> q;
        for(int i = 0; i < nums1.size(); i++) {
            q.push({nums2[i], nums1[i]});
        }
        for(int i = 0; i < nums1.size(); i++) {
            auto [mi, val] = q.top(); q.pop();
            sum += val;
            inc.push(val);
            if(i >= k) {
                sum -= inc.top();
                inc.pop();
            }
            if(i + 1 >= k) {
                res = max(res, sum * mi);
            }
        }
        return res;
    }
};