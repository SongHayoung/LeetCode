class Solution {
public:
    int splitNum(int num) {
        long long res = 0, po = 1;
        string s = to_string(num);
        sort(begin(s), end(s));
        while(s.length()) {
            if(s.length() == 1) {
                res += (s.back() - '0') * po;
                s.pop_back();
            } else {
                res += (s.back() - '0') * po;
                s.pop_back();
                res += (s.back() - '0') * po;
                s.pop_back();
            }
            po *= 10;
        }
        return res;
    }
};
