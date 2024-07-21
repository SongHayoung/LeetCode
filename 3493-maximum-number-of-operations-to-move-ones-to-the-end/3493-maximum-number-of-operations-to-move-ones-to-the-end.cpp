
class Solution {
public:
    int maxOperations(string& s) {
        int res = 0, o = 0, fl = false;
        s.push_back('1');
        for(auto& ch : s) {
            if(ch == '1') {
                if(fl) res += o;
                o++;
                fl = false;
            } else fl = true;
        }
        return res;
    }
};