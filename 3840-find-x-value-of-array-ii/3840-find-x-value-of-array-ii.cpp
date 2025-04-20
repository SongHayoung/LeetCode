class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size(), sq = sqrt(n);
        vector<vector<int>> buc(n / sq + 1, vector<int>(k));
        vector<int> p(n / sq + 1);
        auto update = [&](int idx) {
            buc[idx] = vector<int>(k), p[idx] = 1;
            for(int i = idx * sq; i < (idx + 1) * sq and i < n; i++) {
                p[idx] = nums[i] % k * p[idx] % k;;
                buc[idx][p[idx]]++;
            }
        };
        auto query = [&](int pos, int x) {
            long long prod = 1, res = 0;
            while(pos < n and pos % sq) {
                prod = prod * nums[pos++] % k;
                res += prod == x;
            }
            for(int i = pos / sq; pos < n and i < buc.size(); i++) {
                for(int j = 0; j < k; j++) if(prod * j % k == x) res += buc[i][j];
                prod = prod * p[i] % k;
            }
            return res;
        };
        for(int i = 0; i < buc.size(); i++) update(i);
        vector<int> res;
        for(auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], x = q[3];
            nums[idx] = val;
            update(idx / sq);
            res.push_back(query(start,x));
        }
        return res;
    }
};