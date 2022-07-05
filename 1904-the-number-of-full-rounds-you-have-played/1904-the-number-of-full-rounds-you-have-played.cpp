class Solution {
    pair<int, int> lowerBound(string s) {
        int hour = stoi(s.substr(0,2));
        int minute = stoi(s.substr(3));
        
        if(minute < 15) minute = 0;
        else if(minute < 30) minute = 15;
        else if(minute < 45) minute = 30;
        else minute = 45;
        
        return {hour, minute};
    }
    pair<int, int> upperBound(string s) {
        int hour = stoi(s.substr(0,2));
        int minute = stoi(s.substr(3));
        
        if(minute == 0) minute = 0;
        else if(minute <= 15) minute = 15;
        else if(minute <= 30) minute = 30;
        else if(minute <= 45) minute = 45;
        else {
            minute = 0;
            hour += 1;
            if(hour == 24) hour = 0;
        }
        return {hour, minute};
    }
    bool fin(int sh, int sm, int eh, int em) {
        if(sh == eh) return em == sm;
        return false;
    }
    pair<int, int> parse(string s) {
        int hour = stoi(s.substr(0,2));
        int minute = stoi(s.substr(3));
        
        return {hour, minute};
    }
    bool canPlay(string& s, string& e) {
        auto [sh, sm] = parse(s);
        auto [eh, em] = parse(e);
        if(sh == eh) {
            if(em < sm) return true;
            return em - sm >= 15;
        }
        return true;
    }
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        if(!canPlay(loginTime, logoutTime)) return 0;
        auto [sh, sm] = upperBound(loginTime);
        auto [eh, em] = lowerBound(logoutTime);
        int res = 0;
        while(!fin(sh,sm,eh,em)) {
            res += 1;
            sm += 15;
            if(sm == 60) {
                sm = 0;
                sh += 1;
            }
            if(sh == 24) sh = 0;
        }
        return res;
    }
};