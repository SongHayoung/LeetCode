class Solution {
private:
    string getMax(map<char, int>& digits) {
        stringstream ss;
        for(char ch = '9'; ch >= '0'; ch--) {
            for(int i = 0; i < digits[ch]; i++)
                ss<<ch;
        }
        return ss.str();
    }

    void recursive(string& maxNum, string& num, map<char, int>& digits, string cur) {
        if(cur.length() == maxNum.length()) {
            if(stol(cur) > stol(num))
                maxNum = cur;
            return;
        }

        for(char ch = '0'; ch <= '9'; ch++) {
            if(digits[ch]) {
                int pos;
                int maxFlag = 0, minFlag = 0;
                for(pos = 0; pos < cur.length(); pos++) {
                    if(maxFlag == 0) {
                        if(maxNum[pos] < cur[pos])
                            maxFlag = -1;
                        else if(maxNum[pos] > cur[pos])
                            maxFlag = 1;
                    }
                    if(minFlag == 0) {
                        if(num[pos] < cur[pos])
                            minFlag = 1;
                        else if(num[pos] > cur[pos])
                            minFlag = -1;
                    }
                }
                if(maxFlag == 0) {
                    maxFlag = maxNum[pos] - ch;
                }

                if(minFlag == 0) {
                    minFlag = ch - num[pos];
                }

                if(maxFlag >= 0 && minFlag >= 0) {
                    digits[ch]--;
                    recursive(maxNum, num, digits, cur + ch);
                    digits[ch]++;
                }
            }
        }
        return;
    }
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        map<char, int> digits;
        bool flag = true;
        for(int i = 1; i < num.size(); i++) {
            if(num[i] > num[i - 1])
                flag = false;
            digits[num[i]]++;
        }
        digits[num[0]]++;

        if(flag)
            return -1;

        string maxNum = getMax(digits);
        recursive(maxNum, num, digits, "");
        long res = stol(maxNum);
        return res > INT_MAX ? -1 : res;
    }
};
