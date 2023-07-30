class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(auto a : arr) freq[a] += 1;
        int res = 0;
        for(auto [k,v] : freq) {
            if(freq.count(k+1)) res += v;
        }
        return res;
    }
};