class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        long long sum = accumulate(begin(nums), end(nums), 0ll);
        long long avg = sum / (long long)nums.size();
        avg = max(avg, 0ll);
        long long look = avg + 1;
        sort(begin(nums), end(nums));
        nums.erase(unique(begin(nums), end(nums)), end(nums));
        for(auto& n : nums) {
            if(n <= avg) continue;
            if(n == look) look++;
            else return look;
        }
        return look;
    }
};