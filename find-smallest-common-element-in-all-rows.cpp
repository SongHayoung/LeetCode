class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        set<int> commonElement(mat[0].begin(), mat[0].end());
        
        for(int i = 1; i < mat.size(); i++) {
            unordered_set<int> removeElement;
            auto element = commonElement.begin();
            for(int j = 0; j < mat[i].size() && element != commonElement.end(); j++) {
                if(*element < mat[i][j]) {
                    while(element != commonElement.end() && *element < mat[i][j]) {
                        removeElement.insert(*element);
                        element = next(element);
                    }
                }
                if(element != commonElement.end() && *element == mat[i][j]) {
                    element = next(element);
                }
            }
            for(auto& remove : removeElement) {
                commonElement.erase(remove);
            }
        }

        return commonElement.empty() ? -1 : *commonElement.begin();
    }
};
