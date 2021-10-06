package main

func minCut(s string) int {
	return o132(s)
}

// perf: 61, 27
// time: n**2
// space: n**2
func o132(s string) int {

	mat := make([][]bool, 0, len(s))
	for i := range s {
		mat = append(mat, make([]bool, len(s), len(s)))
		mat[i][i] = true
	}
	for i := 0; i < len(s)-1; i += 1 {
		if s[i] == s[i+1] {
			mat[i][i+1] = true
		}
	}

	// left + ssl = right
	// right < len(s) => left + ssl < len(s) => left < len(s) - ssl
	for ssl := 2; ssl < len(s); ssl += 1 {
		for left := 0; left < len(s)-ssl; left += 1 {
			if s[left] == s[left+ssl] && mat[left+1][left+ssl-1] {
				mat[left][left+ssl] = true
			}
		}
	}

	min_cut := make([]int, len(s), len(s))
	for right := 1; right < len(s); right += 1 {
		min_cut[right] = len(s)
		for left := 0; left <= right; left += 1 {
			if mat[left][right] {
				if left == 0 {
					min_cut[right] = 0
				} else if temp := min_cut[left-1] + 1; temp < min_cut[right] {
					min_cut[right] = temp
				}
			}
		}
	}
	return min_cut[len(min_cut)-1]
}

func main() {
	minCut("aab")
}
