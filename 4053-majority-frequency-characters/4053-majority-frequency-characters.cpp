class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char, int> freq;
        for(auto& ch : s) freq[ch]++;
        unordered_map<int, string> rfreq{{0,""}};
        for(auto& [k,v] : freq) rfreq[v].push_back(k);
        int best = 0;
        for(auto& [cnt, str] : rfreq) {
            if(str.size() > rfreq[best].size()) best = cnt;
            else if(str.size() == rfreq[best].size()) best = max(best, cnt);
        }
        return rfreq[best];
    }
};