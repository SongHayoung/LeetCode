class Solution {
    vector<int> _origin;
public:
    Solution(vector<int>& nums) {
        _origin = vector<int>(nums.begin(), nums.end());
    }

    vector<int> reset() {
        return _origin;
    }

    vector<int> shuffle() {
        vector<int> _shuffle(_origin.begin(), _origin.end());
        for(int i = 0; i < _shuffle.size(); i++) {
            swap(_shuffle[rand() % _shuffle.size()], _shuffle[i]);
        }
        return _shuffle;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */