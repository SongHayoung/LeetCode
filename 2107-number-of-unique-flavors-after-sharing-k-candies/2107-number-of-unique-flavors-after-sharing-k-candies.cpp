class Solution {
public:
    int shareCandies(vector<int>& A, int k) {
        unordered_map<int, int> freq;
        for(auto& a : A) freq[a]++;
        int res = 0, now = freq.size();
        for(int i = 0; i < A.size(); i++) {
            if(--freq[A[i]] == 0) now -= 1;
            if(i >= k and ++freq[A[i-k]] == 1) now += 1;
            if(i >= k - 1) res = max(res, now);
        }
        return res;
    }
};