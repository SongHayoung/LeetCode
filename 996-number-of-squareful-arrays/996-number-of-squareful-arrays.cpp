class Solution {
    unordered_map<int, int> counter;
    unordered_map<int, vector<int>> ref;
    int backTracking(int n, int pick) {
        if(!pick) return 1;
        int res = 0;
        for(auto r : ref[n]) {
            if(counter[r]) {
                counter[r]--;
                res += backTracking(r, pick - 1);
                counter[r]++;
            }
        }
        return res;
    }
public:
    int numSquarefulPerms(vector<int>& nums) {
        for(auto n : nums) counter[n]++;
        for(auto [i, _] : counter) {
            for(auto [j, _]: counter) {
                int sum = i + j, sq = sqrt(i + j);
                if(sum == sq * sq) {
                    ref[i].push_back(j);
                }
            }
        }
        int res = 0;
        for(auto [n, _]: counter) {
            counter[n]--;
            res += backTracking(n, nums.size() - 1);
            counter[n]++;
        }
        
        return res;
    }
};