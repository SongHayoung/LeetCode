class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> ans(num1.length() + num2.length(), 0);
        for(int i = 0; i < num1.length(); i++) {
            for(int j = 0; j < num2.length(); j++) {
                ans[i + j] += (num1[i] & 0b1111) * (num2[j] & 0b1111);
            }
        }
        int carry = 0;
        for(int i = 0; i < ans.size(); i++) {
            ans[i] += carry;
            carry = ans[i] / 10;
            ans[i] %= 10;
        }
        while(!ans.back()) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());

        stringstream ss;
        for(auto digit : ans) {
            ss<<digit;
        }
        return ss.str();
    }
};