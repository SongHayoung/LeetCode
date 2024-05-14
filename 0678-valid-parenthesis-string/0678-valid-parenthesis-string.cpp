class Solution {
public:
    bool checkValidString(string S) {
        vector<int> o,s;
        for(int i = 0; i < S.length(); i++) {
            if(S[i] == '(') {
                o.push_back(i);
            } else if(S[i] == '*') {
                s.push_back(i);
            } else {
                if(o.size()) o.pop_back();
                else if(s.size()) s.pop_back();
                else return false;
            }
        }
        reverse(begin(o), end(o));
        reverse(begin(s), end(s));
        int cnt = 0;
        while(o.size()) {
            int mi = o.back();
            if(s.size()) mi = min(mi, s.back());
            if(o.back() == mi) cnt++, o.pop_back();
            else {
                if(cnt) cnt--;
                s.pop_back();
            }
        }
        return cnt <= s.size();
    }
};