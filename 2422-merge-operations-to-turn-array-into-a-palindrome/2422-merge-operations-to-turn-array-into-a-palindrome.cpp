class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        deque<long long> A;
        for(auto n : nums) A.push_back(n);
        int res = 0;
        while(A.size() > 1) {
            long long l = A.front(), r = A.back();
            if(l == r) {
                A.pop_front();
                A.pop_back();
            } else if(l < r) {
                A.pop_front();
                A.front() += l;
                res += 1;
            } else if(l > r) {
                A.pop_back();
                A.back() += r;
                res += 1;
            }
        }
        return res;
    }
};