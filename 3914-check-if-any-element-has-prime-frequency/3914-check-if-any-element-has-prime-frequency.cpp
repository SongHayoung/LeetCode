class Solution {
    bool prime(int n) {
        if(n == 1) return false;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto& n : nums) freq[n]++;
        for(auto& [_,cnt] : freq) {
            if(prime(cnt)) return 1;
        }
        return 0;
    }
};