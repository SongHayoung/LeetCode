class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq(26,words.size());
        for(auto& w : words) {
            vector<int> now(26);
            for(auto& ch : w) now[ch-'a']++;
            for(int i = 0; i < 26; i++) freq[i] = min(freq[i], now[i]);
        }
        vector<string> res;
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < freq[i]; j++) {
                res.push_back(string(1,'a' + i));
            }
        }
        return res;
    }
};