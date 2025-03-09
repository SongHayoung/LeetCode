
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<array<long long,3>> S;
        long long n = nums1.size(), sum = 0;
        priority_queue<long long,vector<long long>,greater<>> q;
        for(int i = 0; i < n; i++) S.push_back({nums1[i], nums2[i], i});
        sort(rbegin(S), rend(S));
        vector<long long> res(n);
        while(S.size()) {
            auto x = S.back()[0];
            long long ans = sum;
            while(S.size() and S.back()[0] == x) {
                auto [_,now,idx] = S.back(); S.pop_back();
                res[idx] = ans;
                sum += now;
                q.push(now);
            }
            while(q.size() > k) {
                sum -= q.top(); q.pop();
            }
        }
        return res;
    }
};