class Solution {
private:
    int getMaximumDigit(int num) {
        return num >= 1000? (num / 1000) * 1000 : num >= 100 ? (num / 100) * 100 : num >= 10 ? (num / 10) * 10 : num % 10;
    }
public:
    string intToRoman(int num) {
        stringstream solution;
        while(num) {
            int maximumDigit = getMaximumDigit(num);
            if(maximumDigit >= 1000) {
                num -= 1000;
                solution<<'M';
            } else if(maximumDigit >= 900) {
                num -= 900;
                solution<<"CM";
            } else if(maximumDigit >= 500) {
                num -= 500;
                solution<<'D';
            } else if(maximumDigit >= 400) {
                num -= 400;
                solution<<"CD";
            } else if(maximumDigit >= 100) {
                num -= 100;
                solution<<'C';
            } else if(maximumDigit >= 90) {
                num -= 90;
                solution<<"XC";
            } else if(maximumDigit >= 50) {
                num -= 50;
                solution<<'L';
            } else if(maximumDigit >= 40) {
                num -= 40;
                solution<<"XL";
            } else if(maximumDigit >= 10) {
                num -= 10;
                solution<<'X';
            } else if(maximumDigit >= 9) {
                num -= 9;
                solution<<"IX";
            } else if(maximumDigit >= 5) {
                num -= 5;
                solution<<'V';
            } else if(maximumDigit >= 4) {
                num -= 4;
                solution<<"IV";
            } else {
                num -= 1;
                solution<<'I';
            }
        }

        return solution.str();
    }
};