class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1, x = 0;
        vector<int> res(n);
        for(int i = 1; i < n - 1; i+=2) {
            x ^= encoded[i];
        }
        for(int i = 1; i <= n; i++)
            x ^= i;
        res[0] = x;
        for(int i = 0; i < n - 1; i++) {
            res[i + 1] = res[i] ^ encoded[i];
        }
        return res;
    }
};