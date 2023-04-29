class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> freq;
        vector<int> res;
        int now = 0;
        for(int i = 0; i < A.size(); i++) {
            if(++freq[A[i]] == 0) now += 1;
            if(--freq[B[i]] == 0) now += 1;
            res.push_back(now);
        }
        return res;
    }
};