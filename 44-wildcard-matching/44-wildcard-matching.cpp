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

bool globMatching(string fileName, string pattern) {
	string newPattern = "";
	
	for(auto& ch : pattern) {
		if(ch == '*') {
			if(newPattern.empty() or newPattern.back() != '*')
				newPattern.push_back(ch);
		} else newPattern.push_back(ch);
	}

	int n = fileName.length(), m = newPattern.length();
	dp = vector<vector<int>>(n, vector<int>(m, -1));
  return helper(fileName, newPattern, 0, 0);
}
public:
    bool isMatch(string s, string p) {
        return globMatching(s, p);
    }
};