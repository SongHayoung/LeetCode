class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;
        for(auto& s : arr) freq[s]++;
        for(auto& s : arr) {
            if(freq[s] == 1) {
                if(--k == 0) return s;
            }
        }
        return "";
    }
};