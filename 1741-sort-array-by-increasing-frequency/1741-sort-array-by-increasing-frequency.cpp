class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto& n : nums) freq[n]++;
        sort(begin(nums), end(nums), [&](int i, int j) {
            if(freq[i] != freq[j]) return freq[i] < freq[j];
            return i > j;
        });
        return nums;
    }
};