func countSubarrays(nums []int) int {
    res := 0
    n := len(nums)
    for i := 0; i < n-2; i++ {
        if 2*nums[i]+2*nums[i+2] == nums[i+1] {
            res++
        }
    }
    return res
}