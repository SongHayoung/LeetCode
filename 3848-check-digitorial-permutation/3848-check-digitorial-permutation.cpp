class Solution {
public:
    bool isDigitorialPermutation(int n) {
        int fact[10]{0,};
        for(int i = 0; i < 10; i++) {
            fact[i] = 1;
            for(int j = 1; j <= i; j++) fact[i] *= j;
        }
        int sum = 0, x = n;
        while(x) {
            sum += fact[x%10];
            x /= 10;
        }
        unordered_map<int,int> freq;
        while(n) {
            freq[n%10]++; n/=10;
        }
        while(sum) {
            freq[sum%10]--; sum/= 10;
        }
        for(auto& [k,v] : freq) if(v) return false;
        return true;
    }
};