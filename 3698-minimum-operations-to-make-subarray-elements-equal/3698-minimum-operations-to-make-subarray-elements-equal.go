package main

import (
	"math"
	"sort"
)

type Seg struct {
	mi, ma, sum, cnt int
	left, right      *Seg
}

func NewSeg(A []int, l, r int) *Seg {
	seg := &Seg{mi: A[l], ma: A[r], sum: 0, cnt: 0}
	if l != r {
		m := (l + r) / 2
		seg.left = NewSeg(A, l, m)
		seg.right = NewSeg(A, m+1, r)
	}
	return seg
}

func (seg *Seg) query(l, r int) (int, int) {
	if l <= seg.mi && seg.ma <= r {
		return seg.sum, seg.cnt
	}
	if l > seg.ma || r < seg.mi {
		return 0, 0
	}
	lsum, lcnt := seg.left.query(l, r)
	rsum, rcnt := seg.right.query(l, r)
	return lsum + rsum, lcnt + rcnt
}

func (seg *Seg) update(x, op int) {
	if seg.mi <= x && x <= seg.ma {
		seg.sum += x * op
		seg.cnt += op
		if seg.left != nil {
			seg.left.update(x, op)
		}
		if seg.right != nil {
			seg.right.update(x, op)
		}
	}
}

func (seg *Seg) find(k int) int {
    if seg.mi == seg.ma {
        return seg.mi
    }
    if seg.left.cnt >= k {
        return seg.left.find(k)
    }
    return seg.right.find(k - seg.left.cnt)
}


func minOperations(nums []int, k int) int64 {
	S := append([]int{}, nums...)
	sort.Ints(S)
	S = unique(S)
	seg := NewSeg(S, 0, len(S)-1)
	res := int64(math.MaxInt64)

	for i := 0; i < len(nums); i++ {
		seg.update(nums[i], 1)
		if i+1 >= k {
			if i >= k {
				seg.update(nums[i-k], -1)
			}
            m := seg.find((k + 1) / 2)
			lsum, lcnt := seg.query(math.MinInt, m-1)
			rsum, rcnt := seg.query(m+1, math.MaxInt)
			res = min(res, int64(lcnt)*int64(m)-int64(lsum)+int64(rsum)-int64(rcnt)*int64(m))
		}
	}
	return res
}

func unique(arr []int) []int {
	m := make(map[int]bool)
	res := []int{}
	for _, v := range arr {
		if !m[v] {
			res = append(res, v)
			m[v] = true
		}
	}
	return res
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}