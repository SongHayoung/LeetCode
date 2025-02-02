package main


func helper(A, B [2]int, k int) int {
	mia := min(A[0], k)
	A[0] -= mia
	k -= mia
	B[1] += mia

	mib := min(B[0], k)
	B[0] -= mib
	k -= mib
	A[1] += mib

	return A[1] - A[0] + B[1] - B[0]
}

func helper2(ns, ew [2]int, k int) int {
	if ns[0] > ns[1] {
		ns[0], ns[1] = ns[1], ns[0]
	}
	if ew[0] > ew[1] {
		ew[0], ew[1] = ew[1], ew[0]
	}
	return max(helper(ns, ew, k), helper(ew, ns, k))
}

func maxDistance(s string, k int) int {
	ns := [2]int{0, 0}
	ew := [2]int{0, 0}
	res := 0

	for _, ch := range s {
		if ch == 'N' {
			ns[0]++
		}
		if ch == 'S' {
			ns[1]++
		}
		if ch == 'E' {
			ew[0]++
		}
		if ch == 'W' {
			ew[1]++
		}
		res = max(res, helper2(ns, ew, k))
	}

	return res
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