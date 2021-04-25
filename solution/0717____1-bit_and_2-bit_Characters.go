package main

func isOneBitCharacter(bits []int) bool {
	return s717(bits)
}

// perf: 4ms, 100
func s717(bits []int) bool {
	index := make(map[int]bool)
	index[0] = true
	for len(index) != 0 {
		for i := range index {
			delete(index, i)
			if i == len(bits)-1 {
				continue
			} else if i == len(bits)-2 && bits[i] == 1 {
				return false
			} else if bits[i] == 0 {
				index[i+1] = true
			} else if bits[i] == 1 {
				index[i+2] = true
			}
		}
	}
	return true
}
