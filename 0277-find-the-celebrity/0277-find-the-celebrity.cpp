/* The knows API is defined for you.
      bool knows(int a, int b); */
class Solution {
public:
    int findCelebrity(int n) {
        int u = 0;
        bool ok = true;
        for(int v = u + 1; v < n; v++) {
            if(knows(u,v)) {
                // u -> v
                // u will not be celebrity
                // v can be celebrity
                u = v;
                ok = true;
            } else {
                // u don't know v and v also don't know u
                // u can not be celebrity
                // ok = false 
                if(!knows(v,u)) ok = false;
            }
        }
        if(!ok) return -1;
        
        for(int i = 0; i < u; i++) {
            if(knows(u,i)) return -1;
            if(!knows(i,u)) return -1;
        }
        return u;
    }
};