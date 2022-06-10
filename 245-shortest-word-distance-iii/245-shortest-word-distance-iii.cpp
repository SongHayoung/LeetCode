class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> A, B;
        for(int i = 0; i < wordsDict.size(); i++) {
            if(wordsDict[i] == word1) A.push_back(i);
            else if(wordsDict[i] == word2) B.push_back(i);
        }
        int res = INT_MAX;
        if(word1 == word2) {
            for(int i = 0; i < A.size() - 1; i++) {
                res = min(res, A[i + 1] - A[i]);
            }
        } else {
            for(int i = 0, j = 0; i < A.size(); i++) {
                while(j < B.size() and B[j] < A[i]) j++;
                if(j) res = min(res, A[i] - B[j - 1]);
                if(j != B.size()) res = min(res, B[j] - A[i]);
            }
        }
        return res;
    }
};