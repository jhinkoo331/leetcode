package main

// The worst of the journey is still to come

// perf: 8ms, 5.8%
func singleNumber(nums []int) (ans []int) {
	var xor int
	for _, num := range nums {
		xor = num ^ xor
	}
	// get the last different bit
	mask := xor ^ (-xor)
	var nums1, nums2 []int
	for _, num := range nums {
		if num&mask == 0 {
			nums1 = append(nums1, num)
		} else {
			nums2 = append(nums2, num)
		}
	}

	var temp int
	for _, num := range nums1 {
		temp = temp ^ num
	}
	ans = append(ans, temp)

	temp = 0
	for _, num := range nums2 {
		temp = temp ^ num
	}
	ans = append(ans, temp)
	return ans
}

func main() {
	singleNumber([]int{
		//2, 1, 2, 3, 4, 1,
		1, 2, 1, 3, 2, 5,
	})
}
