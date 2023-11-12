
class Solution {
    bool ok(vector<string>& A) {
        vector<int> time;
        for(auto& s : A) {
            int t = (s[0] - '0') * 10 + s[1] - '0';
            t *= 60;
            t += (s[2] - '0') * 10 + s[3] - '0';
            time.push_back(t);
        }
        sort(begin(time), end(time));
        for(int i = 0, j = 0; j < time.size(); i++) {
            while(j < time.size() and time[i] + 60 > time[j]) j += 1;
            if(j - i >= 3) return true;
        }
        return false;
    }
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> res;
        unordered_map<string, vector<string>> mp;
        for(auto& a : access_times) {
            mp[a[0]].push_back(a[1]);
        }
        for(auto& [k,v] : mp) {
            if(ok(v)) res.push_back(k);
        }
        
        return res;
    }
};