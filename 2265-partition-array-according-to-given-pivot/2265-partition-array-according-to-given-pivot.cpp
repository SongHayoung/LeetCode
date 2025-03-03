class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, greater;
        int pi = 0;
        for(auto& n : nums) {
            if(n < pivot) less.push_back(n);
            else if(n == pivot) pi++;
            else greater.push_back(n);
        }
        while(pi--) less.push_back(pivot);
        less.insert(less.end(), greater.begin(), greater.end());
        return less;
    }
};