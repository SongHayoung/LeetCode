class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = 0, prev = 0;
        for(auto& n : target) {
            res += max(n - prev, 0);
            prev = n;
        }
        return res;
    }
};