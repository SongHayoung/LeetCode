class Solution {
    int solution (vector<int>& arr, int l, int r) {
        if(l + 1 >= r) return 0;
        int m = l + (r-l)/2;
        if(arr[m-1] >= arr[m] or arr[m+1] >= arr[m])  //if m is vally or horizon
            return max(solution(arr, l, m), solution(arr,m,r));

        bool upperLeft = arr[m] < arr[m-1];  //top might be in left side

        while(l < m and m < r) { //move m to top of mountain
            if(upperLeft) {
                if(arr[m-1] > arr[m]) m--;
                else if(arr[m-1] == arr[m]) {
                    return max(solution(arr,l,m-1), solution(arr,l + (r-l)/2, r));
                } else break;
            } else {
                if(arr[m+1] > arr[m]) m++;
                else if(arr[m+1] == arr[m]) {
                    return max(solution(arr,l,l + (r-l)/2), solution(arr,m+1,r));
                } else break;
            }
        }

        if(m == l) return solution(arr, l + (r-l)/2, r); //if top is end of left just check right only
        if(m == r) return solution(arr,l, l + (r-l)/2);  //if top is end of right just check left only

        if(!(arr[m-1] < arr[m] and arr[m+1] < arr[m])) return 0; //if m is not top return 0

        int left = m, right = m;
        while(left > 0) {  //find left end and right end
            if(arr[left] > arr[left-1]) left--;
            else break;
        }
        while(right < arr.size()-1) {
            if(arr[right] > arr[right+1]) right++;
            else break;
        }

        //divide and conquer
        return max({right - left + 1, solution(arr, l, left), solution(arr, right, r)});
    }
public:
    int longestMountain(vector<int>& arr) {
        return solution(arr,0,arr.size()-1);
    }
};