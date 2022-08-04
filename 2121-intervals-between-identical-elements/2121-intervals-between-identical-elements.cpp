class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < arr.size(); i++) mp[arr[i]].push_back(i);
        vector<long long> res(arr.size());
        for(auto [_, A] : mp) {
            vector<long long> psum = {0};
            for(int i = 0; i < A.size(); i++)
                psum.push_back(psum.back() + A[i]);
            for(int i = 1; i < psum.size(); i++) {
                long long l = 1ll * A[i-1] * i - psum[i];
                long long r = psum.back() - psum[i] - 1ll * A[i-1] * (psum.size() - i - 1);
                res[A[i-1]] = l + r;
            }
        }
        return res;
    }
};