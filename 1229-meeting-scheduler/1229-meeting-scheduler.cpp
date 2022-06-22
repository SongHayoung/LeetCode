class Solution {
    vector<int> intersection(vector<int>& t1, vector<int>& t2) {
        int start = max(t1[0], t2[0]);
        int end = min(t1[1], t2[1]);
        return {start, end};
    }
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(),slots1.end());
        sort(slots2.begin(),slots2.end());
        for(int i = 0, j = 0; i < slots1.size() and j < slots2.size();) {
            vector<int> intersect = intersection(slots1[i], slots2[j]);
            if(intersect[1] - intersect[0] >= duration) {
                return {intersect[0], intersect[0] + duration};
            }
            
            if(slots1[i][0] < slots2[j][0] and slots1[i][1] < slots2[j][1]) i++;
            else if(slots1[i][0] > slots2[j][0] and slots1[i][1] > slots2[j][1]) j++;
            else if(slots1[i][0] < slots2[j][0] and slots2[i][1] < slots1[i][1]) j++;
            else i++;
        }
        return {};
    }
};