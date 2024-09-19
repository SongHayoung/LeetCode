class Solution {
    unordered_map<string, vector<int>> dp;
public:
    vector<int> diffWaysToCompute(string& exp) {
        if(dp.count(exp)) return dp[exp];
        vector<int>& res = dp[exp];
        for(int i = 0; i < exp.length(); i++) {
            if(!isdigit(exp[i])) {
                string left = exp.substr(0,i);
                string right = exp.substr(i + 1);
                vector<int> leftResult = diffWaysToCompute(left);
                vector<int> rightResult = diffWaysToCompute(right);
                for(int l : leftResult) {
                    for(int r : rightResult) {
                        if(exp[i] == '+') {
                            res.push_back(l + r);
                        } else if(exp[i] == '-') {
                            res.push_back(l - r);
                        } else {
                            res.push_back(l * r);
                        }
                    }
                }
            }
        }
        
        if(res.empty()) {
            res.push_back(stoi(exp));
        }
        return res;
    }
};