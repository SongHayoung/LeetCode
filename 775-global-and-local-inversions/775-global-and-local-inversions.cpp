class Solution {
    int fenwick[101010];
    int query(int n) {
        int res = 0;
        while(n) {
            res += fenwick[n];
            n -= n & -n;
        }
        return res;
    }
    void update(int n) {
        while(n < 101010) {
            fenwick[n] += 1;
            n += n & -n;
        }
    }
public:
    bool isIdealPermutation(vector<int>& nums) {
        int g = 0, l = 0, n = nums.size();
        memset(fenwick, 0, sizeof fenwick);
        for(int i = 0; i < n; i++) {
            if(i + 1 != n) {
                if(nums[i] > nums[i + 1]) l++;
            }
            g += i - query(nums[i] + 1);
            if(g >= n) return false;
            update(nums[i] + 1);
        }
        return g == l;
    }
};