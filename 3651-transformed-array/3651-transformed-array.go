package main

func constructTransformedArray(nums []int) []int {
    n := len(nums)
    res := make([]int, 0, n)

    for i := 0; i < n; i++ {
        idx := (i + nums[i]%n + n) % n
        res = append(res, nums[idx])
    }

    return res
}