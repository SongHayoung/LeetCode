class Solution {
    vector<long long> pi(const string& pattern) {
        vector<long long> prefix(pattern.size());
        long long j = 0;
        for (long long i = 1; i < pattern.size(); i++) {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = prefix[j - 1];
            }
            if (pattern[i] == pattern[j]) {
                prefix[i] = ++j;
            }
        }
        return prefix;
    }
    vector<long long> kmp1(const string& text, const string& pattern, vector<long long>& PI) {
        vector<long long> matchPositions;
        long long j = 0;
        for (long long i = 0; i < text.size(); i++) {
            while (j > 0 && text[i] != pattern[j]) {
                j = PI[j - 1];
            }
            if (text[i] == pattern[j]) {
                j++;
                if (j == pattern.size()) {
                    matchPositions.push_back(i - pattern.size() + 1);
                    j = PI[j - 1];
                }
            }
        }
        return matchPositions;
    }
    string kmp2(const string& baseString, string& res, const string& pattern, vector<long long>& PI, deque<long long>& any) {
        long long j = 0;
        for (long long i = 0; i < res.size(); i++) {
            while (j > 0 && res[i] != pattern[j]) {
                j = PI[j - 1];
            }
            if (res[i] == pattern[j]) {
                j++;
                if (j == pattern.size()) {
                    if(baseString[i-j+1] == 'T') j = PI[j - 1];
                    else {
                        while(any.size() and any.front() < i - j + 1) any.pop_front();
                        int at = -1;
                        while(any.size() and any.front() <= i) {
                            at = any.front(); any.pop_front();
                        }
                        if(at == -1) return "";
                        res[at]++;
                        j = 0;
                    }
                }
            }
        }
        return res;
    }
public:
    string generateString(const string& baseString, const string& pattern) {
        string res(baseString.size() + pattern.size() - 1, '#');
        vector<long long> patternPositions, anti;
        deque<long long> any;

        for (int i = 0, maxLength = 0; i < baseString.size(); i++) {
            if (baseString[i] == 'T') {
                patternPositions.push_back(i);
                maxLength = max(maxLength, i);
                while (maxLength < i + pattern.size()) {
                    res[maxLength] = pattern[maxLength - i];
                    maxLength++;
                }
            } else anti.push_back(i);
        }

        vector<long long> PI = pi(pattern);
        if (kmp1(res, pattern, PI) != patternPositions) return "";
        for(int i = 0; i < res.size(); i++) {
            if(res[i] == '#') {
                any.push_back(i);
                res[i] = 'a';
            }
        }
        return kmp2(baseString, res, pattern, PI, any);
    }
};