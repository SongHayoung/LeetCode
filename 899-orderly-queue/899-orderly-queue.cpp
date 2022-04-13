class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) {
            string res = s;
            for(int i = 0; i < s.length(); i++)
                res = min(res, s.substr(i) + s.substr(0,i));
            return res;
        } else {
            sort(begin(s),end(s));
            return s;
        }
    }
};