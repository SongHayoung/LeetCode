class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        auto ok = [](int n) {
            while(n) {
                if(n % 10 == 0) return false;
                n /= 10;
            }
            return true;
        };
        for(int i = 1; i < n; i++) {
            if(ok(i) and ok(n-i)) return {i,n-i};
        }
        return {};
    }
};