class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> psum1(10101, 0), psum2(10101, 0), psum3(10101,0);
        for(auto& n : nums) {
            psum1[n] += n;
            psum2[n] += n;
            psum3[n] += 1;
        }
        for(int i = 1; i < 10101; i++) {
            psum1[i] += psum1[i-1];
            psum3[i] += psum3[i-1];
        }
        for(int i = 10098; i >= 0; i--) {
            psum2[i] += psum2[i+1];
        }
        vector<int> res;
        for(auto& n : nums) {
            long long l = psum1[n], lcnt = psum3[n];
            long long r = psum2[n+1], rcnt = nums.size() - lcnt;
            res.push_back(n * lcnt - l + r - n * rcnt);
        }
        return res;
    }
};