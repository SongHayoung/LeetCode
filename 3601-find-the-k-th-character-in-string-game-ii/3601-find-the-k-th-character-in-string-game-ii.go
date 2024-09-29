package main

func helper(op []int, pos int64, k *int64) int {
	len := int64(1) << pos
	if len >= *k {
		return 0
	}
	res := helper(op, pos+1, k)
	if len < *k {
		*k -= len
		res = (res + op[pos]) % 26
	}
	return res
}

func kthCharacter(k int64, operations []int) byte {
	return byte('a' + helper(operations, 0, &k))
}