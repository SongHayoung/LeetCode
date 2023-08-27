class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        unordered_set<long long> exc; 
        long long res = 0;
        for(long long i = 1, cnt = 0; cnt < n; i++) {
            if(exc.count(i)) continue;
            res += i;
            exc.insert(target - i);
            cnt += 1;
        }
        return res;
    }
};