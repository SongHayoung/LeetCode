class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.length() < num2.length()) return addStrings(num2,num1);
        int i = num1.length() - 1, j = num2.length() - 1, app = 0;
        while(i >= 0 and j >= 0) {
            int sum = (num1[i] & 0b1111) + (num2[j] & 0b1111) + app;
            app = sum / 10;
            sum %= 10;
            num1[i] = sum | 0b110000;
            i--,j--;
        }
        while(i >= 0 and app) {
            int sum = (num1[i] & 0b1111) + app;
            app = sum / 10;
            sum %= 10;
            num1[i] = sum | 0b110000;
            i--;
        }
        if(i == -1 and app > 0) {
            return "1" + num1;
        } else {
            return num1;
        }
    }
};