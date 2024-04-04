class Solution {
public:
    int maxDepth(string s) {
        int res = 0, dep = 0;
        for(auto& ch : s) {
            if(ch == '(') {
                res = max(res, ++dep);
            } else if(ch == ')') --dep;
        }
        return res;
    }
};