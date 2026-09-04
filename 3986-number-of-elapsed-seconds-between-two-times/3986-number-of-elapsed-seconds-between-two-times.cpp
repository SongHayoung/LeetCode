class Solution {
    array<int,3> parse(string& s) {
        auto digitOf = [&](char ch) {
            return ch - '0';
        };
        return {digitOf(s[0]) * 10 + digitOf(s[1]), digitOf(s[3]) * 10 + digitOf(s[4]), digitOf(s[6]) * 10 + digitOf(s[7])};
    }
    long long time(string& str) {
        auto [h,m,s] = parse(str);
        return h * 3600 + m * 60 + s;
    }
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        return time(endTime) - time(startTime);
    }
};