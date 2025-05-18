func smallestIndex(nums []int) int {
	sumDigits := func(x int) int {
		s := 0
		for x > 0 {
			s += x % 10
			x /= 10
		}
		return s
	}
	for i, v := range nums {
		if sumDigits(v) == i {
			return i
		}
	}
	return -1
}