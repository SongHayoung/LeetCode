package main

func isBalanced(num string) bool {
	sum := 0
	sign := 1
	for i := 0; i < len(num); i++ {
		sum += int(num[i]-'0') * sign
		sign = -sign
	}
	return sum == 0
}