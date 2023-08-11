/**
 * Definition for a category handler.
 * class CategoryHandler {
 * public:
 *     CategoryHandler(vector<int> categories);
 *     bool haveSameCategory(int a, int b);
 * };
 */
class Solution {
public:
    int numberOfCategories(int n, CategoryHandler* categoryHandler) {
        vector<bool> ok(n,true);
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(!ok[i]) continue;
            res += 1;
            for(int j = i+1; j < n; j++) {
                if(!ok[j]) continue;
                ok[j] = !categoryHandler->haveSameCategory(i,j);
            }
        }
        return res;
    }
};