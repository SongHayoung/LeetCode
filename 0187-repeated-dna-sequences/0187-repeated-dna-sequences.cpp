class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<long long, long long> freq;
        unordered_map<char,int> val;
        val['A'] = 0;
        val['C'] = 1;
        val['G'] = 2;
        val['T'] = 3;
        
        long long now = 0;
        for(long long i = 0, po = 1; i < s.length(); i++) {
            now += val[s[i]] * po;
            if(i >= 9) {
                freq[now]++;
                now /= 4;
            } else po = po * 4;
        }
        unordered_set<long long> us;
        for(auto& [k,v] : freq) if(v >= 2) us.insert(k);
        now = 0;
        vector<string> res;
        for(long long i = 0, po = 1; i < s.length(); i++) {
            now += val[s[i]] * po;
            if(i >= 9) {
                if(us.count(now)) {
                    us.erase(now);
                    string x = "";
                    for(int j = i - 9; j <= i; j++) x.push_back(s[j]);
                    res.push_back(x);
                }
                now /= 4;
            } else po = po * 4;
        }
        return res;
    }
};