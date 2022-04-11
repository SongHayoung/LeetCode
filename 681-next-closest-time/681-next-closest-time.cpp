class Solution {
    pair<int, int> res;
    int diff = 60 * 24;
    int __compare(int bh, int bm, int sh, int sm) {
        if(bm >= sm) {
            bm -= sm;
        } else {
            bm = bm - sm + 60;
            bh -= 1;
        }
        bh -= sh;
        return bh * 60 + bm;
    }
    int compare(pair<int,int>& origin, int h, int m) {
        int oh = origin.first, om = origin.second;
        if(oh > h or (oh == h and om >= m)) {
            return 60*24 - __compare(oh,om,h,m);
        } else {
            return __compare(h,m,oh,om);
        }
    }
    void backtracking(pair<int,int>& origin, vector<bool>& digits, int hour, int minute, int p) {
        if(hour >= 24 or minute >= 60) return; //invalid
        if(p == 4) {
            int cmp = compare(origin,hour,minute);
            if(diff > cmp) {
                diff = cmp;
                res = {hour, minute};
            }
            
        } else {
            for(int i = 0; i < 10; i++) {
                if(digits[i]) {
                    int nxtHour = hour, nxtMinute = minute;
                    if(p == 0) nxtHour += i * 10;
                    else if(p == 1) nxtHour += i;
                    else if(p == 2) nxtMinute += i * 10;
                    else nxtMinute += i;
                    backtracking(origin, digits, nxtHour, nxtMinute, p + 1);
                }
            }
        }
    }
    string to_time(int t) {
        if(t == 0) return "00";
        else if(t < 10) return "0" + to_string(t);
        else return to_string(t);
    }
public:
    string nextClosestTime(string time) {
        vector<bool> digit(10);
        digit[time[0]-'0'] = digit[time[1]-'0'] = digit[time[3]-'0'] = digit[time[4]-'0'] = true;
        pair<int, int> origin = {(time[0]&0b1111) * 10 + (time[1]&0b1111), (time[3]&0b1111) * 10 + (time[4]&0b1111)};
        res = origin;
        backtracking(origin, digit, 0, 0, 0);
    
        return to_time(res.first) + ":" + to_time(res.second);
    }
};