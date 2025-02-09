package main

import (
	"sort"
)

func sortMatrix(grid [][]int) [][]int {
	n := len(grid)

	for x := 0; x < n; x++ {
		var r, c []int

		for i, j := x, 0; i < n && j < n; i, j = i+1, j+1 {
			r = append(r, grid[i][j])
		}
		for i, j := 0, x; i < n && j < n; i, j = i+1, j+1 {
			c = append(c, grid[i][j])
		}

		sort.Sort(sort.Reverse(sort.IntSlice(r)))
		sort.Ints(c)

		for i, j := 0, x; i < n && j < n; i, j = i+1, j+1 {
			grid[i][j] = c[i]
		}
		for i, j := x, 0; i < n && j < n; i, j = i+1, j+1 {
			grid[i][j] = r[j]
		}
	}

	return grid
}