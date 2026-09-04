class Solution {
public:
    int countMonobit(int n) {
        int res = 1;
        for(int i = 1; i <= n; i = i * 2 + 1) res++;
        return res;
    }
};