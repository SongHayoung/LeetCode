class Solution {
    int parse(string& s) { //string to time with minites;
        return ((s[0] & 0b1111)*10 + (s[1] & 0b1111)) * 60 + (s[3] & 0b1111) * 10 + (s[4] & 0b1111);
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        if(timePoints.size() >= 1441) return 0; //duplications
        int res = INT_MAX;
        set<int> s;
        for(auto& time : timePoints) {
            int minute = parse(time);
            if(s.empty()) { s.insert(minute);continue; }
            if(!res) return res;
            auto it = s.lower_bound(minute);
            if(it != s.end()) { //after minute
                res = min(res, *it - minute);
            } else {
                res = min(res, *s.begin() + 1440 - minute);
            }

            if(it == s.begin()) { //before minute
                res = min(res, minute + 1440 - *prev(s.end()));
            } else {
                res = min(res, minute - *prev(it));
            }
            s.insert(minute);
        }
        return res;
    }
};