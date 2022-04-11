class Solution {
    map<int, int> count;
    unordered_map<int, int> end;
public:
    bool isPossible(vector<int>& nums) {
        for(auto n : nums) count[n]++;
        for(auto n : nums) {
            if(!count[n]) continue;
            count[n]--;
            
            if(end[n-1] > 0) {
                end[n-1]--;
                end[n]++;
            }else if(count[n + 1] > 0 and count[n + 2] > 0) {
                count[n+1]--;
                count[n+2]--;
                end[n+2]++;
            } else return false;
        }
        return true;
    }
};