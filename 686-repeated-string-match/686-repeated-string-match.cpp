class Solution {
private:
    int isTwo(string &a, string &b) {
        size_t pos = a.length() - 1;
        for(; b.find(a.substr(pos)) != string::npos; --pos) {}
        for(int aPos = pos, bPos = a.length() - pos; aPos >= 0 && bPos < b.length(); --aPos, ++bPos) {
            if(a[aPos] != b[bPos])
                return -1;
        }
        return 2;
    }

    int getLoop(string &a, string &b, size_t& pos) {
        int res = pos ? 1 : 0, i = 0;
        for(; pos < b.length(); pos++, i++) {
            if(b[pos] != a[i])
                return -1;
            if(i == a.length() - 1) {
                i = -1;
                res++;
            }
        }

        return i ? res + 1 : res;
    }
public:
    int repeatedStringMatch(string a, string b) {
        size_t pos = b.find(a, 0), prev = 0;
        return b.length() <= a.length() ? a.find(b) != string::npos ? 1 : isTwo(a, b) : pos != string::npos && a.find(b.substr(0, pos), 0) ==  string::npos ? -1 : pos == string::npos ? isTwo(b, a) : getLoop(a, b, pos);
    }
};