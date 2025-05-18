import "sort"

func calc(n int) int {
	res := 0
	for n > 0 {
		res += n % 10
		n /= 10
	}
	return res
}

func minSwaps(nums []int) int {
	n := len(nums)
	sum := make([]int, n)
	for i, v := range nums {
		sum[i] = calc(v)
	}
	ord := make([]int, n)
	now := make([]int, n)
	gogo := make([]int, n)
	for i := 0; i < n; i++ {
		ord[i] = i
		now[i] = i
	}
	sort.Slice(ord, func(i, j int) bool {
		a, b := ord[i], ord[j]
		if sum[a] == sum[b] {
			return nums[a] < nums[b]
		}
		return sum[a] < sum[b]
	})
	for i := 0; i < n; i++ {
		gogo[ord[i]] = i
	}
	res := 0
	for i := 0; i < n; i++ {
		for now[i] != ord[i] {
			res++
			j := gogo[now[i]]
			now[i], now[j] = now[j], now[i]
		}
	}
	return res
}