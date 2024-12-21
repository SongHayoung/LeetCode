long long mod = 1e9 + 7;
class Solution {
public:
    int subsequencesWithMiddleMode(vector<int>& nums) {
        unordered_map<long long, long long> left, right;
        unordered_map<long long, long long> leftDup, rightDup;
        long long res = 0, n = nums.size();
        long long lDupSum = 0, rDupSum = 0;
        auto add = [&](unordered_map<long long, long long>& dup, unordered_map<long long, long long>& freq, long long& sum, long long x) {
            dup[x] += freq[x];
            sum += freq[x];
            freq[x]++;
        };
        auto del = [&](unordered_map<long long, long long>& dup, unordered_map<long long, long long>& freq, long long& sum, long long x) {
            freq[x]--;
            dup[x] -= freq[x];
            sum -= freq[x];
            if(freq[x] == 0) freq.erase(x);
        };
        for(auto& n : nums) add(rightDup, right, rDupSum, n);
        for(int i = 0; i < n - 2; i ++) {
            long long x = nums[i];
            
            del(rightDup, right, rDupSum, x);

            if(i > 1) {
                // 2-0, 2-1, 2-2
                res += leftDup[x] * (n - i - 1) * (n - i - 2) / 2;
                // 0-2, 1-2, 2-2
                res += rightDup[x] * i * (i - 1) / 2;
                // 2-2
                res -= rightDup[x] * leftDup[x];

                long long leftSingle = left[x] * (i - left[x]);
                long long rightSingle = right[x] * (n - i - 1 - right[x]);
                
                // 1-1
                res += leftSingle * rightSingle;
                // 1-0
                if(leftSingle) {
                    for(auto& [k,v] : left) {
                        if(k == x) continue;
                        long long le = left[x] * v;
                        long long ri = (n - i - 1) * (n - i - 2) / 2 - rDupSum;
                        
                        if(right.count(x)) {
                            ri -= right[x] * (n - i - 1 - right[x]);
                        }
                        if(right.count(k)) {
                            ri -= right[k] * (n - i - 1 - right[k]);
                        }
                        if(right.count(x) and right.count(k)) {
                            ri += right[k] * right[x];
                        }
                        res += le * ri;
                    }
                }
                // 0-1
                if(rightSingle) {
                    for(auto& [k,v] : right) {
                        if(k == x) continue;
                        long long ri = right[x] * v;
                        long long le = i * (i - 1) / 2 - lDupSum;
                        if(left.count(x)) {
                            le -= left[x] * (i - left[x]);
                        }
                        if(left.count(k)) {
                            le -= left[k] * (i - left[k]);
                        }
                        if(left.count(x) and left.count(k)) {
                            le += left[k] * left[x];
                        }
                        res += le * ri;
                    }
                }
                
            }
            
            add(leftDup, left, lDupSum, x);
        }
        return (res % mod + mod) % mod;
        
    }
};