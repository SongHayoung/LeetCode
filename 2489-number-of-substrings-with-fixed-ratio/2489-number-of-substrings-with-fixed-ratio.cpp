class Solution {
public:
    long long fixedRatio(string s, int num1, int num2) {
        unordered_map<long long, int> freq{{0, 1}};
        long long res = 0, now = 0;
        for (auto& ch : s) {
            if (ch == '0') now += num2;
            else now -= num1;
            res += freq[now];
            freq[now] += 1;
        }
        return res;
    }
};