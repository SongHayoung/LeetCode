class Solution {
private:
    bool isPrime(int n) {
        int sqrtNum = sqrt(n);
        for(int i = 2; i <= sqrtNum; i++) {
            if(!(n % i))
                return false;
        }
        return true;
    }

    int recursive(string num, int &len, int &N) {
        if(len > num.length() * 2) {
            for(int i = 0; i <= 9; i++) {
                int ret = recursive(num + to_string(i), len, N);
                if(ret != -1)
                    return ret;
            }

            return -1;
        } else {
            for(int pos = len - num.length() - 1; pos >= 0; pos--) {
                num += num[pos];
            }
            
            int val = stoi(num);
            if(val >= N && isPrime(val)) {
                return val;
            }
            return -1;
        }
    }
public:
    int primePalindrome(int N) {
        if(N < 10) {
            for(int i = max(N, 2); i <= 11; i++) {
                if(isPrime(i))
                    return i;
            }
            return -1;
        }
        string num = to_string(N);
        for(int len = num.length(); len <= 9; len++) {
            for(int num = 1; num <= 9; num += 2) {
                int ret = recursive(to_string(num), len, N);
                if(ret != -1) {
                    return ret;
                }
            }
        }
        return -1;
    }
};