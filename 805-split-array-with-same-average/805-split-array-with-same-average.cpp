class Solution {
public:
    //SUM = S, Sum of array a = A, Sum of array b = B, size of nums = N
    //1. S = A + B
    //2. A/K == B/(N-K) (average)
    //
    // -> B = S - A
    // -> A/K = (S-A)/(N-K)
    // -> A * (N-K) = (S-A) * K
    // -> AN - AK = SK - AK
    // -> AN = SK
    // -> A = SK/N
    // and we know s, k, n so we just find A with combination of k element
    // and optimze to search [1 ... n / 2]
    // S = A + B witch means S = B + A
    bool splitArraySameAverage(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        
        vector<int> target(n + 1, -1);
        vector<unordered_set<int>> acc(n / 2 + 3);
        
        for(int k = 1; k < n; k++) {
            if(sum * k % n != 0) continue;
            target[k] = sum * k / n;
        }
        
        if(accumulate(target.begin(), target.end(), 0) == -n-1) //if no target return false
            return false;
        
        acc[0].insert(0);
        
        for(int i = 0; i < n; i++) {
            for(int c = min(i,n/2 + 1); c >= 0; c--) {
                for(auto comb : acc[c])
                    acc[c+1].insert(comb + nums[i]);
                if(acc[c+1].count(target[c+1]))
                    return true;
            }
        }
        
        return false;
    }
};