class Solution {
public:
    bool isDecomposable(string s) {
        bool fl = false;
        while(s.size()) {
            char ch = s.back();
            int cnt = 0;
            while(s.size() and s.back() == ch) s.pop_back(), cnt++;
            if(cnt % 3 == 0) continue;
            if((cnt - 2) % 3 or fl) return false;
            fl = true;
        }
        return fl;
    }
};