class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for(auto& a : arr) {
            freq[((a % k) + k) % k]++;
        }
        for(auto& [remainder, count] : freq) {
            if(remainder == 0) {
                if(count & 1) return false;
            } else if(remainder * 2 == k) {
                if(count & 1) return false;
            } else {
                if(freq[k - remainder] != count) return false;
            }
        }
        return true;
    }
};