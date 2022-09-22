package main

// be happy, be confident.

func diffWaysToCompute(expression string) []int {
	nums, ops := getToken0241(expression)
	ans := getAns0241_withDuplicate(nums, ops)
	return ans
}

const (
	Add0241 uint8 = '+'
	Sub0241 uint8 = '-'
	Mul0241 uint8 = '*'
	Div0241 uint8 = '/'
)

// perf: 0ms, 99%
func getAns0241_withDuplicate(nums []int, ops []uint8) (ans []int) {
	grid := make([][][]int, len(nums), len(nums))
	for i := range grid {
		grid[i] = make([][]int, len(nums), len(nums))
	}
	for i := range nums {
		grid[i][i] = append(grid[i][i], nums[i])
	}
	for interval := 2; interval <= len(nums); interval += 1 {
		for left, right := 0, interval-1; right < len(nums); left, right = left+1, right+1 {
			for rightLeft := left + 1; rightLeft <= right; rightLeft += 1 {
				for _, leftResult := range grid[left][rightLeft-1] {
					for _, rightResult := range grid[rightLeft][right] {
						var ans int
						switch ops[rightLeft-1] {
						case Add0241:
							ans = leftResult + rightResult
						case Sub0241:
							ans = leftResult - rightResult
						case Mul0241:
							ans = leftResult * rightResult
						case Div0241:
							ans = leftResult / rightResult
						default:
							panic("invalid op")
						}
						grid[left][right] = append(grid[left][right], ans)
					}
				}
			}
		}
	}
	return grid[0][len(nums)-1]
}

// extract numbers and operators from the expression
func getToken0241(exp string) (nums []int, ops []uint8) {
	if len(exp) == 0 {
		return
	}
	firstNumIsNegative := exp[0] == Sub0241
	if firstNumIsNegative {
		exp = exp[1:]
	}
	for curIndex := 0; curIndex < len(exp); {
		curNum := 0
		for curIndex < len(exp) && (_0241IsOp(exp[curIndex]) == false) {
			curNum = curNum*10 + int(exp[curIndex]-'0')
			curIndex += 1
		}
		nums = append(nums, curNum)
		if curIndex < len(exp) {
			ops = append(ops, exp[curIndex])
			curIndex += 1
		}
	}
	if firstNumIsNegative {
		nums[0] = -nums[0]
	}
	return nums, ops
}

// error: duplicated result should not be removed.
func getAns0241(nums []int, ops []uint8) (ans []int) {
	grid := make([][]map[int]bool, len(nums), len(nums))
	for i := range grid {
		grid[i] = make([]map[int]bool, len(nums), len(nums))
		for ii := range grid[i] {
			grid[i][ii] = make(map[int]bool)
		}
	}
	for i := range nums {
		grid[i][i][nums[i]] = true
	}
	for interval := 2; interval <= len(nums); interval += 1 {
		for left, right := 0, interval-1; right < len(nums); left, right = left+1, right+1 {
			for rightLeft := left + 1; rightLeft <= right; rightLeft += 1 {
				for leftResult := range grid[left][rightLeft-1] {
					for rightResult := range grid[rightLeft][right] {
						var ans int
						switch ops[rightLeft-1] {
						case Add0241:
							ans = leftResult + rightResult
						case Sub0241:
							ans = leftResult - rightResult
						case Mul0241:
							ans = leftResult * rightResult
						case Div0241:
							ans = leftResult / rightResult
						default:
							panic("invalid op")
						}
						grid[left][right][ans] = true
					}
				}
			}
		}
	}
	for num := range grid[0][len(nums)-1] {
		ans = append(ans, num)
	}
	return ans
}

// return true if the letter is operator
func _0241IsOp(c uint8) bool {
	return c == Add0241 || c == Sub0241 || c == Mul0241 || c == Div0241
}
