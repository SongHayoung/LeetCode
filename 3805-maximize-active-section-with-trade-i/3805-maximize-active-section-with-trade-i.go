package main

func maxActiveSectionsAfterTrade(s string) int {
	var cnt []int
	one := 0

	for i := 0; i < len(s); i++ {
		if s[i] == '1' {
			one++
		} else {
			if i == 0 || s[i-1] == '1' {
				cnt = append(cnt, 1)
			} else {
				cnt[len(cnt)-1]++
			}
		}
	}

	if len(cnt) <= 1 {
		return one
	}

	best := 0
	for i := 0; i < len(cnt)-1; i++ {
		best = max(best, cnt[i]+cnt[i+1])
	}

	return best + one
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
