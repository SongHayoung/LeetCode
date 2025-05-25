func minCuttingCost(n, m, k int) int64 {
	query := func(n, k int64) int64 {
		if n <= k {
			return 0
		}
		return k * (n - k)
	}
	kn := int64(k)
	return query(int64(n), kn) + query(int64(m), kn)
}