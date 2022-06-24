class Solution {
    string toString(vector<int>& A) {
        string res = "#";
        for(auto& a : A) {
            res += to_string(a) + '#';
        }
        return res;
    }
    vector<int> PI(string& s) {
        int n = s.length();
        vector<int> pi(n);
        for(int i = 1, j = 0; i < n; i++) {
            while(j > 0 and s[i] != s[j]) j = pi[j - 1];
            if(s[i] == s[j]) pi[i] = ++j;
        }
        return pi;
    }
    int kmp(string& s, string& p, int st) {
        auto pi = PI(p);
        for(int i = st, j = 0; i < s.length(); i++) {
            while(j > 0 and s[i] != p[j]) j = pi[j - 1];
            if(s[i] == p[j])
                if(++j == p.length())
                    return i;
        }
        
        return -1;
    }
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        string s = toString(nums);
        int i = 0;
        for(auto& g : groups) {
            string p = toString(g);
            i = kmp(s, p, i);
            if(i == -1) return false;
            i -= 1;
        }
        
        
        return true;
    }
};