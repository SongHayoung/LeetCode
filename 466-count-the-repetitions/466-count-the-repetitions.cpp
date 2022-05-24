class Solution {
    unordered_map<char, vector<int>> mp;
    pair<int, int> helper(string& s, int startAt) {
        int repeat = 0;
        for(int i = 0; i < s.length(); i++) {
            auto& vec = mp[s[i]];
            if(startAt < vec.back()) {
                startAt = *upper_bound(begin(vec), end(vec), startAt);
            } else {
                repeat++;
                startAt = vec[0];
            }
        }
        
        return {repeat, startAt};
    }
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int res = 0, gcd = __gcd(n1, n2);
        n1 /= gcd, n2 /= gcd;
        int n = s1.length(), m = s2.length();
        vector<pair<int, int>> repeater;
    
        for(int i = 0; i < n; i++) {
            mp[s1[i]].push_back(i);
        }
        for(int i = 0; i < s2.length(); i++) {
            if(!mp.count(s2[i])) return 0;
        }
        for(int i = 0; i < n; i++) {
            auto repeat = helper(s2, i - 1);
            repeater.push_back(repeat);
        }
        
        int i = 0, rep = 0;
        while(n1){
            auto repeat = repeater[i];
            n1 -= repeater[i].first;
            if(n1 <= 0) break;
            i = (repeater[i].second + 1);
            if(i == s1.length()) {
                n1 -= 1;
                i = 0;
            }
            if(++rep == n2) {
                res++;
                rep = 0;
            }
        }
        
        return res;
    }
};