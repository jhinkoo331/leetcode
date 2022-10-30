package main

// perf: 95%, 63%
func maxRotateFunction(A []int) int {
	sum := 0 // sum of all element in the array A
	for _, val := range A {
		sum += val
	}

	maxVal := 0
	preVal := 0
	for index, val := range A { // the value of F(0)
		preVal += index * val
	}
	maxVal = preVal

	for _, val := range A {
		//newAns := ans - (sum - val) + val * (len(A) - 1)
		newVal := preVal - sum + val*len(A) // this line may raise overflow error of int32
		if newVal > maxVal {
			maxVal = newVal
		}
		preVal = newVal
	}
	return maxVal
}

func main() {
	arr := []int{4, 3, 2, 6}
	maxRotateFunction(arr)
}
