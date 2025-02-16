package main

func sumOfGoodNumbers(nums []int, k int) int {
    res := 0
    n := len(nums)
    for i := 0; i < n; i++ {
        ok := true
        if i - k >= 0 && nums[i] <= nums[i-k] {
            ok = false
        }
        if i + k < n && nums[i] <= nums[i+k] {
            ok = false
        }
        if ok {
            res += nums[i]
        }
    }
    return res
}