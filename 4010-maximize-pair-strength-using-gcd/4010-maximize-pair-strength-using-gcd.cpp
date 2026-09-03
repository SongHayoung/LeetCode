class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto& n : nums) freq[n]++;

        vector<int> vals;
        for(auto& [n, cnt] : freq) vals.push_back(n);

        long long res = 0;
        for(int i = 0; i < vals.size(); i++) {
            for(int j = i; j < vals.size(); j++) {
                int a = vals[i], b = vals[j];

                if(i == j) {
                    if(freq[a] >= 2) res = max(res, 1ll);
                } else {
                    long long g = gcd(a, b);
                    res = max(res, 1ll * a * b / g / g);
                }
            }
        }

        return res;
    }
};