class Solution {
    string dfs(map<char,list<int>> &m, set<char>& letter, int pos) {
        if(letter.empty()) {
            return "";
        }
        for(char ch : letter) {
            bool flag = true;
            int npos = *upper_bound(m[ch].begin(), m[ch].end(), pos);
            for(char other : letter) {
                if(m[other].back() < npos) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                letter.erase(ch);
                return ch + dfs(m, letter, npos);
            }
        }
        return "";
    }
public:
    string smallestSubsequence(string s) {
        map<char,list<int>> m;
        set<char> letter;
        for(int i = 0; i < s.length(); i++) {
            letter.insert(s[i]);
            m[s[i]].push_back(i);
        }
        
        return dfs(m, letter, -1);
    }
};
