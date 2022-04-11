class Solution {
    struct Bug{
        int pos;
        bool isBackward;
    };
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if(x == 0)
            return 0;

        bool isVisited[6001][2] = {false, };
        isVisited[0][0] = isVisited[0][1] = true;

        for(int num : forbidden) {
            isVisited[num][0] = isVisited[num][1] = true;
        }

        queue<Bug> q;

        q.push({0, false});

        for(int jump = 0; !q.empty(); jump++) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                Bug bug = q.front();
                q.pop();
                if(!bug.isBackward && bug.pos >= b && !isVisited[bug.pos - b][1]) {
                    isVisited[bug.pos - b][1] = true;
                    if(bug.pos - b == x)
                        return jump + 1;
                    q.push({bug.pos - b, true});
                }

                if(bug.pos + a <= 6000 && !isVisited[bug.pos + a][0]) {
                    isVisited[bug.pos + a][0] = true;
                    if(bug.pos + a == x)
                        return jump + 1;
                    q.push({bug.pos + a, false});
                }
            }
        }

        return -1;
    }
};
