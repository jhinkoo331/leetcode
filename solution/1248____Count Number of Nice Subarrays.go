package main

// be happy, be confident

func numberOfSubarrays(nums []int, k int) int {
	return o1248(nums, k)
}

// perf: 89%, 53%
func o1248(nums []int, k int) (ans int) {
	var oddNumsIndex []int
	oddNumsIndex = append(oddNumsIndex, -1)
	for index, num := range nums {
		if num%2 == 1 {
			oddNumsIndex = append(oddNumsIndex, index)
		}
	}
	oddNumsIndex = append(oddNumsIndex, len(nums))
	for left, right := 1, k; right < len(oddNumsIndex)-1; left, right = left+1, right+1 {
		ans += (oddNumsIndex[left] - oddNumsIndex[left-1]) * (oddNumsIndex[right+1] - oddNumsIndex[right])
	}
	return ans
}

func main() {
	o1248([]int{2, 2, 2, 1, 2, 2, 1, 2, 2, 2}, 2)
}
