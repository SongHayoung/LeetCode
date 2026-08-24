package main

import (
	"math"
	"sort"
)

type counter struct {
	mp   map[int]int
	odds int
}

func (c *counter) init() {
	if c.mp == nil {
		c.mp = make(map[int]int)
	}
}

func (c *counter) update(x int, op int) {
	c.init()
	c.mp[x] += op
	if c.mp[x]&1 == 1 {
		c.odds++
	} else {
		c.odds--
	}
	if c.mp[x] == 0 {
		delete(c.mp, x)
	}
}

func (c *counter) ok(k int) bool {
	if len(c.mp) != k {
		return false
	}
	return c.odds == 0
}

type q3 struct {
	l   int
	r   int
	idx int
}

func validSubarrays(nums []int, k int, queries [][]int) []bool {
	var c counter
	Q := make([]q3, 0)

	for i := 0; i < len(queries); i++ {
		l := queries[i][0]
		r := queries[i][1]
		length := r - l + 1
		if length&1 == 1 {
			continue
		}
		if length < 2*k {
			continue
		}
		Q = append(Q, q3{l: l, r: r, idx: i})
	}

	sq := int(math.Sqrt(float64(len(queries))))
	if sq == 0 {
		sq = 1
	}

	sort.Slice(Q, func(i, j int) bool {
		a := Q[i]
		b := Q[j]
		ab := a.l / sq
		bb := b.l / sq
		if ab == bb {
			return a.r < b.r
		}
		return ab < bb
	})

	res := make([]bool, len(queries))
	l, r := 0, 0

	for _, qu := range Q {
		le, ri, idx := qu.l, qu.r, qu.idx
		for r <= ri {
			c.update(nums[r], 1)
			r++
		}
		for l > le {
			l--
			c.update(nums[l], 1)
		}
		for r > ri+1 {
			r--
			c.update(nums[r], -1)
		}
		for l < le {
			c.update(nums[l], -1)
			l++
		}
		res[idx] = c.ok(k)
	}

	return res
}