class Solution {
public:
long cnt[100001] = {}, sieve[100001] = {};
int sumOfFlooredPairs(vector<int>& nums) {
    int max_n = *max_element(begin(nums), end(nums));
    for (auto n : nums)
        ++cnt[n];
    for (auto n = 1; n <= max_n; ++n)
        if (cnt[n])
            for (auto f = 1; n * f <= max_n; ++f)
                sieve[f * n] = (sieve[f*n] + cnt[n]) %1000000007 ;
    partial_sum(begin(sieve), end(sieve), begin(sieve));
    return accumulate(begin(nums), end(nums), 0l, [&](long sum, int n) { return (sum + sieve[n]) % 1000000007; });
}
};