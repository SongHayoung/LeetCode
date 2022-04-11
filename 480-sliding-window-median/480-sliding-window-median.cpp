class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<double> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(),(k/2));
        vector<double> res {(*mid + *prev(mid ,!(k & 1))) / 2};
        for(int i = k; i < nums.size(); i++) {
            window.insert(nums[i]);
            if(nums[i] < *mid)
                mid--;
            
            if(nums[i-k] <= *mid)
                mid++;
            window.erase(window.find(nums[i-k]));
            
            res.push_back((*mid + *prev(mid ,!(k & 1))) / 2);
        }
        return res;
    }
};