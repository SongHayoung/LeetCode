class Solution {
    vector<char> number{'1','6','9','8','0'};
    int res = 0;
    bool bigger(string origin, string target) {
        if(origin.length() != target.length()) return origin.length() > target.length();
        for(int i = 0; i < origin.length(); i++) {
            if (origin[i] > target[i]) return true;
            else if(origin[i] < target[i]) return false;
        }
        return true; //origin == target
    }
    string rotate(string s) {
        string res = "";
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] == '6') res+='9';
            else if(s[i] == '9') res+='6';
            else res += s[i];
        }
        return res;
    }
    void backTracking(string& s, int len, bool odd, string& lo, string& hi) {
        if(s.length() == len) {
            string rev = rotate(s);
            string num;
            if(odd) {
                num = s + '8' + rev;
            } else {
                num = s + rev;
            }
            res += (bigger(num, lo) && bigger(hi, num));
            if(odd) {
                num[len] = '0';
                res += (bigger(num, lo) && bigger(hi, num));
                num[len] = '1';
                res += (bigger(num, lo) && bigger(hi, num));
            }
        } else {
            for(int i = 0; i < 5; i++) {
                if(s.length() == 0 and i == 4) continue;
                s += number[i];
                backTracking(s,len,odd,lo,hi);
                s.pop_back();
            }
        }
    }
public:
    int strobogrammaticInRange(string low, string high) {
        string tmp = "";
        if(low.length() != 1) {
            backTracking(tmp, low.length()>>1, low.length() & 1, low, high);
        }
        if(low.length() != high.length()) {
            backTracking(tmp, high.length()>>1, high.length() & 1, low, high);
        }
        for(int i = low.length() + 1; i < high.length(); i++) {
            //first of(1,6,8,9) and combination of(0,1,6,8,9) and if length is odd, combination of(0,1,8)
            res += 4 * pow(5, (i>>1) - 1) * (i & 1 ? 3 : 1);
        }
        return res
               + (bigger("8", low) and bigger(high, "8"))
               + (bigger("1", low) and bigger(high, "1"))
               + bigger("0", low);
    }
};
