class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize) return false;
        map<int, int> remain;
        for(auto h : hand) remain[h]++;
        
        while(!remain.empty()) {
            auto be = remain.begin();
            auto nxt = next(be);
            for(int i = 1; i < groupSize and be->second; i++,++nxt) {
                if(nxt == remain.end()) return false;
                if(nxt->first != be->first + i) return false;
                if(nxt->second < be->second) return false;
                nxt->second -= be->second;
            }
            remain.erase(be);
            
        }
        return true;
        
    }
};