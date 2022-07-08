class Solution {
public:
    int numOfPairs(vector<string>& A, string target) {
        unordered_map<string, int> freq;
        for(auto& a : A) freq[a]++;
        int res = 0;
        for(int i = 1; i < target.length(); i++) {
            string a = target.substr(0,i), b = target.substr(i);
            res += freq[a] * (freq[b] - (a == b));
        }
        return res;
    }
};