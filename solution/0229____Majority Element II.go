package main

import "math/rand"

func majorityElement(nums []int) []int {
	return _0229(nums)
}

// perf: 89, 60
// note: this method is partly inspired by TomKing
func _0229(nums []int) []int {
	var m, n int
	var m_cnt, n_cnt int
	for _, num := range nums {
		if m_cnt != 0 && m == num {
			m_cnt++
		} else if n_cnt != 0 && n == num {
			n_cnt++
		} else if m_cnt == 0 {
			m = num
			m_cnt = 1
		} else if n_cnt == 0 {
			n = num
			n_cnt = 1
		} else {
			m_cnt--
			n_cnt--
		}
	}
	var threshold int = len(nums) / 3
	m_cnt = 0
	n_cnt = 0
	for _, num := range nums {
		if num == m {
			m_cnt++
		} else if num == n {
			n_cnt++
		}
	}
	// make(slice, length, cap)
	ans := make([]int, 0, 2)
	if m_cnt > threshold {
		ans = append(ans, m)
	}
	if n_cnt > threshold {
		ans = append(ans, n)
	}
	return ans
}

// len(nums) == 3k, 2*(k+1) > 2k - 1
// len(nums) == 3k+1, 2*(k+1) > 2k
// len(nums) == 3k+2, 2*(k+1) == 2k + 1
// this method is wrong..
func __0229(nums []int) []int {
	ans := make([]int, 0, 2)
	var n, n_cnt int
	for _, num := range nums {
		if n_cnt == 0 {
			n = num
			n_cnt = 2
		} else if num == n {
			n_cnt += 2
		} else {
			n_cnt -= 1
		}
	}
	n_cnt = 0
	for _, num := range nums {
		if num == n {
			n_cnt++
		}
	}
	if n_cnt > len(nums)/3 {
		ans = append(ans, n)
	} else { // there is no majority element
		return ans
	}
	// find the second element
	n_cnt = 0
	for i := len(nums) - 1; i >= 0; i-- {
		num := nums[i]
		if n_cnt == 0 {
			n = num
			n_cnt = 2
		} else if num == n {
			n_cnt += 2
		} else {
			n_cnt -= 1
		}
	}
	if n_cnt != 0 {

	}
	return nil
}

// todo: with binary sort..
// step1: find the mid
func _0229_3(nums []int) []int {
	rand.Seed(1997)
	var left, right int = 0, len(nums) - 1
	var mid int = -1
	third := len(nums) / 3
	second := third * 2
	for true {
		// rand.Intn return a random integer in range [0, n)
		temp := left + rand.Intn(right-left+1)
		nums[left], nums[temp] = nums[temp], nums[left]
		temp = nums[left]
		for right > left && nums[right] >= temp {
			right--
		}
		nums[left] = nums[right]
		for left < right && nums[left] <= temp {
			left++
		}
		nums[right] = nums[left]
		nums[left] = temp
	}
}

func main() {

}
