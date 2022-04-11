class Solution {
    string largeSum(string a, string b) {
        string ret = "";
        int aPos = a.length() - 1, bPos = b.length() - 1, additional = 0;

        while(aPos >= 0 || bPos >= 0) {
            int num = additional;

            if(aPos >= 0) {
                num += a[aPos--] & 0b1111;
            }

            if(bPos >= 0) {
                num += b[bPos--] & 0b1111;
            }

            if(num >= 10) {
                num -= 10;
                additional = 1;
            } else {
                additional = 0;
            }

            ret.insert(0, string(1, num|0b110000));
        }

        if(additional)
            ret.insert(0, "1");

        return ret;
    }

    bool isAddable(string prev, string cur, int pos, string &num) {
        if(pos == num.length())
            return true;

        string sum = largeSum(prev, cur);

        if(pos + sum.length() > num.length())
            return false;

        for(int i = pos; i < pos + sum.length(); i++) {
            if(num[i] != sum[i - pos])
                return false;
        }

        return isAddable(cur, sum, pos + sum.length(), num);
    }
public:
    bool isAdditiveNumber(string num) {
        if(num.length() > 2) {
            for (int i = 1; i <= num.length() / 2; i++) {
                if(num[0] == '0' && i != 1)
                    break;
                for (int j = i + 1; j <= i + num.length() / 2; j++) {
                    if((num[i] == '0' && j - i != 1) || j == num.length())
                        break;

                    if (isAddable(num.substr(0, i), num.substr(i, j - i), j, num))
                        return true;
                }
            }
        }

        return false;
    }
};