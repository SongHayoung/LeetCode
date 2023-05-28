class Solution {
public:
    string removeTrailingZeros(string num) {
        while(num.size() and num.back() == '0') num.pop_back();
        return num;
    }
};