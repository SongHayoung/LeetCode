class Solution {
public:
    int tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        int res = 0;
        unordered_map<int,int> ab;
        for(auto& x : a) {
            for(auto& y : b) {
                ab[x^y]++;
            }
        }
        for(auto& z : c) {
            for(auto& [k,v] : ab) {
                int pc = __builtin_popcountll(k ^ z);
                if(pc % 2 == 0) res += v;
            }
        }
        return res;
    }
};