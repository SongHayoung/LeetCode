class Solution {
    bool helper(string& s, vector<int>& freq, string& now, int l, int r, bool over) {
        if(l > r) return now > s;
        if(over) {
            for(int i = 0; i < 26; i++) for(int j = 0; j < freq[i]; j++) {
                now[l++] = i + 'a';
            }
            return true;
        }
        for(int start = s[l] - 'a', i = start; i < 26; i++) {
            if(!freq[i]) continue;
            freq[i] -= 1;
            now[l] =  i + 'a';

            if(helper(s,freq,now,l+1,r,start != i)) return true;

            freq[i] += 1;
            if(i != start) return false;
        }
        return false;
    }
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26);
        for(auto& ch : s) freq[ch-'a']++;
        string now = string(s.length(), '#');
        if(helper(target, freq, now, 0, target.size() - 1, false)) return now;
        return "";
    }
};