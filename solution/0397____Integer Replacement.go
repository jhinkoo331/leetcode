package main

import "fmt"

func integerReplacement(n int) int {
        return 0
}

func main() {
        var arr [100]int
        arr[1] = 0
        for i := 2; i < len(arr); i++ {
                var target int
                target = i * 2
                if target < len(arr) {
                        if arr[target] == 0 {
                                arr[target] = arr[i] + 1
                        } else if arr[target] > arr[i] {
                                arr[target] = arr[i] + 1
                        }
                }
                target = i - 1
                if target > 1 {
                        if arr[target] == 0 {
                                arr[target] = arr[i] + 1
                        } else if arr[target] > arr[i] {
                                arr[target] = arr[i] + 1
                        }
                }
                target = i + 1
                if target < len(arr) {
                        if arr[target] == 0 {
                                arr[target] = arr[i] + 1
                        } else if arr[target] > arr[i] {
                                arr[target] = arr[i] + 1
                        }
                }
        }
        fmt.Println(arr)
}
