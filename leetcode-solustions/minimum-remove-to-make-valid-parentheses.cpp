
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        list<int> l;
        for(int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case '(' : l.push_back(i); break;
                case ')' : if(!l.empty()) l.pop_back(); else s[i] = '*'; break;
            }
        }
        for(auto& pos : l) s[pos] = '*';
        stringstream ss;
        for(auto& c : s)
            if(c != '*')
                ss << c;
        return ss.str();
    }
};
