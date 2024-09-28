package main

import "math"

func helper(x int) int {
	res := 0
	for x > 0 {
		res += x % 10
		x /= 10
	}
	return res
}

func minElement(nums []int) int {
	res := math.MaxInt64
	for _, n := range nums {
		res = min(res, helper(n))
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}