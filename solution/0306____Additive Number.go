package main

func isAdditiveNumber(num string) bool {
        nums := make([]int, 0, len(num))
        for _, c := range num {
                nums = append(nums, int(c - '0'))
        }
        if nums == nil {
                return false    // todo: test
        }
        stack := make([]struct{digit, value int}, 0)
        stack = append(stack, struct{digit, value int}{1, nums[0]})
        i := 1
        for len(stack) != 0 {
                ok, add_digit := check(nums[1:], stack[0].digit, stack[0].value)
                if ok {
                        if add_digit {
                                stack = append(stack)
                        } else {

                        }
                } else {

                }
        }
}

func check(nums []int, digit int, prev int) (ok, add_digit bool) {
        // pow[i] = 10**i
        pow := []int {1, 10, 100, 1000, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9}
        biggest := []int {9, 99, 999, 1e4-1, 1e5-1, 1e6-1, 1e7-1, 1e8-1, 1e9-1}
        if prev == biggest[digit] {
                digit++
                add_digit = true
        }
        if len(nums) < digit {
                return false, add_digit
        }
        value := 0
        for i := 0; i < digit; i++ {
                value += nums[i] * pow[digit-i-1]
        }
        return value == prev + 1, add_digit
}

func main() {
	
}
