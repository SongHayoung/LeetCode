class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> us;
        int res = 0;
        for(int i = 1; us.size() < n; i++) {
            if(us.count(k - i)) continue;
            us.insert(i);
            res += i;
        }
        return res;
    }
};