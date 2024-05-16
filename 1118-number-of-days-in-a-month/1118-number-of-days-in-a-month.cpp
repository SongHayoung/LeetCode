class Solution {
public:
    int numberOfDays(int year, int month) {
        if(month == 2) {
            if(year % 4) return 28;
            if(year % 100) return 29;
            return year % 400 == 0 ? 29 : 28;
        }
        if(month <= 7) {
            return month & 1 ? 31 : 30;
        }
        return month & 1 ? 30 : 31;
    }
};