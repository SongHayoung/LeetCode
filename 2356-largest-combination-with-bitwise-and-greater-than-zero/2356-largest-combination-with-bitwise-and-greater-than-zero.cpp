class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> count(32, 0);
        for(auto& c : candidates) {
            for(int i = 0; i < 32; i++) {
                if(c & (1<<i))
                    count[i]++;
            }
        }
        return *max_element(begin(count), end(count));
    }
};