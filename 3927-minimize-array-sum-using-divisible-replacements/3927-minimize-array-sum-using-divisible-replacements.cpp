
class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        unordered_map<long long, long long> freq;
        long long res = 0;
        for(auto& n : nums) freq[n]++;
        for(auto& [k,v] : freq) {
            long long pick = k;
            for(int i = 1; i * i <= k and pick > i; i++) {
                if(k % i) continue;
                long long a = i, b = k / i;
                if(freq.count(a)) pick = min(pick,a);
                if(freq.count(b)) pick = min(pick,b);
            }
            res += pick * v;
        }
        return res;
    }
};
