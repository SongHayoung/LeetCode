func buttonWithLongestTime(events [][]int) int {
    res := []int{0, 0}
    p := 0
    for _, e := range events {
        btn, t := e[0], e[1]
        d := t - p
        p = t
        if d > res[0] || (d == res[0] && -btn > res[1]) {
            res = []int{d, -btn}
        }
    }
    return -res[1]
}