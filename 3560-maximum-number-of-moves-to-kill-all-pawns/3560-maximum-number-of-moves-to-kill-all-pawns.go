package main

import (
	"fmt"
	"math"
	"container/list"
)

var cost [][]int
var dp [][]int

func dist(A []int) [][]int {
	dy := []int{-1, -2, -2, -1, 1, 2, 2, 1}
	dx := []int{-2, -1, 1, 2, 2, 1, -1, -2}
	dist := make([][]int, 50)
	for i := range dist {
		dist[i] = make([]int, 50)
		for j := range dist[i] {
			dist[i][j] = math.MaxInt32
		}
	}
	q := list.New()

	push := func(y, x, c int) {
		if dist[y][x] > c {
			dist[y][x] = c
			q.PushBack([]int{y, x})
		}
	}

	push(A[0], A[1], 0)

	for q.Len() > 0 {
		front := q.Front()
		q.Remove(front)
		y, x := front.Value.([]int)[0], front.Value.([]int)[1]

		for i := 0; i < 8; i++ {
			ny, nx := y+dy[i], x+dx[i]
			if 0 <= ny && ny < 50 && 0 <= nx && nx < 50 {
				push(ny, nx, dist[y][x]+1)
			}
		}
	}

	return dist
}

func helper(mask, x int) int {
	if dp[mask][x] != -1 {
		return dp[mask][x]
	}

	mi := math.MaxInt32
	ma := math.MinInt32
	pc := popCount(mask)

	for i := 0; i < len(cost); i++ {
		if (mask>>i)&1 != 0 {
			continue
		}
		now := cost[x][i] + helper(mask|(1<<i), i)
		mi = min(mi, now)
		ma = max(ma, now)
	}

	if pc&1 == 1 {
		dp[mask][x] = mi
	} else {
		dp[mask][x] = ma
	}

	return dp[mask][x]
}

func maxMoves(kx, ky int, positions [][]int) int {
	n := len(positions)
	dp = make([][]int, 1<<n)
	for i := range dp {
		dp[i] = make([]int, n)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}
	cost = make([][]int, n)
	for i := range cost {
		cost[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		d := dist(positions[i])
		for j := i + 1; j < n; j++ {
			cost[i][j] = d[positions[j][0]][positions[j][1]]
			cost[j][i] = cost[i][j]
		}
	}

	for i := 0; i < n; i++ {
		dp[(1<<n)-1][i] = 0
	}

	res := math.MinInt32
	k := []int{kx, ky}
	d := dist(k)
	for i := 0; i < n; i++ {
		res = max(res, d[positions[i][0]][positions[i][1]]+helper(1<<i, i))
	}

	return res
}

func popCount(x int) int {
	count := 0
	for x > 0 {
		count++
		x &= x - 1
	}
	return count
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
