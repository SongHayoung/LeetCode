class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char, int> freq;
        for(auto ch : s) freq[ch]++;
        string t = "";
        string res = "";
        for(int i = 0; i < s.length(); i++) {
            t.push_back(s[i]);
            freq[s[i]]--;
            bool has = false;
            while(t.length()) {
                bool has = false;
                for(char ch = 'a'; ch < t.back() and !has; ch++) {
                    if(freq[ch]) has = true;
                }
                if(has) break;
                res.push_back(t.back());
                t.pop_back();
            }
        }
        while(t.length()) {
            bool has = false;
            for(char ch = 'a'; ch < t.back() and !has; ch++) {
                if(freq[ch]) has = true;
            }
            if(has) break;
            res.push_back(t.back());
            t.pop_back();
        }
        return res;
    }
};