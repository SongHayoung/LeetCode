class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	    unordered_map<int, int> hashTable;
	    for(int i = 0; i < nums.size(); i++) {
		    int x = target - nums[i];
		    if(hashTable.count(x)) {
			    return {i,hashTable[x]};
		    }
		    hashTable[nums[i]] = i;
	    }
        return {-1};
    }
};