class Solution {
public:
    long long countSubstrings(string s) {
        vector<long long> mod7(7), mod9(9);
        long long n = s.length(), res = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            vector<long long> mod77(7), mod99(9);
            long long x = s[i]-'0';
            sum = (sum * 10 + x) % 1000;
            mod7[0]++, mod9[0]++;
            for(int i = 0; i < 7; i++) {
                mod77[(i * 10 + x) % 7] += mod7[i];
            }
            for(int i = 0; i < 9; i++) {
                mod99[(i + x) % 9] += mod9[i];
            }
            swap(mod9,mod99);
            swap(mod7,mod77);
            if(x == 1 or x == 2 or x == 5) res += (i + 1);
            if(x == 3 or x == 6) res += mod9[0] + mod9[3] + mod9[6];
            if(x == 9) res += mod9[0];
            if(x == 4) {
                res++;
                if(i and sum % 4 == 0) res += i;
            }
            if(x == 8) {
                res++;
                if(i >= 1 and sum % 100 % 8 == 0) res += 1;
                if(i >= 2 and sum % 8 == 0) res += i - 1;
            }
            if(x == 7) {
                res += mod7[0];
            }
        }
        return res;
    }
};