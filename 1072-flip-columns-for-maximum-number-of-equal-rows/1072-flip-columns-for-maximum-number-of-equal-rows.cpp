class Solution {
    string hash(vector<int>& A) {
        string res = "";
        for(auto& a : A) res += to_string(a) + '#';
        return res;
    }
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& A) {
        for(auto& r : A) {
            if(r[0] == 1)
                for(auto& c : r) c = !c;
        }
        unordered_map<string, int> freq;
        int res = 0;
        for(auto& r : A) {
            res = max(res, ++freq[hash(r)]);
        }
        return res;
    }
};