class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(begin(arr), end(arr));
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 0 and i + 1 < arr.size() and arr[i + 1] == 0) return true;
            else if(arr[i] != 0) {
                auto it = lower_bound(begin(arr), end(arr), arr[i] * 2);
                if(it != end(arr) and *it == arr[i] * 2) return true;
            }
        }
        return false;
    }
};