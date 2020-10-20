package main

// perf: 100, 16
// todo: where comes the memory consumption?
func _0763(S string) []int {
	var ans []int
	var lastOccurIndex [128]int
	for index, char := range S {
		lastOccurIndex[char] = index
	}
	for left := 0; left < len(S); {
		right := lastOccurIndex[S[left]]
		for temp := left; temp <= right; temp++ {
			if right < lastOccurIndex[S[temp]] {
				right = lastOccurIndex[S[temp]]
			}
		}
		ans = append(ans, right-left+1)
		left = right + 1
	}
	return ans
}

func partitionLabels(S string) []int {
	return _0763(S)
}

func main() {

}
