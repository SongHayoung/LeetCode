class Solution {
    vector<string> res;
    
    void helper(string& num, string b, int p, long long target, long long prv, long long eval) {
        if(num.length() == p) {
            if(eval == target) {
                res.push_back(b);
            }
        } else {
            long long cur = 0;
            string B = "";
            for(int i = p; i < num.length(); i++) {
                if(i != p and num[p] == '0') break;
                cur = cur * 10 + (num[i] & 0b1111);
                B += num[i];
                if(p == 0) {
                    helper(num, b + B, i + 1, target, cur, cur);
                } else {
                    helper(num, b + "+" + B, i + 1, target, cur, eval + cur);
                    helper(num, b + "-" + B, i + 1, target, -cur, eval - cur);
                    helper(num, b + "*" + B, i + 1, target, prv * cur, eval - prv + prv * cur);
                }
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        helper(num, "", 0, target, 0, 0);
        return res;
    }
};