package main

// perf: 96, 100
func _1400(s string, k int) bool {
	if len(s) < k { // there must be empty string, return err
		return false
	}
	// check how many times every single character has appeared
	var count [128]int
	for _, char := range s {
		count[char]++
	}
	oddCount := 0
	for _, c := range count {
		if c&1 != 0 {
			oddCount++
		}
	}
	if k < oddCount {
		return false
	}
	return true
}

func canConstruct(s string, k int) bool {
	return _1400(s, k)
}

func main() {
	canConstruct("annabelle", 2)
}
