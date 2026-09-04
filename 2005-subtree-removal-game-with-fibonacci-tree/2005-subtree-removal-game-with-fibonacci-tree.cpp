class Solution {
public:
    bool findGameWinner(int n) {
        if (n == 1) return false;
        vector<int> sg(n + 1);
        sg[0] = 0;
        sg[1] = 1;

        for (int i = 2; i <= n; i++) {
            sg[i] = (sg[i - 1] ^ sg[i - 2]) + 1;
        }

        return (sg[n - 1] ^ sg[n - 2]);
    }
};