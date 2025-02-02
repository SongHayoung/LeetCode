package main

func findValidPair(s string) string {
    freq := make([]int, 10)

    for _, ch := range s {
        freq[ch-'0']++
    }

    for i := 0; i < len(s)-1; i++ {
        if freq[s[i]-'0'] == int(s[i]-'0') && freq[s[i+1]-'0'] == int(s[i+1]-'0') && s[i] != s[i+1] {
            return string([]byte{s[i], s[i+1]})
        }
    }

    return ""
}