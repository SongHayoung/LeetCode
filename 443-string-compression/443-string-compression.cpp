class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0;
        vector<char> _chars;
        pair<char, int> p{chars.front(), 0};
        for(auto& c : chars) {
            if(p.first == c) p.second++;
            else {
                string num = to_string(p.second);
                res += p.second == 1 ? 1 : num.length() + 1;
                _chars.push_back(p.first);
                if(num != "1")
                    for(auto& n : num) _chars.push_back(n);
                p = {c, 1};
            }
        }
        string num = to_string(p.second);
        res += p.second == 1 ? 1 : num.length() + 1;
        _chars.push_back(p.first);
        if(num != "1")
            for(auto& n : num) _chars.push_back(n);
        chars = _chars;
        return res;
    }
};