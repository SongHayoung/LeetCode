class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto& n : nums) freq[n]++;
        for(auto& n : nums) if(freq[n] == 1 and n % 2 == 0) return n;
        return -1;
    }
};