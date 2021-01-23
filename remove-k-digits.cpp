class Solution {
private:
    char getMinimum(map<char,list<int>> &chars, int maxPos) {
        int res = 10;
        for(auto p : chars) {
            if(!p.second.empty() && (p.first & 0b1111) < res && p.second.front() <= maxPos)
                res = (p.first & 0b1111);
        }
        return res | 0b110000;
    }
public:
    string removeKdigits(string num, int k) {
        if(k == 0)
            return num;
        if(k == num.length())
            return "0";
        stringstream res;
        map<char, list<int>> chars;
        int pos, prev = -1, len = 0;
        for(pos = 0; pos <= k + 1; pos++) {
            chars[num[pos]].push_back(pos);
        }

        while(len != num.length() - k) {
            char choosed = getMinimum(chars, k + len);
            for(int i = chars[choosed].front() + k; i > 0 && pos < num.length(); i--, pos++) {
                chars[num[pos]].push_back(pos);
            }

            prev = chars[choosed].front();

            for(auto p = chars.begin(); p != chars.end(); p++) {
                while(!p->second.empty() && p->second.front() <= prev) {
                    p->second.pop_front();
                }
            }

            res<<choosed;
            len++;
            if(num.length() - prev - 1 == num.length() - k - len) {
                res<<num.substr(prev + 1);
                break;
            }
        }
        string ret = res.str();
        for(pos = 0; pos < ret.length() && ret[pos] == '0'; pos++) {}
        if(pos != 0)
            ret = ret.substr(pos);
        return ret == "" ? "0" : ret;
    }
};
