class Solution {
    long long digits(string& s, int& p) {
        long long res = 0;
        while(p < s.length() and isdigit(s[p])) {
            res = res * 10 + (s[p] - '0');
            p++;
        }
        return res ? res : 1;
    }
    unordered_map<string, long long> parse(string& s, int& p) {
        unordered_map<string, long long> res;
        while(p < s.length() and s[p] != ')') {
            if(s[p] == '(') {
                ++p;
                auto sub = parse(s,p);
                long long val = digits(s,p);
                for(auto& [k,v] : sub) {
                    res[k] += v * val;
                }
            } else {
                string atom = string(1,s[p]);
                p++;
                while(p < s.length() and islower(s[p])) {
                    atom.push_back(s[p++]);
                }
                long long val = digits(s,p);
                res[atom] += val;
            }
        }
        ++p;
        return res;
    }
public:
    string countOfAtoms(string formula) {
        int pos = 0;
        auto atoms = parse(formula, pos);
        vector<pair<string,long long>> S;
        for(auto& [k,v] : atoms) {
            S.push_back({k,v});
        }
        sort(begin(S), end(S));
        string res = "";
        for(auto& [atom, cnt] : S) res += atom + (cnt == 1 ? "" : to_string(cnt));
        return res;
    }
};