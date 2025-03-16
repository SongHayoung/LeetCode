package main

import (
	"math"
	"sort"
)

func query(A []int, pos, n int) int {
	if len(A) == 1 {
		return -1
	}

	it := sort.Search(len(A), func(i int) bool { return A[i] >= pos })
	res := math.MaxInt
    
    fmt.Println(it)
	if it != 0 {
		res = min(res, pos-A[it-1])
	} else {
		res = min(res, n-A[len(A)-1]+pos)
	}
	if it != len(A) - 1 {
		res = min(res, A[it+1]-pos)
	} else {
		res = min(res, n-pos+A[0])
	}

	return res
}

func solveQueries(nums []int, queries []int) []int {
	at := make(map[int][]int)
	for i, num := range nums {
		at[num] = append(at[num], i)
	}

	res := make([]int, len(queries))
	for i, q := range queries {
		res[i] = query(at[nums[q]], q, len(nums))
	}

	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}