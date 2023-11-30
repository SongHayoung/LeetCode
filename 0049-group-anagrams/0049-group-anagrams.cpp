class Solution {
	string keyOf(string& str) {
		vector<int> frequency(26);
		for(auto& ch : str) frequency[ch-'a'] += 1;
		string key = "";
		for(int i = 0; i < 26; i++) key += to_string(frequency[i]) + "#";
		return key;
	}
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
	    unordered_map<string, vector<string>> hashTable;
	    for(auto& str : strs) {
		    string hashKey = keyOf(str);
		    hashTable[hashKey].push_back(str);
	    }        
	    vector<vector<string>> res;
	    for(auto& [_,values] : hashTable) res.push_back(values);
	    return res;
    }
};