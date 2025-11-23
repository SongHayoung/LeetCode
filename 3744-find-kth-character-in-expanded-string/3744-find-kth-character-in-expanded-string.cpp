class Solution {
public:
    char kthCharacter(string s, long long k) {
        int len = 0;
        k++;
        for(auto& ch : s) {
            if(isalpha(ch)) len++;
            else len = 0;
            k -= max(len, 1);
            if(k <= 0) return ch;
        }
        return '#';
    }
};