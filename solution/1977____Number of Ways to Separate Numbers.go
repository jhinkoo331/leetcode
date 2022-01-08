package main

// be happy, be confident.

func numberOfCombinations(num string) int {
	return oo1977(num)
}

type pair struct {
	num   int
	count int
}

// overflow
func o1977(num string) int {
	nums := make([]int, len(num), len(num))
	for i := range num {
		nums[i] = int(num[i] - '0')
	}
	info := make([][]pair, len(nums), len(nums))

	for i := len(nums) - 1; i >= 0; i -= 1 {
		if nums[i] == 0 {
			continue
		}
		cur_num := 0
		for ii := i; ii < len(nums); ii += 1 {
			cur_num = cur_num*10 + nums[ii]
			if ii+1 < len(nums) && nums[ii+1] == 0 {
				continue
			}
			if ii == len(nums)-1 {
				info[i] = append(info[i], pair{cur_num, 1})
				break
			}
			for iii := len(info[ii+1]) - 1; iii >= 0; iii -= 1 {
				if info[ii+1][iii].num >= cur_num {
					info[i] = append(info[i], pair{cur_num, info[ii+1][iii].count})
				} else {
					break
				}
			}
		}
	}

	sum := 0
	for _, temp := range info[0] {
		sum = (sum + temp.count) % (1e9 + 7)
	}
	return sum
}

// tle
func oo1977(num string) int {
	// info[i][ii] = k: for number consists of num[i]_num[i+1]..._num[ii], there are k combination of num[ii+1:]
	if len(num) == 0 {
		return 0
	}
	info := make([][]int, len(num))
	for i := range info {
		info[i] = make([]int, len(num)+1)
	}
	for left := len(num) - 1; left >= 0; left -= 1 {
		if num[left] == '0' {
			continue
		}
		for right := left + 1; ; right += 1 {
			if right == len(num) {
				info[left][right] = 1
				break
			}
			if num[right] == '0' {
				continue
			}
			if left+right-left+right-left > len(num) {
				continue
			}
			left_bigger_right := false
			for t, tt := left, right; t < right; t, tt = t+1, tt+1 {
				if num[t] > num[tt] {
					left_bigger_right = true
					break
				} else if num[t] < num[tt] {
					break
				}
			}
			if left_bigger_right == false {
				info[left][right] = info[right][left+right-left+right-left]
			}
			for temp := left + right - left + right - left + 1; temp <= len(num); temp += 1 {
				info[left][right] = (info[left][right] + info[right][temp]) % (1e9 + 7)
			}
		}
	}
	sum := 0
	for _, v := range info[0] {
		sum += v
	}
	return sum
}

func main() {
	numberOfCombinations("24896")
}
