package main

func countArrays(original []int, bounds [][]int) int {
	l, r := bounds[0][0], bounds[0][1]
	n := len(original)

	for i := 1; i < n && l <= r; i++ {
		l = max(l+original[i]-original[i-1], bounds[i][0])
		r = min(r+original[i]-original[i-1], bounds[i][1])
	}

	return max(0, r-l+1)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}