class Solution {
public:
    string smallestNumber(long long n) {
        if(n == 1) return "1";
        vector<int> cnt(10);
        auto work = [&](int x) {
            while(n % x == 0) {
                n /= x;
                cnt[x] += 1;
            }
        };
        for(auto x : {8,9,6,4,2,3,5,7}) work(x);
        if(n != 1) return "-1";
        string res = "";
        for(int i = 2; i <= 9; i++) res += string(cnt[i],'0' + i);
        return res;
    }
};