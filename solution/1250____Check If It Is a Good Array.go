package main

// be happy, be confident.

// 对结果影响最大的操作, 优化了这一步操作后, 才AC了
func gcd(i, ii int) int {
	for i%ii != 0 {
		i, ii = ii, i%ii
	}
	return ii
}

// 88%, 88%
func isGoodArray(nums []int) bool {
	for _, num := range nums {
		if nums[0] = gcd(nums[0], num); nums[0] == 1 {
			return true
		}
	}
	return false
}
