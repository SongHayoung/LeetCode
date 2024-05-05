class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int> freq;
        int res = INT_MAX, d = word.length() / k;
        for(int i = 0; i < word.length(); i += k) {
            string s = "";
            for(int j = 0; j < k; j++) {
                s.push_back(word[j+i]);
            }
            ++freq[s];
            res = min(res, d - freq[s]);
        }
        return res;
    }
};