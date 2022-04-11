class Solution {
private:
    void makeGraph(unordered_map<int, list<int>> &behinds, unordered_map<int, int> &countsOfFront, set<int> &nodes, vector<vector<int>> &seqs) {
        for(vector<int> vec : seqs) {
            for(int i = 0; i < vec.size(); i++) {
                nodes.insert(vec[i]);

                if(i) {
                    countsOfFront[vec[i]] += 1;
                    behinds[vec[i - 1]].push_back(vec[i]);
                }
            }
        }
    }

    queue<int> getFrontNodes(set<int> &nodes, unordered_map<int,int> countsOfFront) {
        queue<int> res;
        
        for(int node : nodes) {
            if(!countsOfFront[node]) {
                res.push(node);
                countsOfFront.erase(node);
            }
        }

        return res;
    }
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, list<int>> behinds;
        unordered_map<int, int> countsOfFront;
        set<int> nodes;

        makeGraph(behinds, countsOfFront, nodes, seqs);
        
        queue<int> q = getFrontNodes(nodes, countsOfFront);
        vector<int> res;

        while(!q.empty()) {
            if(q.size() > 1)
                return false;

            res.push_back(q.front());

            for(int num : behinds[q.front()]) {
                countsOfFront[num]--;

                if(!countsOfFront[num]) {
                    q.push(num);
                    countsOfFront.erase(num);
                }
            }

            q.pop();
        }

        return countsOfFront.empty() && res == org;
    }
};