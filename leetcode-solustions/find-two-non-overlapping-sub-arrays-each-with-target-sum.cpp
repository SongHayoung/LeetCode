class Solution {
    bool isMatch(const pair<int, int>& p1, const pair<int, int>& p2) {
        if(p1.first < p2.first) {
            return p1.second < p2.first;
        } else {
            return p2.second < p1.first;
        }
    }
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int start = 0, end = 0, sum = arr[0], sz = arr.size() - 1;
        map<int, list<pair<int, int>>> subArray;
        while(end != sz || sum >= target) {
            if(sum < target && end != sz) {
                sum += arr[++end];
            } else if(sum > target && start != sz) {
                if(start != end)
                    sum -= arr[start++];
                else
                    sum += arr[++end] - arr[start++];
            } else if(sum == target){
                subArray[end - start + 1].push_back({start, end});
                if(end != sz)
                    sum += arr[++end];
                else
                    break;
            } else
                break;
        }

        int res = INT_MAX;
        for(auto arrayA = begin(subArray); arrayA != subArray.end() && arrayA->first * 2 < res; arrayA++) {
            for(auto pairA = begin(arrayA->second); pairA != arrayA->second.end() && arrayA->first * 2 < res; pairA++) {
                for(auto arrayB = arrayA; arrayB != subArray.end() && arrayB->first + arrayA->first < res; arrayB++) {
                    for(auto pairB = arrayA->first == arrayB->first ? next(pairA) : begin(arrayB->second); pairB != arrayB->second.end() && arrayB->first + arrayA->first < res; pairB++) {
                        if(isMatch(*pairA, *pairB)) {
                            res = min(res, arrayA->first + arrayB->first);
                        }
                    }
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};
