package main

import (
	"fmt"
)

func countOfSubstrings(word string, k int) int64 {
	n := len(word)
	res := int64(0)
	vowels := map[byte]bool{'a': true, 'e': true, 'i': true, 'o': true, 'u': true}
	suf := make([]int, n+1)

	for i := n - 1; i >= 0; i-- {
		if i+1 < n && vowels[word[i+1]] {
			suf[i] = suf[i+1] + 1
		} else {
			suf[i] = 0
			if vowels[word[i]] {
				suf[i] = 1
			}
		}
	}

	freq := make(map[byte]int)
	for i, j, cnt := 0, 0, 0; i < n; i++ {
		for j < n && (len(freq) != 5 || cnt < k) {
			if vowels[word[j]] {
				freq[word[j]]++
			} else {
				cnt++
			}
			j++
		}
		if len(freq) == 5 && cnt == k {
			res += int64(max(1, suf[j-1]))
		}
		if vowels[word[i]] {
			freq[word[i]]--
			if freq[word[i]] == 0 {
				delete(freq, word[i])
			}
		} else {
			cnt--
		}
	}

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
