class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int a = -1, b = -1, res = INT_MAX;
        for(int i = 0; i < wordsDict.size(); i++) {
            if(wordsDict[i] == word1) a = i;
            if(wordsDict[i] == word2) b = i;
            if(a != -1 and b != -1) res = min(res, abs(a-b));
        }
        return res;
    }
};