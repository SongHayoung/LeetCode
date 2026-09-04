
class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        int mod = 1e9 + 7, bit = 0;
        unordered_map<int, long long> e, o;
        long long E = 1, O = 0;
        e[bit] = 1;
        for(auto& n : nums) {
            bit ^= n;
            E = o.count(bit ^ target2) ? o[bit ^ target2] : 0, O = e.count(bit ^ target1) ? e[bit ^ target1] : 0;
            o[bit] = (o[bit] + O) % mod;
            e[bit] = (e[bit] + E) % mod;
        }
        return (O + E) % mod;
    }
};
