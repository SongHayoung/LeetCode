package main

import (
    "sort"
    "strconv"
    "strings"
)

func countMentions(numberOfUsers int, events [][]string) []int {
    res := make([]int, numberOfUsers)
    us := make(map[int]struct{})
    for i := 0; i < numberOfUsers; i++ {
        us[i] = struct{}{}
    }

    var q []struct {
        time, id int
    }

    sort.Slice(events, func(i, j int) bool {
        t1, _ := strconv.ParseInt(events[i][1], 10, 64)
        t2, _ := strconv.ParseInt(events[j][1], 10, 64)
        if t1 == t2 {
            return events[i][0] > events[j][0]
        }
        return t1 < t2
    })

    for _, e := range events {
        time, _ := strconv.ParseInt(e[1], 10, 64)

        for len(q) > 0 && q[0].time <= int(time) {
            id := q[0].id
            q = q[1:]
            us[id] = struct{}{}
        }

        if e[0] == "MESSAGE" {
            if e[2] == "ALL" {
                for i := 0; i < numberOfUsers; i++ {
                    res[i]++
                }
            } else if e[2] == "HERE" {
                for id := range us {
                    res[id]++
                }
            } else {
                ids := getIds(e[2])
                for _, id := range ids {
                    res[id]++
                }
            }
        } else {
            id, _ := strconv.Atoi(e[2])
            delete(us, id)
            q = append(q, struct {
                time, id int
            }{
                time: int(time) + 60,
                id:   id,
            })
        }
    }

    return res
}

func getIds(s string) []int {
    var res []int
    val := 0
    s += " "
    for i := 0; i < len(s); i++ {
        if s[i] == ' ' {
            res = append(res, val)
            val = 0
        } else if '0' <= s[i] && s[i] <= '9' {
            val = val*10 + int(s[i]-'0')
        }
    }
    return res
}
