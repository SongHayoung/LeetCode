class Solution {
public:
    int maxRepOpt1(string text) {
        int res = 0, n = text.length(), l = 0, r = 0;
        unordered_map<char, int> freq;
        for(auto& ch : text) ++freq[ch];
        while(r < n) {
            int temp = -1, noteq = 0;
            while(r < n) {
                if(text[l] != text[r]) {
                  if(++noteq >= 2) break;
                    temp = r;
                }
                ++r;
                int remain = freq[text[l]] - (r - l);
                if(remain < 0) break;
                res = max(res, r - l);
            }
            if(temp == -1) l = r;
            else r = l = temp;
        }
        l = r = n - 1;
        while(l >= 0) {
            int temp = -1, noteq = 0;
            while(l >= 0) {
                if(text[l] != text[r]) {
                  if(++noteq >= 2) break;
                    temp = l;
                }
                --l;
                int remain = freq[text[r]] - (r - l);
                if(remain < 0) break;
                res = max(res, r - l);
            }
            if(temp == -1) r = l;
            else r = l = temp;
        }
        return res;
    }
};