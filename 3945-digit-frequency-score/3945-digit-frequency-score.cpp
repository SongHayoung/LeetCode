class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int> freq;
        while(n) {
            freq[n%10]++;
            n /= 10;
        }
        int res = 0;
        for(auto& [k,v] : freq) res += k*v;
        return res;
    }
};