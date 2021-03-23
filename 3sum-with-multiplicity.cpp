class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long long res = 0, mod = 1e9 + 7;
        map<int, long long> m;
        for(auto num : arr) {
            m[num]++;
        }

        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());

        for(int i = 0; i < arr.size() && arr[i] * 3 <= target; i++) {
            for(int j = i; j < arr.size() && arr[i] + arr[j] * 2 <= target; j++) {
                if(m.count(target - arr[i] - arr[j])) {
                    if(target == arr[i] * 3) {
                        if(m[arr[i]] >= 3) {
                            res = res + m[arr[i]] * (m[arr[i]] - 1) * (m[arr[i]] - 2) / 6;
                        }
                    } else if(target == arr[i] + arr[j] * 2) {
                        if(m[arr[j]] >= 2) {
                            res = res + m[arr[i]] * m[arr[j]] * (m[arr[j]] - 1) / 2;
                        }
                    } else if(i == j){
                        if(m[arr[i]] >= 2) {
                            res = res + m[arr[i]] * (m[arr[i]] - 1) / 2 * m[target - arr[i] * 2];
                        }
                    } else {
                        res = res + m[arr[i]] * m[arr[j]] * m[target - arr[i] - arr[j]];
                    }
                    res %= mod;
                }
            }
        }
        return res;
    }
};
