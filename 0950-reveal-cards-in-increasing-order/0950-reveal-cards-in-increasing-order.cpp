class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        int n = deck.size();
        for(int i = 0; i < n; i++) q.push(i);
        sort(rbegin(deck), rend(deck));
        vector<int> res(n);
        while(!q.empty()) {
            auto i = q.front(); q.pop();
            res[i] = deck.back(); deck.pop_back();
            if(!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return res;
    }
};