class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size(), res = 0;
        vector<int> bits;
        for(int i = 0; i < n; i++) {
            int bi = 0;
            bool unique = true;
            for(auto& ch : arr[i]) {
                if(bi & (1<<(ch-'a'))) unique = false;
                bi |= 1<<(ch-'a');
            }
            if(unique)
                bits.push_back(bi);
        }
        n = bits.size();
        for(int subset = 0; subset < 1<<n; subset++) {
            int mask = 0;
            bool unique = true;
            for(int i = 0; i < n and unique; i++) {
                if(!(subset & (1<<i))) continue;
                if(mask & bits[i]) {
                    unique = false;
                } else mask ^= bits[i];
            }
            if(unique)
                res = max(res, __builtin_popcount(mask));
        }
        return res;
    }
};