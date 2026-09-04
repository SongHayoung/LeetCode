class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        map<int,int> at;
        for(int i = capacity.size() - 1; i >= 0; i--) {
            if(capacity[i] >= itemSize) at[capacity[i]] = i;
        }
        if(at.size() == 0) return -1;
        return begin(at)->second;
    }
};