int fenwick[101010];

void update(int n) {
    while(n < 101010) {
        fenwick[n] += 1;
        n += n & -n;
    }
}

int query(int n) {
    int res = 0;
    while(n) {
        res += fenwick[n];
        n -= n & - n;
    }
    return res;
}

class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        vector<int> ok(nums.size(), true);
        memset(fenwick, 0, sizeof fenwick);
        for(int i = 0; i < nums.size(); i++) {
            int now = query(nums[i] - 1);
            if(now < k) ok[i] = false;
            update(nums[i]);
        }
        memset(fenwick, 0, sizeof fenwick);
        for(int i = nums.size() - 1; i >= 0; i--) {
            int now = query(nums[i] - 1);
            if(now < k) ok[i] = false;
            update(nums[i]);
        }
        return count(begin(ok), end(ok), true);
    }
};