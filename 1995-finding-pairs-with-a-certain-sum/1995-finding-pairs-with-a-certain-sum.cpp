class FindSumPairs {
    unordered_map<int, long> n1;
    unordered_map<int, long> n2;
    vector<int> num2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : num2(nums2) {
        for(auto& n : nums1) n1[n]++;
        for(auto& n : nums2) n2[n]++;
    }

    void add(int index, int val) {
        n2[num2[index]]--;
        num2[index] += val;
        n2[num2[index]]++;
    }

    int count(int tot) {
        int res = 0;
        for(auto& n : n1) {
            res += n.second * n2[tot - n.first];
        }
        
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */