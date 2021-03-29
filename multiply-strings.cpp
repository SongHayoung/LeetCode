class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> ans(num1.length() + num2.length(), 0);
        for(int i = 0; i < num1.length(); i++) {
            if(num1[i] == '0') continue;
            int carry = 0;
            for(int j = 0; j < num2.length(); j++) {
                ans[i + j] += (num1[i] & 0b1111) * (num2[j] & 0b1111) + carry;
                carry = ans[i + j] / 10;
                ans[i + j] %= 10;
            }
            if(carry) {
                ans[i + num2.length()] += carry;
            }
        }
        while(!ans.back()) {
            ans.pop_back();
        }
        stringstream ss;
        for(int i = ans.size() - 1; i >= 0; i--)
            ss<<ans[i];
        
        return ss.str();
    }
};
