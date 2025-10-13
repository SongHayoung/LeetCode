
class Solution {
    int abc(string& s) {
        int cnt[3]{0,}, res = 0;
        map<pair<int,int>,int> freq{{{0,0},-1}};
        for(int i = 0; i < s.length(); i++) {
            cnt[s[i]-'a']++;
            pair<int,int> now = {cnt[0] - cnt[1], cnt[0] - cnt[2]};
            if(freq.count(now)) res = max(res, i - freq[now]);
            else freq[now] = i;
        }
        return res;
    }
    int single(string& s) {
        int res = 1;
        for(int i = 1, cons = 1; i < s.length(); i++) {
            if(s[i] == s[i-1]) cons++;
            else cons = 1;
            res = max(res, cons);
        }
        return res;
    }
    int two(string& s, int skip) {
        int cnt[3]{0,}, res = 0;
        map<int,int> freq{{0,-1}};
        vector<int> use;
        for(int i = 0; i < 3; i++) if(i != skip) use.push_back(i);
        for(int i = 0; i < s.length(); i++) {
            cnt[s[i]-'a']++;
            if(cnt[skip]) {
                cnt[0] = cnt[1] = cnt[2] = 0;
                freq = {{0,i}};
            } else {
                int now = cnt[use[0]] - cnt[use[1]];
                if(freq.count(now)) res = max(res, i - freq[now]);
                else freq[now] = i;
            }
        }
        return res;
    }
public:
    int longestBalanced(string s) {
        return max({abc(s), single(s), two(s,0), two(s,1), two(s,2)});
    }
};