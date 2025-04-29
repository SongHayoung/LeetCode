class Solution {
public:
    long long countSubarrays(vector<int>& A, int k) {
        long long res = 0, ma = *max_element(begin(A), end(A));
        vector<int> pos{-1};
        for(int i = 0; i < A.size(); i++) if(A[i] == ma) pos.push_back(i);
        pos.push_back(A.size());
        for(int i = 1; i < pos.size() - 1; i++) {
            long long l = i, r = i + k - 1;
            if(r + 1 >= pos.size()) break;
            long long lec = pos[l] - pos[l-1], ric = pos.back() - pos[r];
            res += lec * ric;
        }
        return res;
    }
};