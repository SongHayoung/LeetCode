class Solution {
public:
    int maxProduct(int n) {
        vector<int> freq(10);
        while(n) {
            freq[n%10]++;
            n /= 10;
        }
        int res = 0;
        for(int i = 1; i < 10; i++) {
            if(!freq[i]) continue;
            freq[i]--;
            for(int j = i; j < 10; j++) if(freq[j]) res = max(res, i * j);
        }
        return res;
    }
};