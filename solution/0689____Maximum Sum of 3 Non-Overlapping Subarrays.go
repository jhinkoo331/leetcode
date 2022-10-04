package main

// [83%, 41%]; hard; one pass
func maxSumOfThreeSubarrays(nums []int, k int) []int {
	subArraySum := make([]int, len(nums)-k+1, len(nums)-k+1)
	sum := 0
	for i := 0; i < k; i += 1 {
		sum += nums[i]
	}
	subArraySum[0] = sum
	for left, right := 0, k; right < len(nums); left, right = left+1, right+1 {
		sum += nums[right]
		sum -= nums[left]
		subArraySum[left+1] = sum
	}

	rightMaxSubArray := make([]struct {
		val   int
		index int
	}, len(subArraySum), len(subArraySum))
	rightMaxSubArray[len(rightMaxSubArray)-1] = struct {
		val   int
		index int
	}{val: subArraySum[len(rightMaxSubArray)-1], index: len(rightMaxSubArray) - 1}
	for i := len(rightMaxSubArray) - 2; i >= 0; i -= 1 {
		if subArraySum[i] >= rightMaxSubArray[i+1].val {
			rightMaxSubArray[i] = struct {
				val   int
				index int
			}{val: subArraySum[i], index: i}
		} else {
			rightMaxSubArray[i] = rightMaxSubArray[i+1]
		}
	}

	rightTwoMaxSubArray := make([]struct {
		val                  int
		thirdArrayBeginIndex int
	}, len(rightMaxSubArray)-k, len(rightMaxSubArray)-k)
	for i := 0; i < len(rightTwoMaxSubArray); i += 1 {
		rightTwoMaxSubArray[i] = struct {
			val                  int
			thirdArrayBeginIndex int
		}{
			val:                  subArraySum[i] + rightMaxSubArray[i+k].val,
			thirdArrayBeginIndex: rightMaxSubArray[i+k].index,
		}
	}

	twoMaxSubArray := make([]struct {
		sum                     int
		secondIndex, thirdIndex int
	}, len(rightTwoMaxSubArray), len(rightTwoMaxSubArray))
	twoMaxSubArray[len(twoMaxSubArray)-1] = struct {
		sum                     int
		secondIndex, thirdIndex int
	}{
		sum:         rightTwoMaxSubArray[len(twoMaxSubArray)-1].val,
		secondIndex: len(twoMaxSubArray) - 1,
		thirdIndex:  rightTwoMaxSubArray[len(twoMaxSubArray)-1].thirdArrayBeginIndex,
	}
	for i := len(twoMaxSubArray) - 2; i >= 0; i -= 1 {
		if rightTwoMaxSubArray[i].val >= twoMaxSubArray[i+1].sum {
			twoMaxSubArray[i] = struct {
				sum                     int
				secondIndex, thirdIndex int
			}{sum: rightTwoMaxSubArray[i].val, secondIndex: i, thirdIndex: rightTwoMaxSubArray[i].thirdArrayBeginIndex}
		} else {
			twoMaxSubArray[i] = twoMaxSubArray[i+1]
		}
	}

	curMaxSum := 0
	var i1, i2, i3 int
	for i := 0; i < len(twoMaxSubArray)-k; i += 1 {
		if temp := subArraySum[i] + twoMaxSubArray[i+k].sum; temp > curMaxSum {
			curMaxSum = temp
			i1, i2, i3 = i, twoMaxSubArray[i+k].secondIndex, twoMaxSubArray[i+k].thirdIndex
		}
	}
	//fmt.Printf("%v\n", subArraySum)
	//fmt.Printf("%v\n", rightMaxSubArray)
	//fmt.Printf("%v\n", rightTwoMaxSubArray)
	//fmt.Printf("%v\n", twoMaxSubArray)
	return []int{i1, i2, i3}
}
