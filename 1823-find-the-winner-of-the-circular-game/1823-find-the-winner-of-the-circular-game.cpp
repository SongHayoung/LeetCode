class Solution {
public:
    int findTheWinner(int n, int k) {
        list<int> l;
        for(int i = 1; i <= n; i++) {
            l.push_back(i);
        }
        
        list<int>::iterator it = l.begin();
        while(l.size() != 1) {
            for(int i = 1; i < k; i++) {
                it = next(it);
                if(it == l.end())
                    it = l.begin();
            }
            auto nt = next(it);
            l.erase(it);
            if(nt == l.end()) nt = l.begin();
            it = nt;
        }

        return l.front();
    }
};