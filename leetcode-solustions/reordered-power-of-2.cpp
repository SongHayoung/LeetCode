class Solution {
public:
    bool reorderedPowerOf2(int N) {
        map<int, set<map<int, int>>> powOfTwo;
        for(long start = 2; start <= INT_MAX; start<<=1) {
            int len = 0;
            long num = start;
            map<int, int> numMap;
            while(num) {
                numMap[num % 10]++;
                len++;
                num /= 10;
            }
            powOfTwo[len].insert(numMap);
        }

        int len = 0;
        map<int, int> m;
        while(N) {
            m[N % 10]++;
            len++;
            N /= 10;
        }

        return powOfTwo[len].count(m);
    }
};
