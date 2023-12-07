class Solution {
public:
    string largestOddNumber(string num) {
        while(num.length() && !((num.back() & 0b0001)))
            num.pop_back();
        return num;
    }
};