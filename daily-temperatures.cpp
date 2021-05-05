class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n, 0);
        map<int, int> m;
        for(int i = n - 1; i >= 0; i--) {
            auto it = m.upper_bound(T[i]);
            if(it != end(m)) res[i] = it->second - i;
            m[T[i]] = i;
            it = m.find(T[i]);
            do if(it != begin(m)){
                it = prev(it);
                it->second = i;
            }while(it != begin(m));
        }
        return res;
    }
};
