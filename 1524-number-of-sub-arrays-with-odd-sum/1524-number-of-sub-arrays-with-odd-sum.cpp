class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long odd = 0, even = 1, sum = 0, res = 0, mod = 1e9 + 7;;
        for(auto& a : arr) {
            sum += a;
            if(sum & 1) {
                res += even;
                odd++;
            } else {
                res += odd;
                even++;
            }
            res %= mod;
        }
        return res;
    }
};