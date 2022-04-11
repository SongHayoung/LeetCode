struct Num{
    Num(long long num, long long pos) : num(num), pos(pos) {}
    long long num;
    mutable int pos;
    bool operator<(const Num& other) const {
        return num < other.num;
    }

    bool operator==(const Num& other) const {
        return num == other.num;
    }
};
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> solution;
        set<Num> sets;
        if(nums.size() < 4)
            return solution;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            if(i != nums.size() - 1 && nums[i] == nums[i + 1]) continue;
            sets.insert(Num(nums[i], i));
        }

        long long p1, p2, p3, p4;
        for(p1 = 0; p1 <= nums.size() - 4 && 1ll * nums[p1] * 4 <= target; p1++) {
            if(p1 != 0 && nums[p1] == nums[p1 - 1]) continue;
            for(p2 = p1 + 1; p2 <= nums.size()-3; p2++){
                if(p2 != p1 + 1 && nums[p2] == nums[p2 - 1]) continue;
                for(p3 = p2 + 1; p3 <= nums.size()-2; p3++) {
                    if(p3 != p2 + 1 && nums[p3] == nums[p3 - 1]) continue;
                    auto it = sets.find(Num(1ll*target-(1ll*nums[p1] + 1ll*nums[p2] + 1ll*nums[p3]), -1));
                    if(it != sets.end() && it->pos > p3)
                        solution.push_back(vector<int>{nums[p1], nums[p2], nums[p3], target-(nums[p1] + nums[p2] + nums[p3])});
                }
            }
        }

        return solution;
    }
};