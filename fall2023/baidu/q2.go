package baidu

import "fmt"

// be happy, be confident.

func sln2(nums []int, k int) (ans [][2]int) {
	for i := range nums {
		nums[i] += k
	}
	var odd, even []int
	for _, n := range nums {
		if n%2 == 0 {
			even = append(even, n)
		} else {
			odd = append(odd, n)
		}
	}
	for len(odd) != 0 && len(even) != 0 {
		ans = append(ans, [2]int{odd[0], even[0]})
		odd = odd[1:]
		even = even[1:]
	}
	for len(even) >= 2 {
		ans = append(ans, [2]int{even[0], even[1]})
		even = even[2:]
	}
	return
}

func main2() {
	var numsCount, k int
	fmt.Scan(&numsCount, &k)
	nums := make([]int, numsCount, numsCount)
	for i := range nums {
		fmt.Scan(&nums[i])
	}
	ans := sln2(nums, k)
	fmt.Println(len(ans))
	for _, pair := range ans {
		fmt.Printf("%d %d\n", pair[0]-k, pair[1]-k)
	}
}
