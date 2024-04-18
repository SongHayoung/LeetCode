class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "0";
        for(int i = num1.size() - 1; i >= 0; i--) {
            int carry = 0, pos = num1.size() - i - 1;
            for(int j = num2.size() - 1; j >= 0; j--) {
                int val = (num1[i] - '0') * (num2[j] - '0') + carry;
                if(res.size() == pos) res.push_back('0');
                val = val + res[pos] - '0';
                res[pos] = val % 10 + '0';
                carry = val / 10;
                pos++;
            }
            while(carry) {
                if(res.size() == pos) res.push_back('0');
                int val = carry + res[pos] - '0';
                res[pos] = val % 10 + '0';
                carry = val / 10;
                pos++;
            }
        }
        while(res.size() > 1 and res.back() == '0') res.pop_back();
        reverse(begin(res), end(res));
        return res;
    }
};