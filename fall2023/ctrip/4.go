package main

import (
    "fmt"
)

// The worst of the journey is still to come

func four(nums []int, zero int) (ans int) {
    two, five := make([]int, len(nums), len(nums)), make([]int, len(nums), len(nums))
    for i, v := range nums {
        for ii := v; ii%2 == 0; ii /= 2 {
            two[i] += 1
        }
        for ii := v; ii%5 == 0; ii /= 5 {
            five[i] += 1
        }
    }
    for left := 0; left < len(nums); left += 1 {
        for right := left + 1; right < len(nums); right += 1 {
            twoSum := two[left] + two[right]
            fiveSum := five[left] + five[right]
            if twoSum < fiveSum {
                if twoSum >= zero {
                    ans += 1
                }
            } else {
                if fiveSum >= zero {
                    ans += 1
                }
            }
        }
    }
    return ans
}

func main() {
    var n, zero int
    fmt.Scanf("%d %d", &n, &zero)
    nums := make([]int, n, n)
    for i := range nums {
        fmt.Scanf("%d", &nums[i])
    }
    fmt.Printf("%d", four(nums, zero))
}

