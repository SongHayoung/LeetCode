class Solution {
public:
    int duplicateNumbersXOR(vector<int>& A) {
        unordered_map<int,int> us;
        int res = 0;
        for(auto& x : A) {
            if(++us[x] == 2) res ^= x;
        }
        return res;
    }
};