class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long prefix[1024]{1}, res(0), mask(0);
        for(auto& c: word) {
            mask ^= 1<<(c-'a');
            res += prefix[mask]++;
            for(int i = 0; i < 10; i++)
                res += prefix[mask ^ (1<<i)];
        }
        return res;
    }
};