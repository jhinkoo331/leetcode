package main


func minSubarray(nums []int, p int) int {
        return _1590_1(nums, p)
}


func _1590_1(nums []int, p int) int {
        var sum = 0
        for _, num := range nums {
                sum += num
        }
        target := sum % p
        if target == 0 {
                // no element need to be removed
                return 0
        }
        latest_occour_index := make([]int, p)           // this line renders error
        var temp = -len(nums)
        for i := range latest_occour_index {
                latest_occour_index[i] = temp
        }
        latest_occour_index[0] = -1
        sum = 0
        ans := len(nums)
        for idx, num := range nums {
               sum += num
               num = sum % p
               latest_occour_index[num] = idx
               num -= target
               if num < 0 {
                       num += p
               }
               if idx - latest_occour_index[num] < ans {
                       ans = idx - latest_occour_index[num]
               }
        }
        if ans == len(nums) {
                // you have to remove all elements to make it divisible for p
                return -1
        } else {
                return ans
        }
}



func main() {
        arr := []int {3,1,4,2}
        minSubarray(arr, 6)
}
