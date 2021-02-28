class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(begin(nums1), end(nums1), 0), sum2 = accumulate(begin(nums2), end(nums2), 0);
        int res = 0, diff = abs(sum1 - sum2);
        if(!diff)
            return res;

        list<int> l;
        l.insert(end(l), begin(nums1), end(nums1));
        auto it = prev(end(l));
        l.insert(end(l), begin(nums2), end(nums2));
        transform(begin(l), next(it), begin(l), [sum1, sum2](int num) { return sum1 > sum2 ? num - 1 : 6 - num; });
        transform(next(it), end(l), next(it), [sum1, sum2](int num) { return sum1 > sum2 ? 6 - num : num - 1; });
        l.sort(greater<int>());
        for(auto& num : l) {
            res++;
            diff -= num;
            if(diff <= 0)
                return res;
        }
        return -1;
    }
};
