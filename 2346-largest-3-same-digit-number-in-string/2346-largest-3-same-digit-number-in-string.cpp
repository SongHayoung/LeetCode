class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "";
        for(int i = 0; i < num.length() - 2; i++) {
            if(num[i] == num[i+1] and num[i+1] == num[i+2]) {
                res = max(res, string(3,num[i]));
            }
        }
        return res;
    }
};