int factors[101010];
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        for(long long i = 2; i < 101010; i++) {
            if(factors[i]) continue;
            for(long long j = i * i; j < 101010; j += i) factors[j] = i;
        }
        long long res = 0;
        auto prime = [&](int i) {
            return i >= 2 and factors[i] == 0;
        };
        for(int i = 0; i < nums.size(); i++) {
            if(prime(i)) res -= nums[i];
            else res += nums[i];
        }
        return abs(res);
    }
};