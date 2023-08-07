class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), l = 0, r = n - 1;
        while(l < r) {
	int m = l + (r-l)/2;
	if(matrix[m][0] == target) return true;
	else if(matrix[m][0] > target) r = m - 1;
    else if(matrix[m].back() < target) {
        l = m+1;
    }
	else if(l == m) break;
    else l = m;
	}
        auto it = lower_bound(matrix[l].begin(), matrix[l].end(), target);
	return it != matrix[l].end() and *it == target;
    }
};


