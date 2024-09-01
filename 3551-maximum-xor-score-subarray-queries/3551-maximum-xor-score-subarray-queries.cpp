const maxN = 1010

var dp [maxN][maxN]int
var dpp [maxN][maxN]int

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func helper(A []int, l, r int) int {
    if dp[l][r] != -1 {
        return dp[l][r]
    }
    if l == r {
        dp[l][r] = A[l]
        dpp[l][r] = A[l]
        return dp[l][r]
    }
    res := max(helper(A, l+1, r), helper(A, l, r-1))
    dp[l][r] = res
    dpp[l][r] = dpp[l+1][r] ^ dpp[l][r-1]
    dp[l][r] = max(res, dpp[l][r])
    return dp[l][r]
}

func maximumSubarrayXor(nums []int, queries [][]int) []int {
    for i := range dp {
        for j := range dp[i] {
            dp[i][j] = -1
            dpp[i][j] = -1
        }
    }

    var res []int
    for _, q := range queries {
        res = append(res, helper(nums, q[0], q[1]))
    }
    return res
}