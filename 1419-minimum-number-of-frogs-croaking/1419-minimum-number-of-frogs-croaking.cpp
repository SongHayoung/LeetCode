class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int res = 0, now = 0;
        unordered_map<char, int> freq;
        for(auto& ch : croakOfFrogs) {
            if(ch == 'c') {
                now++;
                freq[ch]++;
            } else if(ch == 'r') {
                if(freq['c'] == 0) return -1;
                freq['c']--;
                freq[ch]++;
            } else if(ch == 'o') {
                if(freq['r'] == 0) return -1;
                freq['r']--;
                freq[ch]++;
            } else if(ch == 'a') {
                if(freq['o'] == 0) return -1;
                freq['o']--;
                freq[ch]++;
            } else if(ch == 'k') {
                if(freq['a'] == 0) return -1;
                freq['a']--;
                now--;
            } else return -1;
            res = max(res, now);
        }
        if(now) return -1;
        return res;
    }
};