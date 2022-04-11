class Solution {
    const int mod = 1337;
    bool isZero(vector<int>& b) {
        for(auto& num : b)
            if(num) return true;
        return false;
    }
    void div(vector<int>& b) {
        bool remainder = false;
        for(int i = 0; i < b.size(); i++) {
            int prev = b[i];
            b[i] >>= 1;
            if(remainder) b[i] += 5;
            remainder = prev & 1;
        }
    }
public:
    int superPow(long a, vector<int>& b) {
        long res = 1;
        while(isZero(b) && a != 1) {
            if(b.back() & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            div(b);
        }
        return res;
    }
};