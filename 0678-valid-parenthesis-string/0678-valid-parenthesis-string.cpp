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
        int cnt = 0;
        while(o.size()) {
            while(s.size() and s.back() > o.back()) {
                s.pop_back();
                cnt++;
            }
            if(!cnt) return false;
            cnt--;
            o.pop_back();
        }
        return true;
    }
};