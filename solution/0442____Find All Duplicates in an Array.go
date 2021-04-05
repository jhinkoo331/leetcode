package main

func findDuplicates(nums []int) []int {
        return ff442(nums)
}

func f442(nums []int) (ans []int) {
        nums = append(nums, 0)
        for i := 0; i < len(nums) - 1; i++ {
                ii := i
                for nums[ii] != ii {
                        nums[ii], ii = ii, nums[ii]
                }
                if ii != i {
                        ans = append(ans, ii)
                }
        }
        return ans
}

func ff442(nums []int) (ans []int) {
        mask :=
        mask := (^(0) >> 1) + 1
        for i := range nums {
                val := nums[i]
                if val < 0 {
                        val ^= mask
                }
                if nums[val-1] < 0 {
                        ans = append(ans, val)
                } else {
                        nums[val-1] ^= mask
                }
        }
        return ans
}

func main() {
        arr := []int{4,3,2,7,8,2,3,1}
        findDuplicates(arr)
}
