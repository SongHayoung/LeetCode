package main

import "sort"

func maxSum(nums []int) int {
	ma := maxElement(nums)
	if ma <= 0 {
		return ma
	}

	us := make(map[int]bool)
	res := 0

	for _, n := range nums {
		if n > 0 && !us[n] {
			res += n
			us[n] = true
		}
	}

	return res
}

func maxElement(arr []int) int {
	if len(arr) == 0 {
		return 0
	}
	sort.Ints(arr)
	return arr[len(arr)-1]
}