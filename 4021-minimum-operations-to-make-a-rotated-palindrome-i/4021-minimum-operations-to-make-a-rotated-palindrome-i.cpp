class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int res = INT_MAX;

        for(int shift = 0; shift < n; shift++) {
            int cost = shift;

            for(int i = 0; i < n / 2; i++) {
                int a = s[(shift + i) % n] - 'a';
                int b = s[(shift + n - 1 - i) % n] - 'a';

                cost += min((a - b + 26) % 26,
                            (b - a + 26) % 26);
            }

            res = min(res, cost);
        }

        return res;
    }
};