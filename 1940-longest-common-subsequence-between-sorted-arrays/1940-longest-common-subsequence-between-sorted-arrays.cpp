class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        unordered_map<int, int> freq;
        for(auto& A : arrays) {
            for(auto& a : A)
                freq[a]++;
        }
        vector<int> res;
        for(int i = 1; i <= 100; i++) {
            if(freq[i] == arrays.size()) res.push_back(i);
        }
        return res;
    }
};