class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26);
        for(auto& ch : word) freq[ch-'a']++;
        sort(begin(freq), end(freq));
        int res = INT_MAX, pre = 0;
        for(int i = 0; i < 26; i++) {
            if(!freq[i]) continue;
            int ma = freq[i] + k, now = 0;
            for(int j = 25; j > i and freq[j] > ma; j--) now += freq[j] - ma;
            res = min(res, pre + now);
            pre += freq[i];
        }
        return res;
    }
};