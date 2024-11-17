class Solution {
    bool helper(vector<long long>& nums, long long k) {
        vector<pair<long long, long long>> A;
        vector<long long> fl(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != -1) continue;
            long long l = INT_MIN, r = INT_MAX;
            if(i and nums[i-1] != -1) {
                l = max(l, nums[i-1] - k);
                r = min(r, nums[i-1] + k);
            }
            if(i + 1 < nums.size() and nums[i+1] != -1) {
                l = max(l, nums[i+1] - k);
                r = min(r, nums[i+1] + k);
            }
            if(l > r) return false;
            bool ok = false;
            for(int j = 0; j < A.size() and !ok; j++) {
                long long mi = max(l, A[j].first), ma = min(r, A[j].second);
                if(mi <= ma) {
                    A[j] = {mi,ma};
                    ok = true;
                    fl[i] = j + 1;
                }
            }
            if(!ok) {
                A.push_back({l,r});
                fl[i] = A.size();
            }
            if(A.size() > 2) return false;
        }
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == -1 and nums[i+1] == -1) {
                if(fl[i] != fl[i+1]) {
                    sort(begin(A), end(A));
                    return A[1].first - A[0].second <= k;
                }
            }
        }
        return true;
    }
public:
    int minDifference(vector<int>& nums) {
        long long l = 0, r = INT_MAX, res = r;
        vector<long long> A;
        for(int i = 0; i < nums.size(); i++) {
            if(i + 1 != nums.size() and nums[i] != -1 and nums[i+1] != -1) l = max(l, 1ll * abs(nums[i] - nums[i+1]));
            if(nums[i] != -1) A.push_back(nums[i]);
            else {
                if(A.size() == 0 or A.back() != -1) A.push_back(nums[i]);
                else if(A.size() == 1 and A.back() == -1) {}
                else {
                    if(A[A.size() - 2] == -1) continue;
                    A.push_back(nums[i]);
                }
            }
        }
        if(A.size() >= 2 and A.back() == -1 and A[A.size() - 2] == -1) A.pop_back();
        if(A.size() <= 1) return 0;
        while(l <= r){
            int m = l + (r - l) / 2;
            bool ok = helper(A,m);
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};