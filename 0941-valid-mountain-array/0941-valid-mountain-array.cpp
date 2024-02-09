class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 0;
        for(; i < arr.size() - 1 and arr[i] < arr[i+1]; i++) {}
        if(i == arr.size() - 1) return false; 
        if(i == 0) return false;
        for(; i < arr.size() - 1 and arr[i] > arr[i+1]; i++) {}
        return i == arr.size() - 1;
    }
};