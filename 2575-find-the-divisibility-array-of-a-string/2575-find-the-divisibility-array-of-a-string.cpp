
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> res;
        long long r = 0;
        for(int i = 0; i < word.size();i++) {
            r = (r * 10 + (word[i] - '0')) % m;
            if(r) res.push_back(0);
            else res.push_back(1);
        }
        return res;
    }
};
