class Solution {
public:
    bool isFascinating(int n) {
        string a = to_string(n), b = to_string(2 * n), c = to_string(3 * n);
        vector<int> freq(10);
        for(auto ch : a) freq[ch-'0'] += 1;
        for(auto ch : b) freq[ch-'0'] += 1;
        for(auto ch : c) freq[ch-'0'] += 1;
        for(int i = 1; i <= 9; i++) if(freq[i] != 1) return false;
        return freq[0] == 0;
    }
};
