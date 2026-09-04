
class Solution {
    unordered_set<char> vowel{'a','e','i','o','u'};
    int countVowels(string& s) {
        int res = 0;
        for(auto& ch : s) {
            if(vowel.count(ch)) res++;
        }
        return res;
    }
public:
    string reverseWords(string s) {
        assert(s[0] != ' ');
        string res = "", chunk = "";
        s.push_back(' ');
        int vowels = -1;
        for(auto& ch : s) {
            if(ch == ' ') {
                if(vowels == -1) {
                    vowels = countVowels(chunk);
                } else {
                    if(countVowels(chunk) == vowels) {
                        reverse(begin(chunk), end(chunk));
                    }
                }
                res += chunk;
                chunk = "";
                res.push_back(' ');
            } else {
                chunk.push_back(ch);
            }
        }


        res.pop_back();
        return res;
    }
};