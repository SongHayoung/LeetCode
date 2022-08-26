class Solution {
public:
    int countTriplets(vector<int>& A) {
        unordered_map<int ,int> freq;
        int res = 0, n = A.size(), z = 0;
        for(int i = 0; i < n; i++) {
            if(A[i] == 0) z += 1;
            for(auto [k,v] : freq) {
                if(k & A[i]) continue;
                res += v;
            }
            for(int j = 0; j < i; j++) {
                freq[A[i] & A[j]]++;
            }
            freq[A[i]]++;
        }
        return res * 6 + z;
    }
};