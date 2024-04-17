class Solution {
public:
    vector<long long> distance(vector<int>& A) {
        vector<long long> res(A.size());
        unordered_map<long long, pair<long long, long long>> mp;
        for(int i = 0; i < A.size(); i++) {
            res[i] += mp[A[i]].second * i - mp[A[i]].first;
            mp[A[i]].first += i;
            mp[A[i]].second += 1;
        }
        mp.clear();
        for(int i = A.size() - 1; i >= 0; i--) {
            res[i] += mp[A[i]].first - mp[A[i]].second * i;
            mp[A[i]].first += i;
            mp[A[i]].second += 1;
        }
        return res;
    }
};