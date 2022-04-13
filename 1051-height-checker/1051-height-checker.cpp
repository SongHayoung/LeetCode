class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int res = 0;
        unordered_map<int, int> counter;
        for(auto n : heights) {
            counter[n]++;
        }
        for(int i = 1, j = 0; i <= 100 and j < heights.size(); j++) {
            while(i < 100 and (!counter.count(i) or counter[i] == 0)) i++;
            if(i == heights[j]) res++;
            counter[i]--;
        }
        return heights.size() - res;
    }
};