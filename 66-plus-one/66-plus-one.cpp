class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int append = 1;
        for(int i = digits.size() - 1; i >= 0 and append; i--) {
            digits[i] += append;
            if(digits[i] == 10) {
                digits[i] = 0;
                append = 1;
            } else append = 0;
        }
        if(append == 1) {
            vector<int> res{append};
            res.insert(res.end(), digits.begin(), digits.end());
            return res;
        } else return digits;
    }
};