class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        vector<int> res {0,1};
        for(int i = 2,counter = 2; i <= n; i++) {
            if(i == counter * 2) counter *= 2;
            res.push_back(1 + res[i - counter]);
        }
        return res;
    }
};