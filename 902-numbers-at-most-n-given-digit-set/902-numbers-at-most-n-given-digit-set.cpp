class Solution {
    int getHeadDigit(int n) {
        while(n >= 10)
            n /= 10;
        return n;
    }
    int helper2(vector<int>& digits, int n) {
        string num = to_string(n);
        unordered_set<int> s(digits.begin(), digits.end());
        int res = 0;
        for(int i = 0; i < num.length() - 1; i++) {
            int count = 0;
            for(auto d : s)
                count += (d < (num[i]-'0'));
            res += pow(digits.size(), num.length() - i - 1) * count;
            if(!s.count(num[i]&0b1111)) return res;
        }
        for(auto d : digits) {
            res += (d <= n % 10);
        }
        return res;
    }
    int helper(vector<int>& digits, int n) {
        if(n < 10) {
            int count = 0;
            for(auto d : digits) {
                count += (d <= n);
            }
            return count;
        }
        long d = 10;
        int res = 0;
        int c = 0;
        while(d <= n) {
            res = res * digits.size() + digits.size();
            d *= 10;
        }
        return res + helper2(digits,n);
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int> d;
        for(auto digit : digits) {
            d.push_back(stoi(digit));
        }
        return helper(d,n);
    }
};