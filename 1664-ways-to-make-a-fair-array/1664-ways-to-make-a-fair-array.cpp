class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        vector<pair<int, int>> psum{{0,0}};
        for(int i = 0, odd = 0, even = 0; i < nums.size(); i++) {
            if(i & 1) odd += nums[i];
            else even += nums[i];
            psum.push_back({odd,even});
        }
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            auto [fo, fe] = psum[i];
            auto [no, ne] = psum[i + 1];
            auto [bo, be] = psum[nums.size()];
            auto ce = bo - no;
            auto co = be - ne;
            if(fo + co == fe + ce)
                res++;
        }
        return res;
    }
};