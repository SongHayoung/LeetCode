func reverseDegree(s string) int {
	res := 0
	for i := 0; i < len(s); i++ {
		res += (i + 1) * (26 - int(s[i]-'a'))
	}
	return res
}