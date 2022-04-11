class Solution {
    long toInt(string s) {
        long res = 0;
        for(int i = 0; i < s.length(); i++) {
            res = (res<<3) + (res<<1) + (s[i] & 0b1111);
        }
        return res;
    }
    bool invalid(string s) {
        return s.length() >= 2 && s[0] == '0';
    }
    bool equal(int sum, string& s, int& pos) {
        string target = to_string(sum);
        if(target.length() + pos > s.length()) return false;
        for(auto& c : target) {
            if(s[pos++] != c) return false;
        }
        return true;
    }
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        int len = S.length();
        stringstream f1;
        for(int i = 0; i < len / 2; i++) {
            f1 << S[i];
            stringstream f2;
            long f1L = toInt(f1.str());
            if(invalid(f1.str()) || f1L > INT_MAX) return vector<int>();
            for(int j = i + 1; j + i < len; j++) {
                f2 << S[j];
                long f2L = toInt(f2.str());
                if(invalid(f2.str()) || f2L > INT_MAX) break;
                int pos = j + 1;
                res.clear();
                res.push_back(f1L);
                res.push_back(f2L);
                while(pos < len) {
                    long sum = 1L * (*prev(res.end())) + 1L * (*prev(prev(res.end())));
                    if(sum <= INT_MAX && equal(sum, S, pos)) res.push_back(sum);
                    else {pos = -1; break; }
                }
                if(pos == len) return res;
            }
        }
        return vector<int>();
    }
};
