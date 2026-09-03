class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        vector<int> pref(n + 1);
        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (s[i] == '1');
        }

        int totalOnes = pref[n];
        vector<bool> res;

        for(auto& p : strs) {
            int fixedOnes = 0, questionCount = 0;

            for(char ch : p) {
                if(ch == '1') fixedOnes++;
                else if(ch == '?') questionCount++;
            }

            int need = totalOnes - fixedOnes;
            if(need < 0 || need > questionCount) {
                res.push_back(false);
                continue;
            }

            vector<int> use(n);
            int remaining = need;

            for(int i = n - 1; i >= 0; i--) {
                if(p[i] == '?' && remaining > 0) {
                    use[i] = 1;
                    remaining--;
                }
            }

            bool ok = true;
            int ones = 0;

            for(int i = 0; i < n; i++) {
                if(p[i] == '1') ones++;
                else if(use[i]) ones++;

                if(ones > pref[i + 1]) {
                    ok = false;
                    break;
                }
            }

            res.push_back(ok);
        }

        return res;
    }
};