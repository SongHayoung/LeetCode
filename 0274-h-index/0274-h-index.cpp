class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> freq(n + 1);
        for(auto& c : citations) {
            freq[min(c,n)]++;
        }
        for(int i = n; i; i--) {
            if(freq[i] >= i) return i;
            freq[i-1] += freq[i];
        }
        return 0;
    }
};