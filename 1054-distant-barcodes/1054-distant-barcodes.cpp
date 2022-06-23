class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> freq;
        for(auto& b : barcodes) freq[b]++;
        priority_queue<pair<int ,int>> pq;
        for(auto& [k, v] : freq) pq.push({v, k});
        
        vector<int> res;
        while(!pq.empty()) {
            auto [tpv, tpk] = pq.top(); pq.pop();
            tpv--;
            res.push_back(tpk);
            if(!pq.empty()) {
                auto [tpv2, tpk2] = pq.top(); pq.pop();
                tpv2--;
                res.push_back(tpk2);
                if(tpv2) pq.push({tpv2, tpk2});
            }
            if(tpv) pq.push({tpv, tpk});
        }
        return res;
    }
};