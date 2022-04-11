class SparseVector {
    int intersectMultiply(map<int, int>& m2) {
        int res = 0;
        auto m1it = m.begin(), m2it = m2.begin();
        while(m1it != end(m) && m2it != end(m2)){
            if(m1it->first < m2it->first) ++m1it;
            else if(m2it->first < m1it->first) ++m2it;
            else {
                res += m1it->second * m2it->second;
                ++m1it, ++m2it;
            }
        }
        return res;
    }
public:
    map<int, int> m;
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(!nums[i]) continue;
            m[i] = nums[i];
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        return intersectMultiply(vec.m);
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
