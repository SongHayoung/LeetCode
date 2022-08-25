class Solution {
    unordered_set<int> A;
    void helper(long long now, long long l, long long r) {
        if(now > r) return;
        if(l <= now) A.insert(now);
        int c = now % 10;
        if(c != 9)
            helper(now * 10 + c + 1, l, r);
        if(c != 0)
            helper(now * 10 + (c - 1 + 10) % 10, l, r);
    }
public:
    vector<int> countSteppingNumbers(int low, int high) {
        for(int i = 0; i <= 9; i++)
            helper(i, low, high);
        vector<int> res(begin(A), end(A));
        sort(begin(res),end(res));
        return res;
    }
};