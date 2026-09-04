class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for(auto& w : words) {
            int sum = 0;
            for(auto& ch : w) sum += weights[ch-'a'];
            res.push_back('z' - sum % 26);
        }
        return res;
    }
};