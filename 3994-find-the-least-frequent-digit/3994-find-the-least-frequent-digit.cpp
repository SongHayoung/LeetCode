class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int,int> freq;
        while(n) {
            freq[n%10]++;
            n /= 10;
        }
        int res = begin(freq)->first;
        for(auto& [k,v] : freq) {
            if(v == freq[res]) res = min(res,k);
            else if(v < freq[res]) res = k;
        }
        return res;
    }
};