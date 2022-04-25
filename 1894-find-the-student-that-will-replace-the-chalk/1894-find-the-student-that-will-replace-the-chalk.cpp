class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long long> psum(n, chalk[0]);
        for(int i = 1; i < n; i++) {
            psum[i] = psum[i-1] + chalk[i];
        }
        k %= psum.back();
        return upper_bound(begin(psum), end(psum), k) - begin(psum);
    }
};