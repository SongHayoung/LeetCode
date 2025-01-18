package main

import "math"

func maxAdjacentDistance(nums []int) int {
    res := 0
    n := len(nums)
    for i := 0; i < n; i++ {
        res = max(res, int(math.Abs(float64(nums[i]-nums[(i+1)%n]))))
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}