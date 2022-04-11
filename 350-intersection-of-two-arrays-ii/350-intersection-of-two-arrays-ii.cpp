class Solution {
public:
    vector<int> intersect(vector<int>& n1, vector<int>& n2) {
        sort(n1.begin(), n1.end());
        sort(n2.begin(), n2.end());
        vector<int> res;
        for(int i = 0, j = 0; i < n1.size() and j < n2.size();) {
            if(n1[i] == n2[j]) {
                res.push_back(n1[i]);
                i++; j++;
            } else if(n1[i] > n2[j]) {
                j++;
            } else {
                i++;
            }
        }
        return res;
    }
};