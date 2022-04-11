class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        list<char> chars;
        for(auto ch : s) {
            if(ch == '-') continue;
            else if(isdigit(ch)) chars.push_back(ch);
            else if('a' <= ch and ch <= 'z') chars.push_back('A' - 'a' + ch);
            else chars.push_back(ch);
        }
        int repeat = k;
        for(auto it = prev(end(chars)); it != begin(chars); it--) {
            if(repeat == 1) {
                
                chars.insert(it, '-');
                it--;
                repeat = k;
            } else {
                repeat--;
            }
        }
        stringstream ss;
        for(auto ch : chars) {
            ss<<ch;
        }
        return ss.str();
    }
};