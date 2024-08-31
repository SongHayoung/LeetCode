func generateKey(num1, num2, num3 int) int {
	res := 0
	po := 1

	for num1 != 0 || num2 != 0 || num3 != 0 {
		digit1 := num1 % 10
		digit2 := num2 % 10
		digit3 := num3 % 10

		minDigit := min(digit1, digit2, digit3)

		res += po * minDigit
		num1 /= 10
		num2 /= 10
		num3 /= 10
		po *= 10
	}

	return res
}