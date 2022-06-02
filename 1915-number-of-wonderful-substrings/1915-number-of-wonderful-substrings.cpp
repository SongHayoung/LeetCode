class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long res = 0, mask = 0;
        unordered_map<int, int> freq{{0, 1}};
        
        for(auto& ch : word) {
            mask ^= (1<<(ch-'a'));
            res += freq[mask];
            
            for(int i = 0; i < 10; i++) {
                res += freq[mask ^ (1<<i)];
            }
            
            
            freq[mask]++;
        }
        
        
        return res;
    }
};