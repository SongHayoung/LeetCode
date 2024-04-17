class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        for(auto& t : tasks) freq[t]++;
        int res = 0;
        for(auto& [_,v] : freq) {
            if(v == 1) return -1;
            res += v / 3;
            v %= 3;
            if(v) res += 1;
        }
        return res;
    }
};