package main

func helper(freq map[int]int, at int) int {
	res := 0
	for k, v := range freq {
		if at == 2 {
			if k%2 == 1 {
				continue
			}
			freq[k]--
			res += helper(freq, at-1)
			freq[k]++
		}
		if at == 1 {
			if v == 0 {
				continue
			}
			freq[k]--
			res += helper(freq, at-1)
			freq[k]++
		}
		if at == 0 {
			if v == 0 || k == 0 {
				continue
			}
			res++
		}
	}
	return res
}

func totalNumbers(digits []int) int {
	freq := make(map[int]int)
	for _, d := range digits {
		freq[d]++
	}
	return helper(freq, 2)
}
