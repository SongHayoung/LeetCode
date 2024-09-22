
class Solution {
    long long findMaxX_formula(long long N) {
    if (N < 1) {
        // N이 1보다 작을 경우, 양의 정수 X는 존재하지 않습니다.
        return 0;
    }
    // 근의 공식을 이용하여 X 계산
    double x = (-1.0 + sqrt(1.0 + 8.0 * N)) / 2.0;
    // 내림하여 정수로 변환
    long long X = static_cast<long long>(floor(x));
    // X가 최소 1 이상인지 확인
    return (X >= 1) ? X : 1;
}

    bool helper(int mountainHeight, long long k, vector<int>& workerTimes) {
        for(auto& t : workerTimes) {
            mountainHeight -= findMaxX_formula(k / t);
            if(mountainHeight <= 0) return true;
        }
        return false;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        sort(begin(workerTimes), end(workerTimes));
        long long l = 0, r = 1e18, res = r;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = helper(mountainHeight, m, workerTimes);
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};