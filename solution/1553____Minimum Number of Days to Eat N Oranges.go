package main

import "fmt"

func minDays(n int) int {
        return o1553(n)
}

// for n = 6128305, time limit exceeded error..
func o1553(n int) int {
        visited := make([]bool, n + 1)
        visited[0] = true
        step := 0
        pre := make(map[int]bool)
        pre[0] = true
        for {
                next := make(map[int]bool)
                step++
                for num := range pre {
                        temp := num + 1
                        if temp <= n && visited[temp] == false {
                                next[temp] = true
                                visited[temp] = true
                        }
                        temp = num*2
                        if temp <= n && visited[temp] == false {
                                next[temp] = true
                                visited[temp] = true
                        }
                        temp = num*3
                        if temp <= n && visited[temp] == false {
                                next[temp] = true
                                visited[temp] = true
                        }
                        if visited[n] == true {
                                return step
                        }
                }
                pre = make(map[int]bool)
                for key := range next {
                        pre[key] = true
                }
        }
}



func main() {
        fmt.Println(minDays(6128305))
}
