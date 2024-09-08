func binary(x int) string {
	if x == 0 {
		return "0"
	}
	res := ""
	for x > 0 {
		res = strconv.Itoa(x%2) + res
		x /= 2
	}
	return res
}

func convertDateToBinary(date string) string {
	date += "-"
	res := ""
	val := 0

	for _, ch := range date {
		if ch >= '0' && ch <= '9' {
			val = val*10 + int(ch-'0')
		} else {
			res += binary(val) + "-"
			val = 0
		}
	}

	return strings.TrimSuffix(res, "-")
}