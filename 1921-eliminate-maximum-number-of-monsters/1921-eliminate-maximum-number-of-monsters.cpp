class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> t(dist.size());
        for(int i = 0; i < dist.size(); i++) {
            t[i] = 1.0 * dist[i] / speed[i];
        }
        sort(begin(t), end(t));
        for(int i = 1; i < dist.size(); i++) {
            if(t[i] <= i) return i;
        }
        return t.size();
    }
};