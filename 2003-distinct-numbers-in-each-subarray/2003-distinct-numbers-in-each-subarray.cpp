class Solution {
public:
    vector<int> distinctNumbers(vector<int>& A, int k) {
        unordered_map<int, int> freq;
        vector<int> res;
        for(int i = 0; i < k - 1; i++)
            freq[A[i]]++;
        int n = A.size(), l = 0, r = k - 1;
        while(r < n) {
            freq[A[r++]]++;
            res.push_back(freq.size());
            if(--freq[A[l++]] == 0)
                freq.erase(A[l-1]);
        }
        return res;
    }
};