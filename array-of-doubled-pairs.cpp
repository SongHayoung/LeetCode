class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> m;
        int maxVal = 0;
        for(auto& num : arr) {
            m[num]++;
            maxVal = max(maxVal, abs(num));
        }
        maxVal = (maxVal + 1) >> 1;
        for(int i = 0; i <= maxVal; i++) {
            if(m.count(i) && m[i]) {
                if(m.count(i*2) && m[i*2] >= m[i]) {
                    m[i*2] -= m[i];
                    m.erase(i);
                    if(!m[i*2])
                        m.erase(i*2);
                } else {
                    return false;
                }
            }
            if(m.count(-i) && m[-i]) {
                if(m.count(-i*2) && m[-i*2] >= m[-i]) {
                    m[-i*2] -= m[-i];
                    m.erase(-i);
                    if(!m[-i*2])
                        m.erase(-i*2);
                } else {
                    return false;
                }
            }
        }
        return m.empty();
    }
};
