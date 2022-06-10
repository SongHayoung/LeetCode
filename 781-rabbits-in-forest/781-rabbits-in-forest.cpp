class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        for(auto& a : answers) freq[a]++;
        int res = 0;
        
        for(auto& [k, v] : freq) {
            int req = k + 1;
            res += max(1.0, ceil(1.0 * v / req)) * req;
            
        }
        
        return res;
    }
};