class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<int> res;
        int change_count = 0;

        for (int i = 0, j = 0; i < n1 && j < n2; i++) {
            if (word1[i] == word2[j]) {
                res.push_back(i);
                j++;
            } else if (change_count == 0) {
                res.push_back(i);
                change_count++;
                j++;
            }
            if (j == n2) break;
        }

        if (res.size() != n2) return {}; // No valid sequence found
        return res;
    }
};