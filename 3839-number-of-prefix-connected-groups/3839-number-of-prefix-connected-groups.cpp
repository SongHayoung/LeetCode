class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(auto& w : words) {
            if(w.length() < k) continue;
            else freq[w.substr(0,k)]++;
        }
        int res = 0;
        for(auto& [k,v] : freq) res += (v >= 2);
        return res;
    }
};