class Solution {
    vector<long long> pi(string& p) {
        vector<long long> PI(p.size());
        for (long long i = 1, j = 0; i < p.size(); i++) {
            while (j > 0 && p[i] != p[j]) j = PI[j - 1];
            if (p[i] == p[j]) PI[i] = ++j;
        }
        return PI;
    }
    bool kmp(string& s, string& p, vector<long long>& PI, function<bool(long long&, long long&, vector<long long>&)> matched) {
        for(long long i = 0, j = 0; i < s.size(); i++) {
            while(j > 0 and s[i] != p[j]) j = PI[j-1];
            if(s[i] == p[j]) {
                if(++j == p.size()) {
                    bool ok = matched(i,j,PI);
                    if(!ok) return false;
                }
            }
        }
        return true;
    }
public:
    string generateString(string& s, string& p) {
        string res(s.size() + p.size() - 1, '#');
        long long t = 0;
        deque<long long> any;

        for (int i = 0, maxLength = 0; i < s.size(); i++) {
            if (s[i] == 'T') {
                t++;
                maxLength = max(maxLength, i);
                while (maxLength < i + p.size()) {
                    res[maxLength] = p[maxLength - i];
                    maxLength++;
                }
            }
        }

        long long matchT = 0;
        auto countT = [&matchT](long long& i, long long& j, vector<long long>& PI) mutable {
            matchT++;
            j = PI[j - 1];
            return true;
        };
        vector<long long> PI = pi(p);
        kmp(res, p, PI, countT);
        if(t != matchT) return ""; // check we made valid res with T

        for(int i = 0; i < res.size(); i++) {
            if(res[i] == '#') {
                any.push_back(i);
                res[i] = 'a';
            }
        }

        auto modifyF = [&s,&any,&res](long long& i, long long& j, vector<long long>& PI) mutable {
            if(s[i-j+1] == 'T') j = PI[j - 1]; // pass if T
            else { // try update largest index we can modify
                while(any.size() and any.front() < i - j + 1) any.pop_front();
                int at = -1;
                while(any.size() and any.front() <= i) at = any.front(), any.pop_front();
                if(at == -1) return false;
                res[at]++;
                j = 0;
            }
            return true;
        };
        return kmp(res, p, PI, modifyF) ? res : "";
    }
};