struct MS {
    int k, best;
    long long inSum, inLoSum, outHiSum;
    multiset<long long> inLo, inHi, outLo, outHi;
    MS(int k) : k(k), best(0), inSum(0), inLoSum(0), outHiSum(0) {}
    void inLoToHi() {
        auto it = prev(inLo.end());
        long long x = *it;
        auto nh = inLo.extract(it);
        inHi.insert(move(nh)), inLoSum -= x;
    }
    void inHiToLo() {
        auto it = inHi.begin();
        long long x = *it;
        auto nh = inHi.extract(it);
        inLo.insert(move(nh)), inLoSum += x;
    }
    void outLoToHi() {
        auto it = prev(outLo.end());
        long long x = *it;
        auto nh = outLo.extract(it);
        outHi.insert(move(nh)), outHiSum += x;
    }
    void outHiToLo() {
        auto it = outHi.begin();
        long long x = *it;
        auto nh = outHi.extract(it);
        outLo.insert(move(nh)), outHiSum -= x;
    }
    void normalize() {
        while(best and *outHi.begin() <= *prev(inLo.end())) inLoToHi(), outHiToLo(), best--;
        while(best < k and inHi.size() and outLo.size() and *prev(outLo.end()) > *inHi.begin()) inHiToLo(), outLoToHi(), best++;
    }
    void addIn(multiset<long long>::node_type nh) {
        long long x = nh.value();
        inSum += x;
        if(best and x < *prev(inLo.end())) {
            inLo.insert(move(nh));
            inLoSum += x;
            inLoToHi();
        } else inHi.insert(move(nh));
    }
    void addOut(multiset<long long>::node_type nh) {
        long long x = nh.value();
        if(best and x > *outHi.begin()) {
            outHi.insert(move(nh));
            outHiSum += x;
            outHiToLo();
        } else outLo.insert(move(nh));
    }
    void outToIn(long long x) {
        auto it = outHi.find(x);
        if(it != outHi.end()) {
            auto nh = outHi.extract(it);
            outHiSum -= x;
            if(outLo.size()) outLoToHi();
            else best--, inLoToHi();
            addIn(move(nh));
        } else {
            it = outLo.find(x);
            auto nh = outLo.extract(it);
            addIn(move(nh));
        }
        normalize();
    }
    void inToOut(long long x) {
        auto it = inLo.find(x);
        if(it != inLo.end()) {
            auto nh = inLo.extract(it);
            inLoSum -= x, inSum -= x;
            if(inHi.size()) inHiToLo();
            else best--, outHiToLo();
            addOut(move(nh));
        } else {
            it = inHi.find(x);
            auto nh = inHi.extract(it);
            inSum -= x;
            addOut(move(nh));
        }
        normalize();
    }
    long long value() {
        return inSum - inLoSum + outHiSum;
    }
};

class Solution {
public:
    long long maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        MS ms(k);
        for(auto& x : nums) ms.outLo.insert(x);
        long long res = LLONG_MIN;
        for(int l = 0; l < n; l++) {
            if(l % 2 == 0) {
                if(l) ms.inToOut(nums[l-1]);
                for(int r = l; r < n; r++) ms.outToIn(nums[r]), res = max(res,ms.value());
            } else {
                ms.inToOut(nums[l-1]);
                for(int r = n-1; r >= l; r--) {
                    res = max(res,ms.value());
                    if(r > l) ms.inToOut(nums[r]);
                }
            }
        }
        return res;
    }
};