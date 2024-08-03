class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(begin(target), end(target));
        sort(begin(arr), end(arr));
        return arr == target;
    }
};