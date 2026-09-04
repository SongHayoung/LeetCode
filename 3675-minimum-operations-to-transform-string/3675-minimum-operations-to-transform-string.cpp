class Solution {
public:
    int minOperations(string s) {
        int res = 0;
        for(auto& ch : s) {
            if(ch != 'a') res = max(res, 26 - ch + 'a');
        }
        return res;
    }
};