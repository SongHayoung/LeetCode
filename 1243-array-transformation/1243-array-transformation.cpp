class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        while(1) {
            vector<int> now = arr;
            for(int i = 1; i < arr.size() - 1; i++) {
                if(arr[i-1] > arr[i] and arr[i] < arr[i+1]) now[i]++;
                else if(arr[i-1] < arr[i] and arr[i] > arr[i+1]) now[i]--;
            }
            
            if(now == arr) break;
            swap(arr,now);
        }
        return arr;
    }
};