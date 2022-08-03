class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        vector<long long> res;
        long long rdp = 0, edp = expressCost;
        for(int i = 0; i < regular.size(); i++) {
            long long rdpp = min(rdp, edp) + regular[i];
            long long edpp = min(rdp + expressCost, edp) + express[i];
            
            rdp = rdpp;
            edp = edpp;
            
            res.push_back(min(rdp, edp));
        }
        
        return res;
    }
};