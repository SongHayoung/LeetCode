/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        set<int> celebrities;
        for(int i = 0; i < n; i++)
            celebrities.insert(i);

        for(int i = 0; i < n; i++) {
            for(auto& celebrity : celebrities) {
                if(!knows(i, celebrity) || (celebrity != i && knows(celebrity, i)))
                    celebrities.erase(celebrity);
            }
        }
        return celebrities.empty() ? -1 : *begin(celebrities);
    }
};