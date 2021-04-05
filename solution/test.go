package main

import (
        "math/rand"
)

func drop_tail(arr []int) {
        arr[0] = rand.Intn(20)
}

func main() {
        arr := []int {1,2,3}
        for len(arr) > 0 {
                drop_tail(arr)
        }
}
