package main

func intersect(nums1 []int, nums2 []int) []int {
	return t350(nums1, nums2)
}

func t350(nums1 []int, nums2 []int) (ans []int) {
	m := make(map[int]int)
	for _, num := range nums2 {
		m[num]++
	}
	for _, num := range nums1 {
		val, ok := m[num]
		if ok && val > 0 {
			m[num]--
			ans = append(ans, num)
		}
	}
	return ans
}

func main() {

}
