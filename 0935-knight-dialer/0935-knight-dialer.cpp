#define MOD 1000000007
class Solution {
    vector<vector<int>> reachAble{
            {4, 6}, //0
            {6, 8}, //1
            {7, 9}, //2
            {4, 8}, //3
            {3, 9, 0}, //4
            {}, //5
            {1, 7, 0}, //6
            {2, 6}, //7
            {1, 3}, //8
            {2, 4} //9
    };
public:
    int knightDialer(int n) {
        vector<int> res(10, 1), tmp(10);
        while(--n) {
            for (int i = 0; i < 10; ++i) {
                tmp[i] = accumulate(begin(reachAble[i]), end(reachAble[i]), 0, [&](int origin, int from) {return (origin + res[from]) % MOD;});
            }
            res = tmp;
        }

        return accumulate(begin(res), end(res), 0, [](int origin, int n) {return (origin + n) % MOD;});
    }
};