class Solution {
private:
    long long gcd(int p, int q) {
        if(q == 0) {
            return p;
        }
        return gcd(q, p % q);
    }

    long long lcm(long long p, long long q) {
        return p * q / gcd(p, q);
    }

    template<typename T>
    void removeMultiplies(set<T> &sets) {
        vector<T> vec(sets.begin(), sets.end());

        for(int i = 0; i < vec.size(); i++) {
            for(int j = i + 1; j < vec.size(); j++) {
                if(!(max(vec[i], vec[j]) % min(vec[i], vec[j])))
                    sets.erase(max(vec[i], vec[j]));
            }
        }
    }
    
    long sequence(long long m, set<int> nums, set<long long> lcms) {
        long ret = 0;
        for(int num : nums) {
            ret += m / num;
        }

        for(long lcm : lcms) {
            ret -= m / lcm;
        }

        return ret;
    }
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        priority_queue<pair<long long, long long>> pq;
        long long l = 0, r = n * min(a, min(b,c)), m;
        set<int> nums{a,b,c};
        removeMultiplies(nums);
        set<long long> lcms;
        for(auto it = nums.begin(); it != nums.end(); it++) {
            for(auto it2 = std::next(it, 1); it2 != nums.end(); it2++) {
                lcms.insert(lcm(max(*it, *it2), min(*it, *it2)));
            }
        }

        removeMultiplies(lcms);


        while(l + 1 < r) {
            m = (l + r)>>1;
            if(sequence(m, nums, lcms) >= n)
                r = m;
            else
                l = m;
        }

        while(sequence(l, nums, lcms) != n)
            l++;
        return l;
    }
};