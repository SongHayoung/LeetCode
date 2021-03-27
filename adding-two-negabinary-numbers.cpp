class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        int add = 0, sz1 = arr1.size(), sz2 = arr2.size(), end = max(sz1,sz2);
        vector<int>& res = arr1.size() > arr2.size() ? arr1 : arr2;
        for(int i = 0 ; i < end; i++) {
            add *= -1;
            if(i < sz1) add += arr1[i];
            if(i < sz2) add += arr2[i];

            switch (add) {
                case 3: res[i] = 1; add = 1; break;
                case 2: res[i] = 0; add = 1; break;
                case 1: res[i] = 1; add = 0; break;
                case 0: res[i] = 0; add = 0; break;
                case -1: res[i] = 1; add = -1; break;
            }
        }
        if(add) {res.push_back(1); res.push_back(1);}
        while(!res.back() && res.size() >= 2)
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
