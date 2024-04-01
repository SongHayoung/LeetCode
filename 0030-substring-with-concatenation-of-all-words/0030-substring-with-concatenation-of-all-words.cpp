class Solution {
    vector<string> chunking(int pos, string& s, int len) {
        string now = "";
        vector<string> res;
        for(int i = pos; i < s.length(); i++) {
            now.push_back(s[i]);
            if(now.size() == len) {
                res.push_back(now);
                now = "";
            }
        }
        return res;
    }
    void helper(string& s, unordered_map<string, int>& freq, int pos, int len, vector<int>& res, int tot) {
        if(pos + tot * len > s.length()) return;
        unordered_map<string, int> now;
        int quali = 0, r = pos;
        auto add = [&](string& s) {
            if(!freq.count(s)) return;
            if(++now[s] == freq[s]) quali++;
        };
        auto del = [&](string& s) {
            if(!freq.count(s)) return;
            if(now[s]-- == freq[s]) quali--;
        };
        vector<string> chunk = chunking(pos,s,len);
        for(int i = 0, r = 0; r < chunk.size(); i++) {
            while(i + tot > r and r < chunk.size()) add(chunk[r++]);
            if(quali == freq.size()) res.push_back(i * len + pos);
            del(chunk[i]);
        }
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> freq;
        for(auto& w : words) freq[w]++;
        int len = words[0].size();
        vector<int> res;
        for(int i = 0; i < len; i++) {
            helper(s,freq,i,len,res,words.size());
        }
        return res;
    }
};