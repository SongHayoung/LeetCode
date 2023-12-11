class Solution {
public:
    int findSpecialInteger(vector<int>& A) {
        unordered_map<int,int> freq;
        int best = 0;
        for(auto& a : A) {
            best = max(best, ++freq[a]);
        }
        for(auto& [k,v] : freq) if(v == best) return k;
        return 0;
    }
};