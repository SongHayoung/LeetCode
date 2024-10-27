class Solution {
    vector<int> prime{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    vector<long long> parse(int x) {
        vector<long long> res(10);
        for(int i = 0; i < 10 and x > 1 ;i++) {
            while(x % prime[i] == 0) {
                x /= prime[i];
                res[i]++;
            }
        }
        return res;
    }
public:
    long long maxScore(vector<int>& nums) {
        if(nums.size() == 1) return nums[0] * nums[0];
        vector<vector<long long>> mi(10,{INT_MAX,INT_MAX}), ma(10,{0,0});
        for(int i = 0; i < nums.size(); i++) {
            vector<long long> now = parse(nums[i]);
            for(int j = 0; j < 10; j++) {
                mi[j].push_back(now[j]);
                ma[j].push_back(now[j]);
                sort(begin(mi[j]), end(mi[j])); mi[j].pop_back();
                sort(rbegin(ma[j]), rend(ma[j])); ma[j].pop_back();
            }
        }
        long long res = 1;
        for(int i = 0; i < 10; i++) res *= pow(prime[i], mi[i][0] + ma[i][0]);
        for(int i = 0; i < nums.size(); i++) {
            vector<long long> now = parse(nums[i]);
            long long g = 1, l = 1;
            for(int j = 0; j < 10; j++) {
                int fl1 = now[j] == mi[j][0];
                int fl2 = now[j] == ma[j][0];
                g *= pow(prime[j], mi[j][fl1]);
                l *= pow(prime[j], ma[j][fl2]);
            }
            res = max(res, g * l);
        }
        return res;
    }
};