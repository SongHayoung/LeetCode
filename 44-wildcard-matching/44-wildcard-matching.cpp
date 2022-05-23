class Solution {
  vector<vector<int>> dp;
    bool helper(string& f, string& p, int i, int j) {
	if(i > f.length() or j > p.length()) return false;
	if(i == f.length() and j == p.length()) return true;
	if(j == p.length()) return false;
	if(i == f.length()) {
		for(; j < p.length(); j++) {
			if(p[j] != '*') return false;
		}
		return true;
	}
	if(dp[i][j] != -1) return dp[i][j];
	if(p[j] == '?') return dp[i][j] = helper(f, p, i + 1, j + 1);
	else if(p[j] != '*') {
		if(p[j] == f[i]) return dp[i][j] = helper(f, p, i + 1, j + 1);
		return dp[i][j] = false;
	}
	
	for(int pos = i; pos <= f.length(); pos++) {
		if(helper(f,p, pos, j + 1))
			return dp[i][j] = true;
	}
	
	return dp[i][j] = false;
}

public:
    bool isMatch(string s, string p) {
        string newP = "";
        for(auto& ch : p) {
            if(ch == '*') {
                if(newP.empty() or newP.back() != '*') newP.push_back(ch);
            } else newP.push_back(ch);
        }
        int n = s.length(), m = newP.length();
	dp = vector<vector<int>>(n, vector<int>(m, -1));
        return helper(s, newP, 0, 0);
    }
};